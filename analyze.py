#!/usr/bin/env python
import os, sys
import json
import pandas as pd

if len(sys.argv) < 3:
	print "Usage: %s ERA DATASET RUNNUMBER" % sys.argv[0]
	sys.exit()

era = sys.argv[1]
datasetName = sys.argv[2]
runNumber = int(sys.argv[3])

certType = 'Collisions'
if 'Cosmic' in datasetName: certType = 'Cosmics'
eraType = era[-2:]

print "@@ Connecting to DQM @@"

## Open DQM root file
sys.argv.append("-b")
from ROOT import *

sys.path.append('scripts')
from browseDQM import *
dqmJSON = DQMJSON()
dqmJSON.loadRuns('/%s/%s.*' % (datasetName, era))
if runNumber not in dqmJSON.runs:
    print "!! Cannot find run %d in the list" % runNumber
    print " Recently available runs are: ",
    for i, x in enumerate(reversed(sorted(dqmJSON.runs.keys()))):
        if i > 25: break
        print x,
    sys.exit()
datasetFullName = dqmJSON.runs[runNumber]

def getInfo(subpath):
    return dqmJSON.getObjectInfo(runNumber, "RPC/"+subpath)

def getME(subpath):
    return dqmJSON.getObjectJSON(runNumber, "RPC/"+subpath)

def getDirs(subpath):
    return dqmJSON.listDir(runNumber, "RPC/"+subpath)

nEvent = int(getInfo("EventInfo/iEvent")['value'])
nRPCEvents = getInfo("AllHits/RPCEvents")['nentries']
nLS = int(getInfo("DCSInfo/rpcHV")['value'])
nFATAL = getInfo("FEDIntegrity/FEDFatal")['nentries']


# Cluster Size:
# Muon/Barrel/Wheel_{#}/sector_{#}/station_{#}/ClusterSize_*
#Wheen_{#} - -2, -1, 0, +1, +2
#sector_{#} - 1...12
#station_{#} - 1...4
#ClusterSize_* - W-2_RB2in_S04, etc.

# Occupancy:
# Muon/Barrel/Wheel_{#}/sector_{#}/station_{#}/Occupancy_*


## Chamber, Avg. Cluster, Occupancy
# chamberTest = getInfo("Muon/Barrel/Wheel_2/sector_4/station_4/ClusterSize_W+2_RB4++_S04")['stats']['x']['mean']

lumiSections = getInfo("DCSInfo/rpcHV")['value']
avgCluster = getInfo("Muon/Barrel/Wheel_2/sector_4/station_4/ClusterSize_W+2_RB4++_S04")['stats']['x']['mean']
occupancy = getInfo("Muon/Barrel/Wheel_2/sector_4/station_4/Occupancy_W+2_RB4++_S04")['nentries']

bxDist = getInfo("Muon/Barrel/Wheel_2/sector_4/station_4/BXDistribution_W+2_RB4++_S04")['stats']['x']['mean']
nOfClusters = getInfo("Muon/Barrel/Wheel_2/sector_4/station_4/NumberOfClusters_W+2_RB4++_S04")['stats']['x']['mean']
multiplicity = getInfo("Muon/Barrel/Wheel_2/sector_4/station_4/Multiplicity_W+2_RB4++_S04")['stats']['x']['mean']

print "\n"
#print open("cache/%d/elog.txt" % runNumber).read()

print("===========CHAMBER TEST============")
print "LumiSections: ",lumiSections
print "Avg. Cluster: ",avgCluster
print "Occupancy: ",occupancy
print "BXDistribution: ", bxDist
print "NumberOfClusters: ", nOfClusters
print "Multiplicity: ", multiplicity


print("===========FILES INFO==============")
filesList = getDirs("Muon/Barrel/Wheel_2/sector_4/station_4/")[1]
for file in filesList:
    if file.startswith('ClusterSize') or file.startswith('Occupancy'):
        print file

wheels = ["-2", "-1", "0", "1", "2"]
sectors = list(range(1,13))
stations = list(range(1,5))

print "Wheels: ",wheels
print "Sectors: ",sectors
print "Stations: ",stations

count_dirs = 0
count_clust = 0
count_occ = 0

def getWheelEff(wheel):

    wheelEff = getME("RPCEfficiency/Wheel_"+wheel+"/GlobEfficiencyWheel_"+wheel)
    effXaxis = wheelEff['xaxis']['labels']
    effYaxis = wheelEff['bins']['content'][:204]

    effChambers = []

    chambList = []

    damaged = []


    for ch in effXaxis:
        if ch['value'].endswith('Forward'):
            chambList.append(ch['value'][:-8])
        elif ch['value'].endswith('Backward'):
            chambList.append(ch['value'][:-9])
        elif ch['value'].endswith('Middle'):
            chambList.append(ch['value'][:-7])
        else:
            damaged.append(ch['value'])

    effDict = {}

    for i in range(len(chambList)):
        if chambList[i] not in effDict.keys():
            effList = []
            effList.append(effYaxis[i])
            effDict[chambList[i]] = effList
        else:
            effDict[chambList[i]].append(effYaxis[i])

    for key in effDict.keys():
        effDict[key] = sum(effDict[key])/len(effDict[key])

    return effDict

#for wheel in wheels:
#    print wheel
#    print len(getWheelEff(wheel))



data_structure = []

# loop iterating over all the chambers to collect avg. cluster and occupancy data
# for each of the chamber. Before storing data, occupancy is divided by lumisection
# of the run to normalize the variables between all the runs

# the table is stored in format of : [chamber, avg. cluster, occupancy, type]
# type - Collisions or Cosmics


for wheel in wheels:
    wheelEff = getWheelEff(wheel)
    print "Collecting wheel ", wheel, " data"
    for sector in sectors:
        for station in stations:
            count_dirs += 1

            filesList = getDirs("Muon/Barrel/Wheel_"+wheel+"/sector_"+str(sector)+"/station_"+str(station)+"/")[1]

            for file in filesList:

                if file.startswith('ClusterSize'):
                    strPathCluster = "Muon/Barrel/Wheel_"+wheel+"/sector_"+str(sector)+"/station_"+str(station)+"/"+file
                    strPathOcc = "Muon/Barrel/Wheel_"+wheel+"/sector_"+str(sector)+"/station_"+str(station)+"/Occupancy"+file[11:]
                    strPathBX = "Muon/Barrel/Wheel_"+wheel+"/sector_"+str(sector)+"/station_"+str(station)+"/BXDistribution"+file[11:]

                    strPathNofClusters = "Muon/Barrel/Wheel_"+wheel+"/sector_"+str(sector)+"/station_"+str(station)+"/NumberOfClusters"+file[11:]
                    strPathMultiplicity = "Muon/Barrel/Wheel_"+wheel+"/sector_"+str(sector)+"/station_"+str(station)+"/Multiplicity"+file[11:]

                    recordRow = []

                    chName = file[12:]
                    recordRow.append(runNumber)
                    recordRow.append(chName)

                    recordRow.append(wheel)
                    recordRow.append(sector)
                    recordRow.append(station)

                    avgCluster = getInfo(strPathCluster)['stats']['x']['mean']
                    recordRow.append(avgCluster)

                    occupancy = getInfo(strPathOcc)['nentries']
                    recordRow.append(occupancy)

                    bxDist = getInfo(strPathBX)['stats']['x']['mean']
                    recordRow.append(bxDist)

                    nOfClusters = getInfo(strPathNofClusters)['stats']['x']['mean']
                    recordRow.append(nOfClusters)

                    multiplicity = getInfo(strPathMultiplicity)['stats']['x']['mean']
                    recordRow.append(multiplicity)

                    recordRow.append(lumiSections)
                    recordRow.append(certType[:3])
                    recordRow.append(wheelEff[chName])
                    data_structure.append(recordRow)



#print "Dirs: ", count_dirs
#print "Cluster: ", count_clust
#print "Occupancy: ", count_occ

#print "===============DATA STRUCTURE=================="
#print data_structure
#print len(data_structure)
#print len(data_structure[0])

if not os.path.isfile(certType+"/"+str(runNumber)+".csv"):
    df = pd.DataFrame(data_structure, columns = ['run', 'chamber', 'wheel', 'sector', 'station', 'avg_cluster_size', 'occupancy', 'avg_bx_dist', 'avg_no_of_clusters', 'avg_multiplicity', 'lumisections', 'type', 'avg_efficiency'])
    df.to_csv(certType+"/"+str(runNumber)+".csv", encoding='utf-8', mode='a', index=False)
else:
    df = pd.DataFrame(data_structure)
    df.to_csv('data.csv', encoding='utf-8', mode='a', header=False, index=False)


print int(lumiSections)

# the script dumps a csv file containing a chamber name and its
# fiducial efficiency averaged at chamber level. The csv containing
# fiducial efficiency of roll level is also dumped.

# to run the code, enter:
# python dump_avg_fid_eff.py <path_to_Summary.root_file>

import os
import sys
import uproot
import numpy as np
import pandas as pd

summary_file = "SummaryAnalyzeEfficiency_XXXXXX_RPCMon.root"

runs_file = open("runs_to_get.txt", "r")
file_content = runs_file.read()
runs_list = file_content.split()

# print(runs_list)


# path = sys.argv[1]
# print(path)
#
# filename = path.split("/")[-1]
# print(filename)
#
# path_to_file = os.path.dirname(path)
# if len(path_to_file) != 0:
#     path_to_file += "/"
# print(path_to_file)

# sys.exit()

# file = uproot.open(path)

for run in runs_list:
    path = "Run"+run+"/"+summary_file
    print(path)
    file = uproot.open(path)

    wheels = ['W-2', 'W-1', 'W0', 'W1', 'W2']
    chamber_eff = {}

    roll_level_eff = {}

    # dictionary chamber_eff stores chamber name (chamber level) as key and
    # list of efficiency values (roll level - M, F, B)
    for wheel in wheels:

        wheel_object = file['Barrel/FiducialCutEff'+wheel]
        wheel_np = wheel_object.to_numpy(flow=False, dd=False)
        fid_cut_eff = wheel_np[0]
        np.shape(fid_cut_eff)
        sectors = wheel_object.member('fXaxis').labels(flow=False)
        chambers = wheel_object.member('fYaxis').labels(flow=False)

        if wheel == 'W0':
            wheel_name = "W+0"
        elif wheel == 'W1':
            wheel_name = 'W+1'
        elif wheel == 'W2':
            wheel_name = 'W+2'
        else:
            wheel_name = wheel
        for sector in range(len(fid_cut_eff)):

            for chamber in range(len(fid_cut_eff[0])):

                eff_value = fid_cut_eff[sector][chamber]

                sector_str = str(sector+1)
                if len(sector_str) == 1:
                    sector_str = "0"+sector_str

                chName = chambers[chamber]
                if chName.startswith('RB4,'):
                    chName = chName.replace(',','')

                if chName.startswith('RB4-_') and (sector_str == '09' or sector_str == '11'):
                    key = wheel_name+"_RB4_S"+sector_str
                else:
                    key = wheel_name+"_"+chName[:-2]+"_S"+sector_str

                # key = wheel_name+"_"+chName[:-2]+"_S"+sector_str

                roll_level_eff[wheel_name+"_"+chName+"_S"+sector_str] = eff_value

                if key not in chamber_eff.keys():
                    value_list = []
                    value_list.append(eff_value)
                    chamber_eff[key] = value_list
                else:
                    chamber_eff[key].append(eff_value)

    # averaging efficiencies at chamber level
    chamber_rolls_count = {}
    is_zero = {}
    for key in chamber_eff.keys():
        chamber_rolls_count[key] = len(chamber_eff[key])
        if 0 in chamber_eff[key]:
            is_zero[key] = 1
        else:
            is_zero[key] = 0
        chamber_eff[key] = sum(chamber_eff[key])/len(chamber_eff[key])


    # averaged dictionary is stored as Pandas DataFrame to be exported as csv
    if not os.path.exists("Collisions/"+run+"/"):
        os.makedirs("Collisions/"+run+"/")
    print(len(chamber_eff))
    zero_df = pd.DataFrame(is_zero.items(), columns = ['chamber', 'contains_zero_roll'])
    roll_count_df = pd.DataFrame(chamber_rolls_count.items(), columns = ['chamber', 'rolls_count'])
    averaged_fid_eff = pd.DataFrame(chamber_eff.items(), columns = ['chamber', 'fid_eff_ch_level'])
    final_fid_eff = zero_df.merge(roll_count_df, on='chamber').merge(averaged_fid_eff, on='chamber')

    final_fid_eff.to_csv("Collisions/"+run+"/"+'fid_with_roll.csv', encoding='utf-8', index=False)

    roll_level_fid_eff = pd.DataFrame(roll_level_eff.items(), columns = ['chamber', 'fid_eff_roll_level'])
    roll_level_fid_eff.to_csv("Collisions/"+run+"/"+'roll_fid_eff.csv', encoding='utf-8', index=False)

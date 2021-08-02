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

path = sys.argv[1]
print(path)

filename = path.split("/")[-1]
print(filename)

path_to_file = os.path.dirname(path)
if len(path_to_file) != 0:
    path_to_file += "/"
print(path_to_file)

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
for key in chamber_eff.keys():
    chamber_eff[key] = sum(chamber_eff[key])/len(chamber_eff[key])

# averaged dictionary is stored as Pandas DataFrame to be exported as csv
print(len(chamber_eff))
averaged_fid_eff = pd.DataFrame(chamber_eff.items(), columns = ['chamber', 'fid_eff_ch_level'])
print(averaged_fid_eff.head(10))
averaged_fid_eff.to_csv(path_to_file+'avg_fid_eff.csv', encoding='utf-8', index=False)

roll_level_fid_eff = pd.DataFrame(roll_level_eff.items(), columns = ['chamber', 'fid_eff_roll_level'])
roll_level_fid_eff.to_csv(path_to_file+'roll_fid_eff.csv', encoding='utf-8', index=False)

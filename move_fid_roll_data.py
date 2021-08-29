import os
import shutil


source_dirs = os.listdir("Eff_2018D/Collisions/")
print(source_dirs)

dest_dirs = os.listdir("Collisions/")
print(dest_dirs)

source_new_dirs = os.listdir("new_collisions/")
print(source_new_dirs)


#for directory in source_dirs:
#    if directory in dest_dirs:
#        shutil.copy2("Eff_2018D/Collisions/"+directory+"/fid_with_roll.csv", "Collisions/"+directory+"/")

for directory in source_new_dirs:
    if directory in dest_dirs:
        shutil.copy2("new_collisions/"+directory+"/fid_with_roll.csv", "Collisions/"+directory+"/")

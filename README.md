# CMS RPC efficiency measurments

The goal of the project is to analyse the relevant data and compute the efficiency of Resistive Plate Chambers on a chamber level using  common data science and machine learning practices.

The repository contains python scripts extracting relevant data for RPC efficiency measurements from .root files as well as the DQM system to store the data in .csv format. The final data of 10 runs for each Collisions and Cosmic runs in .csv files are stored in **Collisions/** and **Cosmics/** directories in separate subdirectories for each run.

Jupyter Notebooks **EDA_Collisions.ipynb** and **EDA_Cosmics.ipynb** contains some essential Exploratory Data Analysis for both Collisions and Cosmics data, whereas **efficiency_collisions.ipynb** and **efficiency_cosmics.ipynb** performs some further ML modeling to calculate chamber efficiency based on its metrics such as avg_cluster_size, occupancy, etc.

## Good Git practices

Before starting the work, always make sure to pull the recent changes by running command:
* git pull

Do the work on the notebooks prepared, after the job is done, don't forget to add new files (if occurred) created during development process and commit the changes using commands:
* git add .
* git commit -m "message indicating changes that were done"

After new files were added and changes were committed, always push the changes to the repository by running command:
* git push -u origin main


import os

arr = os.listdir()

print(arr)
dirs = []

for directory in arr:
    if directory.startswith("Run"):
        dirs.append(directory[3:])

print(dirs)

with open('runs_to_get.txt', 'w') as f:
    for item in dirs:
        f.write("%s\n" % item)

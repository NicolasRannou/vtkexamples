import os
import sys
import subprocess

path = sys.argv[2];
listing = os.listdir(path);

for mesh in  listing:
    subprocess.call([sys.argv[1], path + mesh]);

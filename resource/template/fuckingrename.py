import os, shutil
import re

for file in os.listdir("."):
	if re.match("Roguelike1@", file):
		os.rename(file, re.sub(r"^(Roguelike1@)", r"Phantom@Roguelike@", file))
	if re.match("Roguelike2@", file):
		os.rename(file, re.sub(r"^(Roguelike2@)", r"Mizuki@Roguelike@", file))

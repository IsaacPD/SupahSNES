import re

white_space = re.compile('\s')

with open("mnemonics.txt", "r") as f:
	mne = f.read()
	mne = white_space.split(mne)
	
	out = open("ops.txt", "w+")
	for m in mne:
		out.write("OP({})\n".format(m))
	out.close()


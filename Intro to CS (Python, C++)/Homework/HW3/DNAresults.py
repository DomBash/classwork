# Name: Dominic B
# Date: 9/16/2015
# Assignment: HW #3
# Collaberation:
# Description: Read in DNA files to find the skin type and diabetes risk

dataList = [4]
genotype = {}
has = 0
skinGeno = 0
rsid = ""

def checkType2Diabetes(genotype):
	if "rs7754840" in genotype:
		skinGeno = genotype["rs7754840"]
		#print(skinGeno)
		if skinGeno == "CC\n":
			return("1.3x Increased risk for Type-2 Diabetes")
		elif skinGeno == "CG\n":
			return("1.3x Increased risk for	Type-2	Diabetes")
		elif skinGeno == "GG\n":
			return("Normal risk for Type-2 Diabetes")
	else:
		return ("No DNA info in Type-2 Diabetes")

def checkSkinType(genotype):
	if "rs1426654" in genotype:
		skinGeno = genotype["rs1426654"]
		if skinGeno == "AA\n":
			return("Probably light-skinned, European ancestry")
		elif skinGeno == "AG\n":
			return("Probably mixed African/European ancestry")
		elif skinGeno == "GG\n":
			return("Probably darker-skinned, Asian or African ancestry")
	else:
		return ("No DNA info on Skin Type")

def parseFile(fname):
	fo = open(fname,"r")
	for line in fo:
		dataList = line.split(" ")
		if dataList[0] == "#":
			print("skipped")
			next(fo)
		else:
			dataList = line.split("	")
			rsid = dataList[0]
			print(rsid)
			genotype[rsid] = dataList[3]
	fo.close()
	return fname

def main():
	import sys
	fname = sys.argv[1]	
	
	print("Parsing",fname)
	parseFile(fname)
	print(checkType2Diabetes(genotype))
	print(checkSkinType(genotype))

main()

fname = "R03-BoulderWeatherData.csv"
fo = open(fname,"r")

lineCounter = 0
next(fo)

for line in fo:
	lineCounter = lineCounter + 1
	print(line)

print("The name of the file is:", fo.name)

fo.close()

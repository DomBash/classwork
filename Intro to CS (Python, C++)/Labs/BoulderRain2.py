fname = "R03-BoulderWeatherData.csv"
fo = open(fname,"r")

dataList = [7]

maxRain = 0.0
totalRain = 0.0
avgRain = 0.0
totalDays = 0
rain = 0.0

next(fo)

for line in fo:
	dataList = line.split(",")
	rain = float(dataList[4])

	if rain > maxRain:
		maxRain = rain
	totalRain += rain
	totalDays += 1
avgRain = totalRain/totalDays

print("The max rain is:", maxRain)
print("Average rain:", round(1000*avgRain)/1000)

fo.close()

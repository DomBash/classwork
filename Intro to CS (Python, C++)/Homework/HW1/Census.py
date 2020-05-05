# Assignment #1 Part 1: Calculate the population after one year.
# Name: Dominic B
# Date: 8/28/15

birth = 8
death = -13
imm = 40
pop = 318892103

# Find the number of seconds in a year
# 60 sec in min, 60 min in hour, 24 hours in day, 365 days in year
secInYear = 60*60*24*365

# Find amount of births, deaths, and immigrants in one year.
immPop = secInYear/imm
deathPop = secInYear/death
birthPop = secInYear/birth

# Add to find total population after one year
totalPop = pop + immPop + deathPop + birthPop

# Round the total population
totalPop = round(totalPop)

# Print the population after one year
print("The population will be",totalPop)









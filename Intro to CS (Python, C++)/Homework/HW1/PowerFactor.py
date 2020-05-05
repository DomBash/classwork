# Assignment #1 Part 2: Calculate the power factor.
# Name: Dominic B
# Date: 8/28/15

# Import math and sqrt
import math
from math import sqrt

# Get real and reactive power from user and make int
realPower = input("Enter the real power: ")
realPower = int(realPower)
reactivePower = input("Enter the reactive power: ")
reactivePower = int(reactivePower)

# Calculate the power factor
powerFactor = (realPower)/(sqrt(pow(realPower,2)+pow(reactivePower,2)))

# Make power factor a float and round to 2 decimal places
powerFactor = float(powerFactor)
powerFactor = powerFactor * 100
powerFactor = round(powerFactor,2) 

# Print the power factor
print("The power factor is:", powerFactor,"%")

















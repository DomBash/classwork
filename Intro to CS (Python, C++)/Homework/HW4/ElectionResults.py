#!/usr/bin/python3
# Name: Dominic B
# Date: 9/10/15
# Assignment #4: Read a file and format the data

import sys
fname = sys.argv[1]
fo = open(fname,"r")

dataList = [6]

votes = {}

counter = 0
name = 0
totalVotes = 0
percent = 0
highVote = 0
highVoteName = ""

for line in fo:
	dataList = line.split(" ")
	name = dataList[0], dataList[1]
	votes[name] = int(dataList[2]) + int(dataList[3]) + int(dataList[4]) + int(dataList[5])

fo.close()

for name in votes:
	totalVotes += votes[name]
	if votes[name] > highVote:
		highVote = votes[name]
		highVoteName = " ".join(name)

print("Candidates".center(15),"Votes".rjust(8),"Percent".rjust(10))
print("==========".center(15),"=====".rjust(8),"=======".rjust(10))

for name in votes:
	percent = round((votes[name] / totalVotes) * 100)
	nameStr = " ".join(name)
	votesStr = str(votes[name])
	percent = str(percent)
	print(nameStr.center(15),votesStr.rjust(8), percent.rjust(8),"%")

print("")	
print("The winner is", highVoteName,"with", highVote, "votes!\n")
print("Total votes polled:", totalVotes)


# Dominic B

width = input("")
width = float(width)

widthHalf = width/2
widthHalf = round(widthHalf)
widthHalf = widthHalf*2
widthHalf1 = widthHalf-2

width = int(width)

blank = " "
star = "*"
print((blank*widthHalf1)+"★")


for i in range(width):
	widthHalf = widthHalf -1
	print((blank*widthHalf)+(star*2*i))

print("Merry Christmas!")
	

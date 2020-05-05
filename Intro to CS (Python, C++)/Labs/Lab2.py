tax = .0735
costPerItem=float(input("what is the cost per item?"))
while costPerItem !=-1 :

	numItem = int(input("What is the number of items?"))

	if costPerItem < 5 or round((costPerItem*100))%10 == 0:
		totalCost = costPerItem*numItem
	else:
		totalCost = costPerItem*numItem+costPerItem*tax

	print("The total cost is $%.2f." % totalCost)
	costPerItem=float(input("What is the cost per item?"))

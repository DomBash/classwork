

def factorial(n):
	if n == 1 or n==0:
		return 1
	else:
		return n*factorial(n-1)
def nChooseK(n,k):
	ans = (factorial(n))/(factorial(k)*(factorial(n-k)))
	return ans

def main():
	print(nChooseK(4,2))
	print(nChooseK(10,5))

main()

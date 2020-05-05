int* AADM(array[], int size, int number)
{
	int newSize = =2*size;
	int* newArray;
	newArray = new int [newSize];

	if(number == 0)
	{
		return array;
	}
	
	for(int 1 = 0; i<number; i++)
	{
		if(i == 0)
		{
			for(int j = 0; j < size; j++)
			{
				newArray[j] = array[j];
			}
			for(int j = 0; j < size; j++)
			{
				newArray[j+size] = 2*newArray[j];
			}
		}
		else
		{
			int* tempArray;
			tempArray = new int [2*newSize];
			for(int j = 0; j < size; j++)
			{
				tempArray[j+newSize = 2*tempArray[j];
			}
		
		}
	}
}

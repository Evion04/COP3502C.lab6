#include <stdio.h>


int search(int numbers[], int low, int high, int value) 
{
	//Student: Evion De La Rosa
	if(low == high)//Checks if there is only one item to search
	{
		//Checks if the item is equal to the value
		if(numbers[low] == value)
			return low;//Returns the index if the item is equal to the value
	}
	else if(low > high)//A case where the value is not found
	{
		return -1;
	}
	else//Regular Case
	{
		//Finds the middle index between low and high
		int mid = (low + high)/2;

		//Checks what the number at the mid is in relation to value
		if(numbers[mid] == value)//If the mid number = value then return index
		{
			return mid;
		}
		else if(numbers[mid] > value)//If the mid number > value then call search with index now as high index
		{
			int recursiveIndex = search(numbers, low, mid - 1, value);//Searchers the left half
			return recursiveIndex;
		}
		else if(numbers[mid] < value)//If the mid number < value then call search with index now as low index
		{
			int recursiveIndex = search(numbers, mid + 1, high, value);// Searches the right half
			return recursiveIndex;
		}
	}

	//If the function gets to this point, then the value is not in the list
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *)malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
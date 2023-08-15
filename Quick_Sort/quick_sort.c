#include <stdio.h>

void swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int partition(int array[], int leftMostIndex, int rightMostIndex)
{
	int pivot = array[leftMostIndex];
	int redArrow = leftMostIndex + 1;
	int blueArrow = rightMostIndex;

	while(redArrow <= blueArrow)
	{
		while((array[redArrow] <= pivot) && (redArrow <= blueArrow))
		{
			redArrow++;
		}
		while((array[blueArrow] > pivot) && (redArrow <= blueArrow))
		{
			blueArrow--;
		}
		if(redArrow <= blueArrow)
		{
			swap(&array[redArrow], &array[blueArrow]);
		}
	}

	swap(&array[leftMostIndex], &array[blueArrow]);
	return blueArrow;
}


void quickSort(int array[], int leftMostIndex, int rightMostIndex)
{
	if(leftMostIndex < rightMostIndex)
	{
		int greenBlockIndex = partition(array, leftMostIndex, rightMostIndex);
		quickSort(array, leftMostIndex, greenBlockIndex - 1);
		quickSort(array, greenBlockIndex + 1, rightMostIndex);
	}
}


void printArray(int array[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
}


int main(void)
{
	int array[] = {8,6,9,4,2,3,4,7,10,23,56};
	int size = sizeof(array)/sizeof(int);

	printf("Original Array:\n");
	printArray(array, size);

	quickSort(array, 0, size - 1);

	printf("Sorted Array:\n");
	printArray(array, size);
}
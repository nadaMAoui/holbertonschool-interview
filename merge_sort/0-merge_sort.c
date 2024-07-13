#include "sort.h"

/**
* merge_worker - merge sort worker function
* @array: pointer to the array
* @size: size of the array
* @middle: Middle index
* @temp: pointer to a working array
* Return: nothing
*/

void merge_worker(int *array, int size, int middle, int *temp)
{
	int i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);
	for (i = 0, j = middle, k = 0; k < size; k++)
	{

		if (j == size)
		{
			temp[k] = array[i];
			i++;
		}
		else if (i == middle)
		{
			temp[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			temp[k] = array[j];
			j++;
		}
		else
		{
			temp[k] = array[i];
			i++;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	printf("[Done]: ");
	print_array(temp, size);
}

/**
* merge_rec - merge sort using recursion
* @array: pointer to the array
* @size: size of the array
* @temp: pointer to a working array
* Return: nothing
*/
void merge_rec(int *array, size_t size, int *temp)
{
	int middle;

	if (size < 2)
		return;
	middle = size / 2;
	merge_rec(array, middle, temp);
	merge_rec(array + middle, size - middle, temp);
	merge_worker(array, size, middle, temp);
}

/**
* merge_sort - merge sort
* @array: pointer to the array
* @size: size of the array
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	merge_rec(array, size, temp);
	free(temp);
}


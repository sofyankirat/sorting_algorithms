#include "sort.h"

int get_max(int *array, int size);

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	size_t idx, max_val = 0;
	int *count, *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	max_val = get_max(array, size); /* get max value */
	count = malloc(sizeof(int) * (max_val + 1));
	if (count == NULL)
	{
		free(temp);
		return;
	}

	for (idx = 0; idx < max_val + 1; idx++) /* initialize array to 0 */
		count[idx] = 0;

	for (idx = 0; idx < size; idx++) /* counting occurences */
		count[array[idx]]++;

	for (idx = 1; idx <= max_val; idx++) /* cumulative sum of occurences */
		count[idx] += count[idx - 1];

	print_array(count, (max_val + 1));

	/* sort array in reverse to maintain 'stability' */
	for (idx = size - 1; (int)idx >= 0; idx--)
	{
		temp[count[array[idx]] - 1] = array[idx];
		count[array[idx]]--;
	}

	for (idx = 0; idx < size; idx++)
		array[idx] = temp[idx]; /* reconstruct sorted array */

	free(count);
	free(temp);
}

/**
 * get_max - Gets the maximum value in an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, idx;

	for (max = array[0], idx = 1; idx < size; idx++)
	{
		if (array[idx] > max)
			max = array[idx];
	}

	return (max);
}

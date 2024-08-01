#include "sort.h"

int get_max(int *array, int size);
void radix_count_sort(int *array, size_t size, int pos);

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void.
 */
void radix_sort(int *array, size_t size)
{
	int pos, max_val;

	if (array == NULL || size < 2)
		return;

	max_val = get_max(array, size);

	for (pos = 1; max_val / pos > 0; pos *= 10)
	{
		radix_count_sort(array, size, pos);
		print_array(array, size);
	}
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

/**
 * radix_count_sort - Implemenation of the Radix sort algorithm, using the
 *                     Least Significant Digit (LSD).
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @pos: The position of the Least Significant Digit.
 *
 * Return: void.
 */
void radix_count_sort(int *array, size_t size, int pos)
{
	/* count will always be count[10] */
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int idx, exp, *temp;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (idx = 0; idx < (int)size; idx++) /* counting occurences */
		count[(array[idx] / pos) % 10]++;

	for (idx = 1; idx < 10; idx++) /* cumulative sum of occurences */
		count[idx] += count[idx - 1];

	/* sort array in reverse to maintain 'stability' */
	for (idx = size - 1; idx >= 0; idx--)
	{
		exp = (array[idx] / pos) % 10;
		temp[count[exp] - 1] = array[idx];
		count[exp]--;
	}

	for (idx = 0; idx < (int)size; idx++)
		array[idx] = temp[idx]; /* reconstruct sorted array */

	free(temp);
}

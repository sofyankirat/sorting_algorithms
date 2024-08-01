#include "sort.h"

/**
 * merge_sort - the merge sort algorithm's interface
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp; /* temporaray array for staging */

	temp = malloc(sizeof(int) * size);
	if (temp == NULL || array == NULL || size < 2)
		return;

	mergesrt(array, 0, size, temp);
	free(temp);
}

/**
 * mergesrt - the merge sort algorithm implementation
 * @A: array of integers to be sorted
 * @left: the start of the array at current state,
 * the position of the first element itself
 * @right: the end of the array at current state,
 * the position of the last element itself
 * @temp: temporary array
 *
 * Return: void
 */
void mergesrt(int A[], int left, int right, int *temp)
{
	int mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		/* above avoids integer overflow for large integers */
		mergesrt(A, left, mid, temp);
		mergesrt(A, mid, right, temp);
		merge(A, left, mid, right, temp);
	}
}

/**
 * merge - the merger function for mergesrt
 * @A: array of integers to be sorted
 * @left: the start of the array at current state,
 * the position of the first element itself
 * @right: the end of the array at current state,
 * the position of the last element itself
 * @mid: the middle of the current array,
 * size of the left array is less than or equal to that of the right array
 * @temp: temporary array
 *
 * Return: void
 */
void merge(int A[], int left, int mid, int right, int *temp)
{
	int i = left; /* counter for - left array*/
	int j = mid;  /* counter for - right array*/
	int k = 0;    /* counter for temp array */

	printf("Merging...\n[left]: ");
	print_array(A + left, mid - left);
	printf("[right]: ");
	print_array(A + mid, right - mid);
	/* copy from both left and rigth arrays but in a sorted manner */
	while (i < mid && j < right)
		temp[k++] = (A[i] < A[j]) ? A[i++] : A[j++];

	/* copy left-overs of left array if any */
	while (i < mid)
		temp[k++] = A[i++];

	/* copy left-overs of right array if any */
	while (j < right)
		temp[k++] = A[j++];

	/* move sorted data from the staging area to the main array */
	for (k = 0, i = left; i < right;)
		A[i++] = temp[k++];
	printf("[Done]: ");
	print_array(A + left, right - left);
}

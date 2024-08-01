#include "sort.h"
void swap(int *x, int *y);

/**
 * heapify - uses the sift-down approach to build a max heap of the structure.
 * This max heap building involves restoring the heap property of the
 * structure.
 * @a: the array being sorted
 * @n: the size of the current array
 * @i: the index of current root
 * @original_size: the real size of the array
 *
 * Return: void
 */
void heapify(int a[], int n, int i, int original_size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[left] > a[largest]) /* sh'd be an if instead */
		largest = left;
	if (right < n && a[right] > a[largest]) /* sh'd be an if instead */
		largest = right;
	if (largest != i)
	{
		swap(&a[i], &a[largest]);
		print_array(a, original_size);
		heapify(a, n, largest, original_size);
	}
}

/**
 * heap_sort - heap sort using the sift-down max heap approach
 * @a: the array to sort
 * @n: the size of the array
 *
 * Return: void
 */
void heap_sort(int a[], size_t n)
{
	int i;

	if (a == NULL || n < 2)
		return;

	/**
	 * n / 2 is the location of the last non-leaf element
	 *
	 */
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i, n); /* Build the correct maxheap structure */

	for (i = n - 1; i >= 1; i--)
	{
		swap(&a[0], &a[i]);
		print_array(a, n);
		heapify(a, i, 0, n);
	}
}

/**
 * swap - swaps two integer pointers
 * @x: first int variable
 * @y: second int variable
 *
 * Return: void
 */
void swap(int *x, int *y)
{
	int tm;

	tm = *x;
	*x = *y;
	*y = tm;
}

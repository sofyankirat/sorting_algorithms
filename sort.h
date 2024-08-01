#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*** Utilities provided for task ***/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** print functions **/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*** Function Prototypes  ***/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/*** Utilities ***/

/** Function specific **/
void printArray(int arr[], int size);
int lomuto(int array[], int start, int end, size_t size);
void quicksrt(int A[], int first, int last, size_t size);
void mergesrt(int A[], int left, int right, int *temp);
void merge(int A[], int left, int mid, int right, int *temp);
int *array_from_boundary(int A[], int left, int end);
void quicksort_fn_hoare(int A[], int low, int high, size_t size);
int hoare_lf_pvt(int A[], int left, int right, size_t size);
int hoare_rt_pvt(int A[], int left, int right, size_t size);
void heapify(int a[], int n, int i, int original_size);

#endif

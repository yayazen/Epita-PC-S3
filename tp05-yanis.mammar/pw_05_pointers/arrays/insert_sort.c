#include <string.h>

// Insertion using the plain algorithm.
void array_insert(int *begin, int *end, int x) {
	while (end > begin && x < *(end - 1)) {
		*end = *(end - 1);
		end--;
	}

	*end = x;
}

// Insertion sort using plain method.
void array_insert_sort(int *begin, int *end){
	for (int *i = begin; i < end; i++) {
		array_insert(begin, i, *i);
	}
}




int *bsearch(int x, int *begin, int *end) {
	int *mid;
	end--;

	while (begin <= end) {
		mid = begin + (end - begin) / 2;

		if (*mid < x)
			begin = mid + 1;
		else if (*mid > x)
			end = mid - 1;
		else
			return mid;
	}

	return begin;
}


// Insertion using the binary-search algorithm.
void array_insert_bin(int *begin, int *end, int x) {
	int *i = bsearch(x, begin, end);
	
	memmove(i + 1, i, (end - i) * sizeof(int));

	*i = x;	
}

// Insertion sort using binary search.
void array_insert_sort_bin(int *begin, int *end) {
	for (int *i = begin; i < end; i++) {
		array_insert_bin(begin, i, *i);
	}
}


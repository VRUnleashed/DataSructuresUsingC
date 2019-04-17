#include <stdio.h>
#include <stdlib.h>

void maxheap(int [], int);
void heapsort(int [], int);

void main() {
	int heap[50], n, i, ch;

	printf("Enter the number of elements you want in max heap\n");
	scanf("%d", &n);

	printf("Enter the elements one by one..\n");
	for(i = 0; i < n; i++) {
		scanf("%d", &heap[i]);
	}

	maxheap(heap, n);

	printf("\nThe Max Heap constructed is :\n");
	for(i = 0; i < n; i++) {
		printf("%d\n", heap[i]);
	}

    printf("\n");
    printf("Do you want to sort this list?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%d", &ch);

    switch(ch) {
        case 1:
            heapsort(heap, n);
            printf("\nThe sorted list is:\n");
            for(i = 0; i < n; i++) {
                printf("%d", heap[i]);
            }
            break;

        case 2:
            printf("Exiting...\n");
            exit(0);

        default :
            printf("Enter a valid choice.\n");
    }
}


void maxheap(int x[], int y) {
	int i, val, s, f;
	for(i = 1; i < y; i++) {
		val = x[i];
		s = i;
		f = (s - 1) / 2;
		while(s > 0 && x[f] < val) {
			x[s] = x[f];
			s = f;
			f = (s - 1) / 2;
		}
		x[s] = val;
	}
}


void heapsort(int x[], int y) {
	int i, s, f, ivalue;
	for(i = y - 1; i > 0; i--) {
		ivalue = x[i];
		x[i] = x[0];
		f = 0;

		if(i == 1)
			s = -1;
		else
			s = 1;

		if(i > 2 && x[2] > x[1])
			s = 2;

		while(s >= 0 && ivalue < x[s]) {
			x[f] = x[s];
			f = s;
			s = 2 * f + 1;

			if(s + 1 <= i - 1 && x[s] < x[s + 1])
				s++;
			if(s > i - 1)
				s = -1;
		}
		x[f] = ivalue;
	}
}

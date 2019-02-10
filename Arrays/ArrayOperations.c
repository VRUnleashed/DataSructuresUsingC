#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int noe = 0;

void insert(int*, int, int);
void delete(int*, int);
void reverse(int*);
void display(int*);
int search(int*, int, int*);

void main() {
    int opt, ele, pos, dele;

    printf("\t\tThis is a program to define operations on Arrays\n");

    while(1) {
        printf("\n--MENU--\n");
        printf("1. Insert new element\n");
        printf("2. Delete an element\n");
        printf("3. Reverse the array\n");
        printf("4. Display the current array\n");
        printf("5. Exit\n");

        printf("\nEnter your choice :\t");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                printf("\nEnter the element you want to add and its position respectively :\t");
                scanf("%d", &ele);
                scanf("%d", &pos);
                insert(arr, ele, pos);
                break;

            case 2:
                printf("\nEnter the element to be deleted :\t");
                scanf("%d", &dele);
                delete(arr, dele);
                break;

            case 3:
                reverse(arr);
                break;

            case 4:
                display(arr);
                break;

            case 5:
                return;

            default:
                printf("\nWhy u no speak human?\n");
        }
    }
}


void insert(int* arr, int num, int count) {
    int i;

    if(noe == MAX) {
        printf("\nYou have reached a maximium limit of no. of elements.\n");
        return;
    }

    if(noe == 0) {
        arr[0] = num;
        noe = noe + 1;
        return;
    }

    for(i = noe - 1; i >= count - 1; i--) {
        arr[i + 1] = arr[i];
    }

    noe = noe + 1;
    arr[count - 1] = num;
}


void delete(int* arr, int num) {
    int i, found, current;

    current = search(arr, num, &found);

    if(found == 0) {
        printf("\nElement %d not found.\n", num);
        return;
    }

    for (i = current; i < noe; i++) {
        arr[i] = arr[i + 1];
    }

    noe = noe - 1;
}


int search(int *arr, int num, int* found) {
    int i;

    *found = 0;

    for(i = 0; i < noe; i++) {
        if(num == arr[i]) {
            *found = 1;
            return i;
        }
    }

    return -1;
}


void reverse(int* arr) {
    int arr1[noe], i;

    if(noe == 0) {
        printf("\nArray is empty\n");
        return;
    }

    for(i = 0; i < noe; i++) {
        arr1[i] = arr[i];
    }

    for(i = 0; i < noe; i++) {
        arr[noe - 1 - i] = arr1[i];
    }
}


void display(int* arr) {
    int i;
    
    if(noe == 0) {
        printf("\nArray is empty.\n");
        return;
    }

    printf("\nThe current array is :\n");

    for(i = 0; i < noe; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}
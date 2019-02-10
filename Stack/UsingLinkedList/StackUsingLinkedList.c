#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node {
    int data;
    struct node* nptr;
};

struct node* tos = NULL;
int count = 0;

int main() {
    int opt;

    printf("This is a program to implement Stack\n");

    while(1) {
        printf("\nMENU\n");
        printf("1. Push an element to the stack\n");
        printf("2. Pop the latest element out of the stack\n");
        printf("3. Display the current stack\n");
        printf("4. Exit\n");

        printf("Enter your choice\t");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}


void push() {
    struct node* ptr = NULL;
    int ele;
    struct node* temp;

    ptr = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter the element to be pushed\n");
    scanf("%d", &ele);
    ptr->data = ele;
    count++;
    temp = tos;
    tos = ptr;
    ptr->nptr = temp;
}


void pop() {
    struct node* temp = NULL;

    if(count != 0) {
        temp = tos;
        tos = tos->nptr;
        count--;
        free(temp);
        printf("\nThe latest element is popped.\n");
    } else {
        printf("\nUnderflow!\n");
        return;
    }
}


void display() {
    struct node* temp = NULL;
    int count_cpy;

    if(count == 0) {
        printf("The Stack is empty!\n");
        return;
    }

    printf("\nThe current stack is:\n");
    temp = tos;
    count_cpy = count;

    while(count_cpy > 0) {
        printf("%d\n", temp->data);
        temp = temp->nptr;
        count_cpy--;
    }
}

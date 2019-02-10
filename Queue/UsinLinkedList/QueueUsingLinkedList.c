#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* nptr;
};

struct node* front = NULL;
struct node* rear = NULL;
int count = 0;

void enqueue();
void dequeue();
void display();

int main() {
    int opt;

    printf("This is a program to implement Queue\n");

    while(1) {
        printf("\nMENU\n");
        printf("1. Insert (enqueue) an element to the queue\n");
        printf("2. Remove (dequeue) the front element from the queue\n");
        printf("3. Display the current queue\n");
        printf("4. Exit\n");

        printf("Enter your choice\t");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}


void enqueue() {
    struct node* ptr = NULL;
    struct node* temp = NULL;
    int ele;

    ptr = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter the element to be added\n");
    scanf("%d", &ele);

    if(count == 0) {
        ptr->data = ele;
        ptr->nptr = NULL;
        front = ptr;
        rear = ptr;
        count++;
    } else {
        temp = rear;
        ptr->data = ele;
        ptr->nptr = NULL;
        temp->nptr = ptr;
        rear = ptr;
        count++;
    }
}


void dequeue() {
    struct node* temp = NULL;

    if(count == 0) {
        printf("\nUnderflow!\n");
        return;
    } else {
        temp = front;
        front = temp->nptr;
        free(temp);
        count = count - 1;
        printf("The front element is removed.\n");
    }
}


void display() {
    int count_cpy;
    struct node* temp = NULL;

    if(count == 0) {
        printf("The Queue is empty!\n");
        return;
    }
    else{
        count_cpy = count;
        temp = front;

        printf("\nThe current queue is :\n");
        while(count_cpy != 0) {
            printf("%d\n", temp->data);
            temp = temp->nptr;
            count_cpy--;

        }
    }
}

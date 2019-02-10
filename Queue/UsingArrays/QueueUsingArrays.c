#include <stdio.h>
#include <stdlib.h>

int queue_size = 100;
int queue[100];
int front = -1;
int rear = -1;
int count = 0;

int enqueue(int, int, int);
int dequeue(int, int, int);
int display(int);

int main()
{
    int i, opt;

    printf("Enter the number of elements to be added in the queue\n");
    scanf("%d", &count);

    printf("Enter the queue elements\n");

    for(i = 0; i < count; i++) {
        scanf("%d", &queue[i]);
    }

    if(count != 0) {
        front = 0;
        rear = count - 1;
    }

    while(1) {
        printf("\n---- MENU ----\n");
        printf("1. Insert (enqueue) an element\n");
        printf("2. Delete (dequeue) the first queue element\n");
        printf("3. Display the current queue\n");
        printf("4. Exit\n");

        printf("Enter your choice\n");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                enqueue(front, rear, count);
                break;

            case 2:
                dequeue(front, rear, count);
                break;

            case 3:
                display(count);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid option\n");
        }
    }
}


int enqueue(int front_cpy, int rear_cpy, int count_cpy) {
    int element;

    printf("Enter the element to be added in queue\n");
    scanf("%d", &element);

    if((front_cpy == 0 && rear_cpy == queue_size) || (front_cpy == rear_cpy + 1)) {
        printf("Overflow!\n");
        return -1;
    }

    if(front_cpy == -1) {
        front_cpy++;
        rear_cpy++;
        rear = rear_cpy;
        front = front_cpy;
    } else if(rear_cpy == queue_size - 1) {
        rear_cpy = 0;
        rear = rear_cpy;
    } else {
        rear_cpy++;
        rear = rear_cpy;
    }

    queue[rear_cpy] = element;
    count_cpy++;
    count = count_cpy;

    return 0;
}


int dequeue(int front_cpy1, int rear_cpy1, int count_cpy) {
    if(front_cpy1 == -1) {
        printf("Underflow!\n");
        return -1;
    }

    if(front_cpy1 == rear_cpy1) {
        front_cpy1 = -1;
        rear_cpy1 = -1;
        front = front_cpy1;
        rear = rear_cpy1;
    } else if(front_cpy1 == queue_size - 1) {
        front_cpy1 = 0;
        front = front_cpy1;
    } else {
        front_cpy1++;
        front = front_cpy1;
    }

    count_cpy--;
    count = count_cpy;

    return 0;
}

int display(int count_cpy) {
    int i;

    printf("\nThe current queue is:\n");

    if(front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    i = front - 1;

    do {
        if(i == queue_size) {
            printf("%d\n", queue[i]);
            i = 0;
        } else {
            i = i + 1;
            printf("%d\n", queue[i]);
        }
    } while(i != rear);

    return 0;
}

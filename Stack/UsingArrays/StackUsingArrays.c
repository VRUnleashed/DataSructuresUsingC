#include <stdio.h>
#include <stdlib.h>

int stacksize = 100;
int stack[100];
int top = -1;

int push(int);
int pop(int);
int display();

int main()
{
    int i, count, opt;

    printf("Enter the number of elements to be added in the stack\n");
    scanf("%d", &count);

    printf("Enter the stack elements\n");

    for(i = 0; i < count; i++) {
        scanf("%d", &stack[i]);
    }

    top = count - 1;

    while(1) {
        printf("\n---- MENU ----\n");
        printf("1. Push an element\n");
        printf("2. Pop the latest element\n");
        printf("3. Display the current stack\n");
        printf("4. Exit\n");

        printf("Enter your choice\n");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                push(top);
                break;

            case 2:
                pop(top);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid option\n");
        }
    }
}


int push(int top_cpy) {
    int element;

    if(top_cpy == stacksize) {
        printf("Overflow!");
        return -1;
    }

    printf("Enter the element to be pushed\n");
    scanf("%d", &element);

    top_cpy++;
    stack[top_cpy] = element;
    top = top_cpy;

    return 0;
}


int pop(int top_cpy1) {
    if(top_cpy1 == -1) {
        printf("Underflow!\n");
        return -1;
    }

    top_cpy1--;
    top = top_cpy1;

    printf("Latest element is popped out of the stack\n");

    return 0;
}


int display() {
    int i;

    if(top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }

    printf("The current stack is:\n");

    for(i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    return 0;
}

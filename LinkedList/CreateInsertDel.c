#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
    int data;
    struct node* link;
};


void append(struct node** q, int num); /* add at the end */
void addatbeg(struct node** q, int num); /* add at beggining */
void addafter(struct node* q, int num, int pos); /* add after a specified no. of nodes */
void display(struct node* q);
int count(struct node* q);
void del(struct node** q, int num);


int main() {
    struct node* p;
    p = NULL;

    printf("No. of elements in linked list = %d\n", count(p));
    append(&p, 14);
    append(&p, 30);
    append(&p, 25);
    append(&p, 42);
    append(&p, 17);

    system("clear");

    display(p);

    addatbeg(&p, 999);
    addatbeg(&p, 888);
    addatbeg(&p, 777);

    display(p);

    addafter(p, 7, 0);
    addafter(p, 2, 1);
    addafter(p, 5, 99);

    display(p);
    printf("No. of elements in linked list = %d\n", count(p));

    del(&p, 99);
    del(&p, 1);
    del(&p, 10);

    display(p);
    printf("No. of elements in the linked list = %d\n", count(p));

    return 0;
}


void append(struct node** q, int num) {
    struct node* temp;
    struct node* r;

    if(*q == NULL) {
        temp = (struct node*) malloc(sizeof(struct node));
        temp->data = num;
        temp->link = NULL;
        *q = temp;
    } else {
        temp = *q;

        while(temp->link != NULL) {
            temp = temp->link;
        }

        r = (struct node*) malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}


void addatbeg(struct node** q, int num) {
    struct node* temp;

    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = num;
    temp->link = *q;
    *q = temp;
}


void addafter(struct node* q, int pos, int num) {
    int i;
    struct node* temp;
    struct node* r;

    temp = q;

    for(i = 0; i < pos; i++) {
        temp = temp->link;

        if(temp == NULL) {
            printf("There are less elemnts in the list than the location specified.\n");
            return;
        }
    }

    r = (struct node*) malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}


void display(struct node* q) {
    struct node* temp;
    temp = q;

    while(temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->link;
    }

    printf("\n");
}


int count(struct node* q) {
    int c = 0;
    struct node* temp;

    temp = q;

    while(temp != NULL) {
        c++;
        temp = temp->link;
    }

    return c;
}


void del(struct node** q, int num) {
    struct node* temp, *r;
    int endOfList = 0;

    temp = *q;

    if(temp->data == num) {
        *q = temp->link;
        free(temp);
        return;
    }

    while(temp->data != num && temp->link != NULL) {

        r = temp;
        temp = temp->link;

        if(temp->link == NULL && temp->data != num) {
            endOfList = 1;
            break;
        }
    }

    if(endOfList == 1) {
        printf("Element %d not found.\n", num);
        return;
    } else {
        r->link = temp->link;
        free(temp);
        return;
    }
}

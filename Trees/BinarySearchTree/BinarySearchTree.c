#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct bstree {
    int data;
    struct bstree* leftChild;
    struct bstree* rightChild;
};

struct bstree* tree = NULL;


void traverse();
void del();
void ins();
void insert(struct bstree**, int);
void delEle(struct bstree**, int);
void inOrder(struct bstree*);
void postOrder(struct bstree*);
void preOrder(struct bstree*);
void searchEle(struct bstree**, int, struct bstree**, struct bstree**, int*);

void main() {
    int opt, element, count, i;
    int value;
    FILE* fptr;

    printf("\t\tThis is a program to represent binary search tree.\n");

    while(1) {
        printf("\n\n--MENU--\n");
        printf("1. Create new tree\n");
        printf("2. Insert new element in the tree\n");
        printf("3. Delete an element from the tree\n");
        printf("4. Traverse and print\n");
        printf("5. Quit\n");

        printf("\nEnter your choice\n");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                tree = NULL;

                printf("Enter the number of elements you want in the tree\n");
                scanf("%d", &count);

                fptr = fopen("BinarySearchTree.txt", "w");

                printf("\nEnter the tree elements\n");

                for(i = 0; i < count; i++) {
                     scanf("%d", &value);
                     fprintf(fptr, "\t%d", value);
                }

                fclose(fptr);

                fptr = fopen("BinarySearchTree.txt", "r");

                while(!feof(fptr)) {
                    fscanf(fptr, "%d", &element);
                    insert(&tree, element);
                }

                fclose(fptr);
                break;

            case 2:
                ins();
                break;

            case 3:
                del();
                break;

            case 4:
                traverse();
                break;

            case 5:
                return;

           default:
                printf("Invalid Input!!ABORTING!!");
        }
    }
}


void ins() {

    int ele;
    printf("\nEnter the element to be added\n");
    scanf("%d", &ele);

    insert(&tree, ele);
}


void del() {
    int ele;

    if(tree == NULL) {
        printf("\nTree Empty\n");
        return;
    }

    printf("\nEnter the element to be deleted\n");
    scanf("%d", &ele);

    delEle(&tree, ele);
}


void traverse() {
    int option;

    if(tree == NULL) {
        printf("\nTree Empty\n");
        return;
    }

    printf("\nChoose the type of traversal\n");
    printf("1. Pre-order Traversal\n");
    printf("2. In-order Traversal\n");
    printf("3. Post-order Traversal\n");
    scanf("%d", &option);
    printf("\n");

    if(option == 1) {
        printf("Pre-order Traversal :\t");
        preOrder(tree);
    } else if(option == 2) {
        printf("In-order Traversal :\t");
        inOrder(tree);
    } else if(option == 3) {
        printf("Post-order Traversal :\t");
        postOrder(tree);
    } else {
        printf("Invalid choice. Returning to main menu....\n");
        return;
    }
}


void insert(struct bstree** tr, int num) {
    if(*tr == NULL) {
        *tr = (struct bstree*) malloc(sizeof(struct bstree));
        (*tr)->leftChild = NULL;
        (*tr)->data = num;
        (*tr)->rightChild = NULL;
    } else {

        if(num < (*tr)->data)
            insert(&((*tr)->leftChild), num);
        else
            insert(&((*tr)->rightChild), num);
    }
}


void searchEle(struct bstree** root, int num, struct bstree** x, struct bstree** par, int* found) {

    struct bstree* temp;
    *found = 0;
    *par = NULL;

    temp = *root;

    while(temp != NULL) {
        if(temp->data == num) {
            *x = temp;
            *found = 1;
            return;
        }

        *par = temp;

        if(num < temp->data)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }
}


void delEle(struct bstree** root, int num) {
    struct bstree* parent, *x, *xsucc;
    int found;

    parent = NULL;
    x = NULL;

    searchEle(root, num, &x, &parent, &found);

    if(found == 0) {
        printf("\nElement %d not found.\n", num);
        return;
    }

    if(x->leftChild != NULL && x->rightChild != NULL) {
        parent = x;
        xsucc = x->rightChild;

        while(xsucc->leftChild != NULL) {
            parent = xsucc;
            xsucc = xsucc->leftChild;
        }

        x->data = xsucc->data;
        x = xsucc;
    }


    if(x->leftChild == NULL && x->rightChild == NULL) {
        if(parent != NULL) {
            if(parent->leftChild == x)
                parent->leftChild = NULL;
            else
                parent->rightChild = NULL;
        } else
            tree = NULL;

        free(x);
        return;
    }

    if(x->leftChild != NULL && x->rightChild == NULL) {
        if(parent != NULL) {
            if(parent->leftChild == x)
                parent->leftChild = x->leftChild;
            else
                parent->rightChild = x->leftChild;
        } else
            tree = x->leftChild;

        free(x);
        return;
    }

    if(x->leftChild == NULL && x->rightChild != NULL) {
        if(parent != NULL) {
            if(parent->leftChild == x)
                parent->leftChild = x->rightChild;
            else
                parent->rightChild = x->rightChild;
        } else
            tree = x->rightChild;

        free(x);
        return;
    }
}


void preOrder(struct bstree* bt) {

    if(bt != NULL) {
        printf("%d\t", bt->data);
        preOrder(bt->leftChild);
        preOrder(bt->rightChild);
    }
}


void inOrder(struct bstree* bt) {

    if(bt != NULL) {
        inOrder(bt->leftChild);
        printf("%d\t", bt->data);
        inOrder(bt->rightChild);
    }
}


void postOrder(struct bstree* bt) {

    if(bt != NULL) {
        postOrder(bt->leftChild);
        postOrder(bt->rightChild);
        printf("%d\t", bt->data);
    }
}

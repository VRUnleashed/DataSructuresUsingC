#include <stdio.h>
#include <stdlib.h>

struct tree {
    char data;
    struct tree* lc;
    struct tree* rc;
};

struct tree* buildTree(int);
void inorder(struct tree*);

char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H', '\0',
            '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

int main() {
    struct tree* root;

    system("clear");

    root = buildTree(0);

    printf("In-Order Traversal:\n");
    inorder(root);

    return 0;
}

struct tree* buildTree(int n) {
    struct tree* temp = NULL;

    if(a[n] != '\0') {
        temp = (struct tree*)malloc(sizeof(struct tree));

        temp->lc = buildTree(2*n + 1);
        temp->data = a[n];
        temp->rc = buildTree(2*n + 2);
    }

    return temp;
}

void inorder(struct tree* ctree) {

    if(ctree != NULL){
        inorder(ctree->lc);
        printf("%c\n", ctree->data);
        inorder(ctree->rc);
    }
}
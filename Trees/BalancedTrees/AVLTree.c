#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define FALSE 0
#define TRUE 1

struct AVLNode {
    int data;
    int balfact;
    struct AVLNode *left;
    struct AVLNode *right;
};

struct AVLNode* buildtree(struct AVLNode*, int, int*);
struct AVLNode* deldata(struct AVLNode*, int, int*);
struct AVLNode* del(struct AVLNode*, struct AVLNode*, int*);
struct AVLNode* balright(struct AVLNode*, int*);
struct AVLNode* balleft(struct AVLNode*, int*);
void display(struct AVLNode*);
void deltree(struct AVLNode*);


int main() {
    struct AVLNode* avl = NULL;
    int h, choice, count, x, i;

    printf("\t\tThis is a program to implement AVL Trees\n\n");

    while(1) {
        printf("\n--MENU--\n");
        printf("1. Create new AVL tree.\n");
        printf("2. Delete a node from the current tree.\n");
        printf("3. Insert a new node in the current tree.\n");
        printf("4. Display the current AVL Tree.\n");
        printf("5. Quit\n");
        printf("\nEnter your choice.\n");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            if(avl != NULL) {
                avl = NULL;
            }

            printf("\nEnter the number of nodes you want in the tree.\n");
            scanf("%d", &count);
            printf("\nEnter the nodes one by one.\n");

            for(i = 0; i < count; i++) {
                scanf("%d", &x);
                avl = buildtree(avl, x, &h);
            }

            break;

        case 2:
            printf("\nEnter the node you want to delete.\n");
            scanf("%d", &x);
            avl = deldata(avl, x, &h);
            break;

        case 3:
            printf("\nEnter the node you want to insert.\n");
            scanf("%d", &x);
            avl = buildtree(avl, x, &h);
            printf("\n");
            break;

        case 4:
            printf("\nThe current AVL tree is:\n");
            display(avl);
            break;

        case 5:
            printf("\nAbort...");
            deltree(avl);
            return 0;

        default:
            printf("Enter a valid choice.\n");
        }
    }

    return 0;
}


struct AVLNode *buildtree(struct AVLNode* root, int data, int *h) {
    struct AVLNode *node1, *node2;

    if(!root) {
        root = (struct AVLNode*) malloc (sizeof(struct AVLNode));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->balfact = 0;
        *h = TRUE;
        return (root);
    }

    if(data < root->data) {
        root->left = buildtree(root->left, data, h);

        if(*h) {
            switch(root->balfact) {
            case 1:
                node1 = root->left;
                if(node1->balfact == 1) {
                    printf("Right rotation along %d.\n", root->data);
                    root->left = node1->right;
                    node1->right = root;
                    root->balfact = 0;
                    root = node1;
                } else {
                    printf("Double rotation, left along %d", node1->data);
                    node2 = node1->right;
                    node1->right = node2->left;
                    printf(" then right along %d.\n", root->data);
                    node2->left = node1;
                    root->left = node2->right;
                    node2->right = root;
                    if(node2->balfact == 1)
                        root->balfact = -1;
                    else
                        root->balfact = 0;
                    if(node2->balfact == -1)
                        node1->balfact = 1;
                    else
                        node1->balfact = 0;
                    root = node2;
                }
                root->balfact = 0;
                *h = FALSE;
                break;

            case 0:
                root->balfact = 1;
                break;

            case -1:
                root->balfact = 0;
                *h = FALSE;
            }
        }
    }

    if(data > root->data) {
        root->right = buildtree(root->right, data, h);

        if(*h) {
            switch(root->balfact) {
            case 1:
                root->balfact = 0;
                *h = FALSE;
                break;

            case 0:
                root->balfact = -1;
                break;

            case -1:
                node1 = root->right;
                if(node1->balfact == -1) {
                    printf("Left rotation along %d.\n", root->data);
                    root->right = node1->left;
                    node1->left = root;
                    root->balfact = 0;
                    root = node1;
                } else {
                    printf("Double rotation, right along %d", node1->data);
                    node2 = node1->left;
                    node1->left = node2->right;
                    node2->right = node1;
                    printf(" then left along %d.\n", root->data);
                    root->right = node2->left;
                    node2->left = root;

                    if(node2->balfact == -1)
                        root->balfact = 1;
                    else
                        root->balfact = 0;
                    if(node2->balfact == 1)
                        node1->balfact = -1;
                    else
                        node1->balfact = 0;
                    root = node2;
                }
                root->balfact = 0;
                *h = FALSE;
            }
        }
    }
    return (root);
}


struct AVLNode* deldata(struct AVLNode* root, int data, int *h) {
    struct AVLNode* node;

    if(!root) {
        printf("No such data.\n");
        return (root);
    } else {
        if(data < root->data) {
            root->left = deldata(root->left, data, h);
            if(*h)
                root = balright(root, h);
        } else {
            if(data > root->data) {
                root->right = deldata(root->right, data, h);
                if(*h)
                    root = balleft(root, h);
            } else {
                node = root;
                if(node->right == NULL) {
                    root = node->left;
                    *h = TRUE;
                    free(node);
                } else {
                    if(node->left == NULL) {
                        root = node->right;
                        *h = TRUE;
                        free(node);
                    } else {
                        node->right = del(node->right, node, h);
                        if(*h)
                            root = balleft(root, h);
                    }
                }
            }
        }
    }
    return (root);
}


struct AVLNode* del(struct AVLNode* succ, struct AVLNode* node, int* h) {
    struct AVLNode* temp = succ;
    if(succ->left != NULL) {
        succ->left = del(succ->left, node, h);
        if(*h)
            succ = balright(succ, h);
    } else {
        temp = succ;
        node->data = succ->data;
        succ = succ->right;
        free(temp);
        *h = TRUE;
    }
    return (succ);
}


struct AVLNode* balright(struct AVLNode* root, int* h) {
    struct AVLNode *node1, *node2;

    switch(root->balfact) {
    case 1:
        root->balfact = 0;
        break;

    case 0:
        root->balfact = -1;
        *h = FALSE;
        break;

    case -1:
        node1 = root->right;
        if(node1->balfact <= 0) {
            printf("Left rotation along %d.\n", root->data);
            root->right = node1->left;
            node1->left = root;
            if(node1->balfact == 0) {
                root->balfact= -1;
                node1->balfact = 1;
                *h = FALSE;
            } else {
                root->balfact = node1->balfact = 0;
            }
            root = node1;
        } else {
            printf("Double rotation, right along %d", node1->data);
            node2 = node1->left;
            node1->left = node2->right;
            node2->right = node1;
            printf(" then left along %d.\n", root->data);
            root->right = node2->left;
            node2->left = root;

            if(node2->balfact == -1)
                root->balfact = 1;
            else
                root->balfact = 0;
            if(node2->balfact == 1)
                node1->balfact = -1;
            else
                node1->balfact = 0;
            root = node2;
            node2->balfact = 0;
        }
    }
    return (root);
}


struct AVLNode* balleft(struct AVLNode* root, int* h) {
    struct AVLNode *node1, *node2;

    switch(root->balfact) {
    case -1:
        root->balfact = 0;
        break;

    case 0:
        root->balfact = 1;
        *h = FALSE;
        break;

    case 1:
        node1 = root->left;
        if(node1->balfact >= 0) {
            printf("Right rotation along %d.\n", root->data);
            root->left = node1->right;
            node1->right = root;
            if(node1->balfact == 0) {
                root->balfact= 1;
                node1->balfact = -1;
                *h = FALSE;
            } else {
                root->balfact = node1->balfact = 0;
            }
            root = node1;
        } else {
            printf("Double rotation, left along %d", node1->data);
            node2 = node1->right;
            node1->right = node2->left;
            node2->left = node1;
            printf(" then right along %d.\n", root->data);
            root->left = node2->right;
            node2->right = root;

            if(node2->balfact == 1)
                root->balfact = -1;
            else
                root->balfact = 0;
            if(node2->balfact == -1)
                node1->balfact = 1;
            else
                node1->balfact = 0;
            root = node2;
            node2->balfact = 0;
        }
    }
    return (root);
}


void display(struct AVLNode* root) {
    if(root != NULL) {
        display(root->left);
        printf("%d\t", root->data);
        display(root->right);
    }
}


void deltree(struct AVLNode* root) {
    if(root != NULL) {
        deltree(root->left);
        deltree(root->right);
    }
    free(root);
}

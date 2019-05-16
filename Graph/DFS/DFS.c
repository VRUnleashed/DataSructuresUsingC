#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int top = -1;
int stack[MAX];
int adj[MAX][MAX];
struct node* adjList[MAX];
int vertexCount = 0;

struct node {
    int data;
    int visited;
};

void addVertex(int x) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = x;
    temp->visited = 0;
    adjList[vertexCount] = temp;
    vertexCount++;
}

void addEdge(int start, int end) {
    adj[start][end] = 1;
    adj[end][start] = 1;
}

void push(int x) {
    top++;
    stack[top] = x;
}

void pop() {
    top--;
}

void displayVertex(int x) {
    printf("\n%d", adjList[x]->data);
}

int peek() {
    return stack[top];
}

int neighbour(int index) {
    int i;

    for(i = 0; i < vertexCount; i++) {
        if(adj[index][i] == 1 && adjList[i]->visited == 0) {
            return i;
        }
    }

    return -1;
}

void depthFirstSearch() {
    int i, unvisitedVertex;
    adjList[0]->visited = 1;
    displayVertex(0);
    push(0);

    while(top != -1) {
        unvisitedVertex = neighbour(peek());

        if(unvisitedVertex == -1) {
            pop();
        } else {
            adjList[unvisitedVertex]->visited = 1;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }
}


int main() {
    int x, c, s, e, i, j, vertices;

    printf("\t\tDFS\n\n");
    printf("Enter the number of vertices (maximum 8)\n");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            adj[i][j] = 0;

    printf("\nThe starting vertex will be 0, so enter the graph details accordingly.\n");
    printf("Enter the data of each vertex one by one (integer)\n");

    for(c = 0; c < vertices; c++) {
        scanf("%d", &x);
        addVertex(x);
    }

    printf("Now enter the edges one by one in order\n");
    printf("When finished, enter '-1'\n");
    printf("Example for entering an edge - Starting_index[press_enter]Terminating_index[press_enter]\n");

    while(1) {
        scanf("%d", &s);
        if(s == -1)
            break;
        scanf("%d", &e);
        addEdge(s, e);
        printf("\n");
    }

    printf("\n\nDFS Traversal:\n\n");
    depthFirstSearch();

    return 0;
}

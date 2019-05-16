#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 8

struct Vertex {
   int label;
   bool visited;
};

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

struct Vertex* lstVertices[MAX];

int adjMatrix[MAX][MAX];

int vertexCount = 0;

void insert(int data) {
   queue[++rear] = data;
   queueItemCount++;
}

int removeData() {
   queueItemCount--;
   return queue[front++];
}

bool isQueueEmpty() {
   return queueItemCount == 0;
}

void addVertex(int label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;
   vertex->visited = false;
   lstVertices[vertexCount++] = vertex;
}

void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
   printf("%d ",lstVertices[vertexIndex]->label);
}

int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
         return i;
   }

   return -1;
}

void breadthFirstSearch() {
   int i;

   lstVertices[0]->visited = true;

   displayVertex(0);

   insert(0);
   int unvisitedVertex;

   while(!isQueueEmpty()) {
      int tempVertex = removeData();

      while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         insert(unvisitedVertex);
      }

   }

   for(i = 0;i<vertexCount;i++) {
      lstVertices[i]->visited = false;
   }
}

int main() {
    int x, c, s, e, i, j, vertices;

    for(i = 0; i<MAX; i++)
       for(j = 0; j<MAX; j++)
          adjMatrix[i][j] = 0;

    printf("\t\tBFS\n\n");
    printf("Enter the number of vertices (maximum 8)\n");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;

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
    printf("\nBreadth First Search: ");

    breadthFirstSearch();

    return 0;
}

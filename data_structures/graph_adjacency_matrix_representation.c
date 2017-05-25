/*
  Representation using Adjacency Matrix
  |0 1 1 1|
  |1 0 1 1|
  |1 1 0 1|
  |1 1 1 0|
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
  int   nodeCount;
  int*  edges;    // Matrix
} Graph;

void addEdge(Graph* graph, int head, int tail, int weight){
  assert(head < graph->nodeCount);
  assert(tail < graph->nodeCount);
  *(graph->edges + head*graph->nodeCount + tail) = weight;
}

Graph* newGraph(int noOfNodes){
  Graph* graph      = malloc(sizeof(Graph));
  graph->nodeCount  = noOfNodes;
  graph->edges      = malloc(sizeof(int) * noOfNodes * noOfNodes);

  return graph;
}

void display(Graph* graph){
  for(int i=0; i< graph->nodeCount; i++){
    printf("| ");
    for(int j=0; j< graph->nodeCount; j++){
      printf("%d ", graph->edges[i*graph->nodeCount + j]);
    }
    printf("|\n");
  }
}

void main(){
  int noOfNodes = 4;
  Graph* graph  = newGraph(noOfNodes);
  addEdge(graph, 0, 1, 3);
  addEdge(graph, 0, 2, 3);
  addEdge(graph, 1, 3, 5);
  addEdge(graph, 1, 2, 4);
  addEdge(graph, 2, 1, 3);
  addEdge(graph, 2, 3, 3);
  assert(graph->edges[0*4 +  1] == 3); // [0,1]
  assert(graph->edges[0*4 +  2] == 3); // [0,2]
  assert(graph->edges[1*4 +  3] == 5); // [1,3]

  display(graph);
}

/* Output

| 0 3 3 0 |
| 0 0 4 5 |
| 0 3 0 3 |
| 0 0 0 0 |

*/

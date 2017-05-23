#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
  int       index;
  int       list_count;
  int       *list;
} NODE;

typedef struct{
  int       node_count;
  NODE      *nodes;
} GRAPH;

/*
  A constructor to create new GRAPH object
  special use is: initialization of certain fields before object is usable  
*/
GRAPH newGraph(int size){
  GRAPH graph;
  graph.node_count    = size;
  graph.nodes         = malloc(sizeof(NODE)*size);

  for(int i = 0; i < size; i++){
    NODE *node        = malloc(sizeof(NODE));
    node->index       = i;
    node->list_count  = 0;
    graph.nodes[i]    = *node;
  }
  return graph;
}

/*
  Adds edges to the Graph provided.
  It features are
    - prevents unnecessary memory allocation
    - allocates only when new instance of object is needed
*/
void add_edge(GRAPH *graph, int src, int dest){
  int pos_of_new_item = graph->nodes[src].list_count++;

  if(graph->nodes[src].list != NULL){
    unsigned int new_size_of_list = sizeof(int)*(pos_of_new_item + 1);
    graph->nodes[src].list        = realloc(graph->nodes[src].list, new_size_of_list);
  }else{
    graph->nodes[src].list        = malloc(sizeof(int));
  }

  // Stores the location just been allocated using `malloc` or `realloc`
  graph->nodes[src].list[pos_of_new_item] =  dest;
}

void display(GRAPH *graph){
  printf("The number of vertices is %d\n", graph->node_count);
  for(int i=0; i < graph->node_count; i++){
    printf("For vertex `%d`", graph->nodes[i].index);
    for(int j=0; j< graph->nodes[i].list_count; j++){
      printf(" --> %d", graph->nodes[i].list[j]);
    }
    printf("\n");
  }
}

void main(){
  int n = 5;
  GRAPH graph = newGraph(n);

  assert(graph.node_count       == n);
  assert(graph.nodes[0].index   == 0);
  assert(graph.nodes[1].index   == 1);
  assert(graph.nodes[3].index   == 3);
  assert(graph.nodes[4].index   == 4);

  add_edge(&graph, 0, 1);
  add_edge(&graph, 0, 4);
  add_edge(&graph, 0, 2);
  add_edge(&graph, 1, 2);
  add_edge(&graph, 1, 4);
  add_edge(&graph, 2, 4);
  add_edge(&graph, 3, 4);
  add_edge(&graph, 4, 0);
  add_edge(&graph, 4, 2);
  add_edge(&graph, 4, 1);

  assert(graph.nodes[0].list[0] == 1);
  assert(graph.nodes[0].list[1] == 4);
  assert(graph.nodes[0].list[2] == 2);
  assert(graph.nodes[1].list[0] == 2);
  assert(graph.nodes[1].list[1] == 4);

  display(&graph);
}

/* Output

The number of vertices is 5
For verted `0` --> 1 --> 4 --> 2
For verted `1` --> 2 --> 4
For verted `2` --> 4
For verted `3` --> 4
For verted `4` --> 0 --> 2 --> 1

*/

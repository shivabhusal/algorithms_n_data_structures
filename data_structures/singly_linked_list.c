#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node{
  int    data;
  struct Node* next;
};


struct Node* prepend(struct Node* oldHeadNode, int sperm){
  struct Node* newHeadNode = malloc(sizeof(struct Node));

  newHeadNode->data = sperm;
  newHeadNode->next = oldHeadNode;

  // After 9 months
  return newHeadNode;
}

struct Node* append(struct Node* parent, int sperm){
  struct Node* child = malloc(sizeof(struct Node));

  child ->data = sperm;
  parent->next = child;

  // After 9 months
  return child;
}


struct Node* findParentOf(struct Node* headNode, struct Node* targetNode){
  struct Node* tempPointer = headNode;
  while(tempPointer->next != targetNode){
    tempPointer = tempPointer->next;
  }
  return tempPointer;
}

//void retrieve();
void delete(struct Node* headNode, struct Node* targetNode){
  struct Node* parentNode = findParentOf(headNode, targetNode);

  // Establishing relnship between the nearby nodes.
  parentNode->next = targetNode->next;

  // Deleting the object to free the memory
  free(targetNode);
}

struct Node* insertAfter(struct Node* targetNode, int data){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = targetNode->next;
  targetNode->next = newNode;

  return newNode;
}

void testRunner();

void main(){
  testRunner();
}

void testRunner(){
  struct Node* headNode = malloc(sizeof(struct Node));
  headNode->data = 12;
  assert(headNode->data == 12);

  struct Node* node1 = append(headNode, 13);
  assert(node1->data == 13);
  assert(headNode->next   == node1);

  struct Node* node2 = append(node1, 14);
  assert(node2->data == 14);
  assert(node1->next == node2);

  // Delete Node1
  assert(findParentOf(headNode, node1) == headNode);
  assert(findParentOf(headNode, node2) == node1);

  delete(headNode, node1);
  assert(node1->data != 13);
  assert(headNode->next == node2);

  // Prepending nodes
  struct Node* oldHeadNode = headNode;
  headNode = prepend(headNode, 11);

  assert(headNode->next == oldHeadNode);
  assert(findParentOf(headNode, oldHeadNode) == headNode);

  // Insert operation
  struct Node* node3 = insertAfter(node2, 15);
  assert(node2->next == node3);
  assert(node2->next->data == 15);

}


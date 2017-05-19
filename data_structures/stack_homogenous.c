#include <stdio.h>
#include <assert.h>

#define SIZE 200
#define EMPTY_INDICATOR -1
#define TRUE 1
#define FALSE 0

typedef struct {
  int top;
  int items[SIZE];
} STACK;

void test_runner(void);
int push(STACK *, int);
int pop(STACK *);

void main(){
  test_runner();

}

int push(STACK *store, int data){
  if(store->top == SIZE){
    // StackOverflow detected;
    //  Instead you can throw an exception
    return FALSE;
  }else{
    store->items[++store->top] = data;
    return TRUE;
  }
}

int pop(STACK *store){
  if(store->top == EMPTY_INDICATOR){
    printf("Emtpty Stack detected!!!");

  }else{
    return(store->items[store->top--]);
  }
}

void test_runner(void){
  STACK store = {-1}; // will set top = -1 to indicate stack is empty
  assert(push(&store, 1) == TRUE);
  push(&store, 2);
  push(&store, 3);

  assert(pop(&store) == 3);
  assert(pop(&store) == 2);
  assert(pop(&store) == 1);

  STACK store2 = {200};
  assert(push(&store2, 12) == FALSE);
}


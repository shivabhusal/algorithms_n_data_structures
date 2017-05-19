#include <stdio.h>
#include <assert.h>

#define SIZE 200
#define EMPTY_INDICATOR -1

#define TRUE 1
#define FALSE 0

#define INT   1
#define FLOAT 2
#define STR   3


typedef struct{
  int etype;
  union{
    int   ival;
    char *sval; // Pointer to a string
    float fval;
  } element;
} STACK_ELEMENT;

typedef struct {
  int top;
  STACK_ELEMENT items[SIZE];
} STACK;

void test_runner(void);
int  push(STACK *, STACK_ELEMENT);
STACK_ELEMENT pop(STACK *);

void display(STACK_ELEMENT *);
void main(){
  test_runner();
  STACK store = {EMPTY_INDICATOR}; // will set top = -1 to indicate stack is empty

  STACK_ELEMENT int_data    = {INT,   {.ival = 1920}};
  STACK_ELEMENT float_data  = {FLOAT, {.fval = 22990.12}};
  STACK_ELEMENT string_data = {STR,   {.sval = "My name is shiva"}};
  
  assert(push(&store, int_data) == TRUE);
  assert(push(&store, float_data) == TRUE);
  assert(push(&store, string_data) == TRUE);
  
  /*
    Its a challenge to print the value to STDOUT
    because you will have to check which type of data it is
    and act accordingly
  */
  printf("The data is '");
  STACK_ELEMENT popped_data = pop(&store);
  display(&popped_data);
  printf("'\n");


  printf("The data is '");
  popped_data = pop(&store);
  display(&popped_data);
  printf("'\n");


  printf("The data is '");
  popped_data = pop(&store);
  display(&popped_data);
  printf("'\n");

}

void display(STACK_ELEMENT *data){
  if(data->etype == INT)
    printf("%d", data->element.ival);
  else if(data->etype == FLOAT)
    printf("%f", data->element.fval);
  else if(data->etype == STR)
    printf("%s", data->element.sval);
}

int push(STACK *store, STACK_ELEMENT data){
  if(store->top == SIZE-1){
    // StackOverflow detected;
    //  Instead you can throw an exception
    return FALSE;
  }else{
    store->items[++store->top] = data;
    return TRUE;
  }
}

STACK_ELEMENT pop(STACK *store){
  if(store->top == EMPTY_INDICATOR){
    printf("Emtpty Stack detected!!!");
  }else{
    return(store->items[store->top--]);
  }
}

void test_runner(void){
  STACK store = {EMPTY_INDICATOR}; // will set top = -1 to indicate stack is empty
  STACK_ELEMENT int_data    = {INT, 12};
  STACK_ELEMENT float_data  = {FLOAT, 12.12};
  STACK_ELEMENT string_data = {STR, {.sval="My name is shiva"}};

  assert(push(&store, int_data) == TRUE);
  assert(push(&store, float_data) == TRUE);
  assert(push(&store, string_data) == TRUE);

  assert(pop(&store).element.sval == string_data.element.sval);
  assert(pop(&store).element.fval == float_data.element.fval);
  assert(pop(&store).element.ival == int_data.element.ival);

  STACK store2 = {SIZE-1};
  assert(push(&store2, int_data) == FALSE);
}

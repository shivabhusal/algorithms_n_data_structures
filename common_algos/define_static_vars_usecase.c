#include <stdio.h>
#include "../cspec/cspec.c"

int * some_function(){
 static int fun_call_counter = 0;
 fun_call_counter++;

 return &fun_call_counter;
}

void main(){
 // `fun_call_counter` is not accessible here yet. And it does not make sense to even think about it
 //  because you cannot use that var `fun_call_counter` by name.

  printf("the function is called %d times\n", *(some_function()));
  printf("the function is called %d times\n", *(some_function()));
  printf("the function is called %d times\n", *(some_function()));
  printf("the function is called %d times\n", *(some_function()));
  printf("the function is called %d times\n", *(some_function()));
  printf("the function is called %d times\n", *(some_function()));
}

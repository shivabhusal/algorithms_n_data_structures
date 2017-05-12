/*
From this experiment we can conclude that; including files we are able to
use the global variables defined in another source file.

*/
#include <stdio.h>
#include "./extern/file1.c"

extern int  var_just_declared_but_not_allocated_with_memory;
int         var_declared_and_allocated_with_memory;  // but has garbage value

void main(){
  var_just_declared_in_another_file = 300;

  printf("value of `var_just_declared_in_another_file` is %d\n", var_just_declared_in_another_file);
  printf("value of `var_defined_in_another_file` is %d\n", var_defined_in_another_file);

  var_declared_and_allocated_with_memory++;
  
  /*
   The following line will throw compile time error
     "extern_variable.c:(.text+0x56): undefined reference to `var_just_declared_but_not_allocated_with_memory'"
  */
  // var_just_declared_but_not_allocated_with_memory++;
}

#include <stdio.h>
#include "../cspec/cspec.c"

// Withour this line, compiler wont compile your code.
// error: ‘a’ undeclared (first use in this function)
extern int some_var_declared_somewhere;

void test_runner(void);

void main(){
 printf("value of some_var_declared_somewhere is %d", some_var_declared_somewhere);
}

void test_runner(void){
 
}

// This var has no visibility in main() function
// because, its defined below main() function; so compiler has no idea
//  where and what it is. However, we can tell compiler that the var is 
//  defined somewhere in some of the source files; dont worry, for now compile the code.
int some_var_declared_somewhere = 10;

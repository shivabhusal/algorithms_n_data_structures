#include <stdio.h>
#include "optimized_insertion.c"
#include "../../cspec/cspec.c"

// Positive condition
void should_sort_the_given_array(void);

// Negative condition
void should_not_return_as_is(void);

void main(){
// Precondtion
should_sort_the_given_array();

// Postcondition
}

void should_sort_the_given_array(void){
 int array1[] = {1,5,6,7,7,9,4};
 int exp[] = {1,4,5,6,7,7,9};
 sort(array1, 7);
 assert_eq_int_array(exp, array1, 7, "{1,5,6,7,7,9,4} should be sorted as {1,4,5,6,7,7,9}");
 
 int array2[] = {123,3,4,6,7,2,3,4};
 int exp2[] = {2,3,3,4,4,6,7,123};
 sort(array2, 8);
 assert_eq_int_array(exp2, array2, 8, "{123,3,4,6,7,2,3,4} should be sorted as {2,3,3,4,4,6,7,123}");
 
 int array3[] = {1,2,3,4,0,-1,-2,-3};
 int exp3[] = {-3,-2,-1,0,1,2,3,4};
 sort(array3, 8);
 assert_eq_int_array(exp3, array3, 8, "{1,2,3,4,0,-1,-2,-3} should be sorted as {-3,-2,-1,0,1,2,3,4}");
 
}



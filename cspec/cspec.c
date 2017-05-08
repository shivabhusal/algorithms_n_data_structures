#include <stdio.h>

// Simple assertion to check if any logical expression is true;
void assert(char, char[]);
void cp_array(int[], int[], int);
void assert_eq_int_array(int[], int[], int, char message[]);
void print_array(int [], int);

void assert(char result, char message[]){
  if(result != 1){
    printf("%s --> FAILED\n", message);
  }else{
    printf("%s --> PASSED\n", message);    
  }
}

void assert_eq_int_array(int expectation[], int reality[], int len, char message[]){
  int i;
  for(i=0; i<len; i++){
   if(expectation[i] != reality[i]){
    printf("%s --> FAILED\n", message);
    printf("The outcome: ");
    print_array(reality, len);
    break;
   }
  }

  if(i == len){
    printf("%s --> PASSED\n", message); 
  }
  
  printf("\n----------------------------------------------------------------------------------\n");
}

void cp_array(int source[], int dest[], int len){
 for(int i=0; i < len; dest[i++] = source[i-1]);
}

void print_array(int arr[], int len){
 for(int i=0; i<len-1; i++){
  printf("%d,", arr[i]);
  }
 printf("%d", arr[len-1]);
}


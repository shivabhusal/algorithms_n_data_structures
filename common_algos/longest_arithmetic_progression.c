#include <stdio.h>
#include <stdlib.h>

void assert_eq_int_array(int expectation[], int reality[], int len, char message[]);
void print_array(int arr[], int len);
void cp_array(int source[], int dest[], int len);
void test_runner();

typedef struct {
  int* array;
  int length;
} Result;

Result* findAP(int* array, int len);


void main() {
    int *array, i, num, diff;
    
    printf("Enter the size of an array \n");
    scanf("%d", &num);
    
    array = malloc(sizeof(int)*num);
    
    printf("Enter the elements of the array\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }
    
    Result* result = findAP(array, num); 
    printf("From the array: ");
    print_array(array, num);
    
    printf("\nThe Longest Arithmetic Progression is: ");
    print_array(result->array, result->length);

    // Note: Activate this if you wish to run the test-suite
    // test_runner();
}

Result* findAP(int* array, int len){
    int* largest = malloc(sizeof(int)*len);
    int largestLen = 0;
    
    int temp[len];
    int lengthTemp = 0;
    
    for(int i=1; i< len-1; i++){
      int lastDiff = array[i-1] - array[i];
      int diff1 = array[i] - array[i+1];
      if(diff1 == lastDiff ){
          temp[lengthTemp] = array[i-1];
          temp[lengthTemp+1] = array[i];
          temp[lengthTemp+2]   = array[i+1];
          lengthTemp++;
          if((i == len -2) && largestLen < lengthTemp){
            cp_array(temp, largest, len);
            largestLen = lengthTemp;
          }
          
      }else{
        if(largestLen < lengthTemp){
          cp_array(temp, largest, len);
          largestLen = lengthTemp;
        }
        lengthTemp = 0;
      }
    }
    
    Result* result = malloc(sizeof(Result));
    result->array  = largest;
    result->length =  largestLen + 2;
    return result;
}

void test_runner(){
  int array[] = {5,1,2,4,6,8,12,16};
  int size = sizeof(array)/sizeof(array[0]);
  int exp[] = {2,4,6,8};
  
  assert_eq_int_array(exp,findAP(array, size)->array, 4, "Should be equal");
  
  
  int array1[] = {5,1,2,4,6,8,10,12,16};
  int size1 = sizeof(array1)/sizeof(array1[0]);
  int exp1[] = {2,4,6,8,10,12};
  
  assert_eq_int_array(exp1,findAP(array1, size1)->array, 6, "Should be equal");


  int array2[] = {5,1,2,4,6,8,12,16,20,24,28};
  int size2 = sizeof(array2)/sizeof(array2[0]);
  int exp2[] = {8,12,16,20,24,28};
  
  assert_eq_int_array(exp2,findAP(array2, size2)->array, 6, "Should be equal");

}

void cp_array(int source[], int dest[], int len){
  for(int i=0; i < len; dest[i++] = source[i-1]);
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
}

void print_array(int arr[], int len){
  printf("\n");
  for(int i=0; i<len-1; i++){
    printf("%d,", arr[i]);
  }
  printf("%d\n", arr[len-1]);
}

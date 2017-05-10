/*
n = 6
6! -->  5!*6
5! --> 4!*5

n! --> n*(n-1)!


-->
0,1,1,2,3,5,8,13,21.....
a=0' b=1

*/

#include <stdio.h>
void fibo(int,int);
void print_array(int[],int);
int seq[10] ={0,1};

void main(){
 int n=10;

 fibo(2, n);
 print_array(seq, n);
}

void fibo(int index,  int n){
 if(index < n){
  seq[index] = seq[index-1] + seq[index - 2];
  fibo(++index, n);
 }
}

void print_array(int arr[], int n){
 int i;
 for(i=0; i< n-1; i++){
   printf("%d, ", arr[i]);
  }

  printf("%d", arr[i]);
}


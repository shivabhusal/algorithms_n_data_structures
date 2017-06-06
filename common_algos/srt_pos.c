#include <stdio.h>
#include "../cspec/cspec.c"

int strpos(char [], char []);
int strlen(char []);

void test_runner(void);

void main(){
  test_runner();
}

int strpos(char str1[], char str2[]){
  
  char flag = 0;
  int  str2_len = strlen(str2);

  for(int i=0; str1[i] != '\0'; i++){
    if(str1[i] == str2[flag]){
      if(flag  == str2_len - 1){
        return(i - flag); 
      }
      flag++;
    }else{
      flag = 0;
    }

  }
  return -1;

}

void test_runner(){
  char str1[] = "my name is shiva";

  assert(strpos(str1, "is") ==  8, "Pos of 'shiva' should be 8");
  assert(strpos(str1, "hari") ==  -1, "Pos of 'hari' should be -1");
  assert(strpos(str1, "my") ==  0, "Pos of 'my' should be 0");


  assert(strpos(str1, "sheva") ==  -1, "Pos of 'sheva' should be -1");
  assert(strpos(str1, "s") ==  9, "Pos of 'my' should be 9");
  assert(strpos(str1, "neme") ==  -1, "Pos of 'neme' should be -1");

}

int strlen(char str[]){
  int i;
  for(i=0; str[i] != '\0'; i++);
  return i;
}

#include <stdio.h>
#include "../cspec/cspec.c"

int strrev(char []);

void test_runner(void);

void main(){
  test_runner();
}

int strrev(char str[]){
  int len = strlen(str);
  int mid_of_string = len/2;

  for(int i=0; i < mid_of_string; i++){
    char tmp = str[i];
    str[i] = str[len - i - 1];
    str[len - i- 1] = tmp;
  }
}

void test_runner(){
  char str1[] = "shiva";
  char str2[] = "madam";
  char str3[] = "1234567";

  strrev(str1);
  assert_eq_string(str1, "avihs", "'shiva' should be reversed as 'avihs'");
  assert_eq_string(str2, "madam", "'madam' should be reversed as 'madam'");
  assert_eq_string(str3, "1234567", "'1234567' should be reversed as '7654321'");

}

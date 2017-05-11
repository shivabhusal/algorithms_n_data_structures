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
  strrev(str2);
  strrev(str3);

  assert_eq_string("avihs", str1, "'shiva' should be reversed as 'avihs'");
  assert_eq_string("madam", str2, "'madam' should be reversed as 'madam'");
  assert_eq_string("7654321", str3, "'1234567' should be reversed as '7654321'");

}

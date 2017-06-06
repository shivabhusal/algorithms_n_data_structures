#include <stdio.h>
void strcpy(char *, char *);
void main(){
 char s1[10] = "my name is";
 char s2[10];
 strcpy(s1, s2);
 printf("%s", s2);
}

void strcpy(char *s1, char *s2){
 while(*s2++ = *s1++);
}

void strcpy_v2(char s1[], char s2[]){
  for(int i=0; s1[i] != '\0'; s2[i++]=s1[i-1]);
}

//Author  	:Shiva Bhusal
//blog    	:cbabhusal.wordpress.com
//twitter 	:@shivabhusal
//stackoverflow :illusionist

#include <stdio.h>
#include <stdlib.h>
void strcat(char *, char *, int, int);
void main()
{
 char s1[] = "my name is ";
 char s2[] =  "shiva";
 int len1 = sizeof(s1)/sizeof(s1[0]);
 int len2 = sizeof(s2)/sizeof(s2[0]);
 strcat(s1, s2, len1, len2);

 printf("%s", s1);
}

void strcat(char *s1, char *s2, int len1, int len2){
   char *tmp = realloc(s1, len1+len2);
   if(!tmp){
    printf("Sorry could not reallocate memory");
   }else{
   s1 += len1;
	 printf("%c", *s2);
   while(*s1++ = *s2++);
  }

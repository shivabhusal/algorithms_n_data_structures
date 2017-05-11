#include <stdio.h>

void calc(char *text, int *wc, int*lc, int*alpha_c);

void main(){
  char text[100];
  int wc=0, lc=0, alpha_c=0;
  printf("Please enter the text:\n");
  scanf("%[^\t]s", text);
  calc(text, &wc, &lc, &alpha_c);

  printf("The word count is %d, line count is %d and alpha-count is %d", wc, lc, alpha_c);
}

void calc(char *text, int *wc, int *lc, int *alpha_c){
  int flag = 0;
  for(int i=0; text[i] != '\0'; i++){

	// resusable boolean expression
	//  this can also be defined as Symbolic Constand and reused; but it would have to be 
  	//  evaluated multiple times
        char is_alpha = (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A'&& text[i] <= 'Z');

	if(is_alpha){
	 ++*alpha_c;
	}

	if(text[i] == '\n')
	  ++*lc;

	// Verify the word and increment the counter
	if(flag ==1 && (text[i] == ' ' || text[i] == '\n' || text[i+1] == '\0')){
	  ++(*wc);
	  flag =0;
	}

	// Reactivate the flag that indicates the beginning of a word has been detected
	if(flag == 0 &&  is_alpha )
	 flag =1;

  }
}

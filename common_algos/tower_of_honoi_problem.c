#include <stdio.h>
#define RINGS 3
void push(int, int [], int *);
int pop(int [], int*);

int rod1[] = {3,2,1};
int rod2[RINGS];
int rod3[RINGS];
int i1 = (RINGS -1) , i2 = -1, i3 = -1;
void main(){
 push(13, rod1, &i1);
 printf("the last item is %d: and index is %d", rod1[3], 3);
}

void push(int val, int stack[], int *index){
// *index +=1;
 stack[(++*index)] = val;
 printf("the index is %d\n", *index);

}

int pop(int stack[], int *index){
int val = stack[*index];
*index--;
return(val);
}
//void mover

//					
//				
//					a(0)
//	4		a(2)		a(1)
//   _______	    _________      ___________

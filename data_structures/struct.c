 1 #include <stdio.h>
 2 #include <string.h>
 3 void main(){
 4 struct address {
 5   char state[30];
 6   char city[20];
 7   char street[30];
 8   char zip[20];
 9 };
10 
11 struct address bill_add, ship_add;
12 
13 strcpy(bill_add.state, "Bagmati");
14 strcpy(bill_add.city, "Kathmandu");
15 strcpy(bill_add.street, "Bagbazar");
16 strcpy(bill_add.zip, "48234");
17
18 printf("State: %s, city: %s, street: %s, zip: %s",
19     bill_add.state,
20     bill_add.city,
21     bill_add.street,
22     bill_add.zip);
23  
24 }


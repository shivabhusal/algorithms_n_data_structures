#include <stdio.h>
#include <string.h>

typedef struct date{
  int year;
  int month;
  int day;
}DATE;

typedef struct time{
  int hour;
  int minute;
  int second;
  char zone[50];
} TIME;


typedef struct {
  DATE date;
  TIME time;
  long int timestamp;
} DATETIME;

DATETIME modify_by_value(DATETIME);
void modify_by_reference(DATETIME *);

//---------------------------------------------------------------------------------------------------------------
void main(){
  struct address {
    char state[30];
    char city[20];
    char street[30];
    char zip[20];
  };

  struct some_strc{
    int first_val;
    int sec_val;
  } new_number = {12, 13};

  struct address bill_add;

  // One type of value assignment
  strcpy(bill_add.state, "Bagmati");
  strcpy(bill_add.city, "Kathmandu");
  strcpy(bill_add.street, "Bagbazar");
  strcpy(bill_add.zip, "48234");

  printf("State: %s, city: %s, street: %s, zip: %s",
      bill_add.state,
      bill_add.city,
      bill_add.street,
      bill_add.zip);



  // Another type of value assignment
  DATE dob       = {1990, 06, 07};
  TIME now       = {12, 43, 45};
  DATETIME today = {{1990, 06, 07}, {12,43, 45, "Kathmandu"}, 123441234};

  printf("\nToday is %d/%d/%d and now its %d:%d:%d [%s]",
      today.date.year,
      today.date.month,
      today.date.day,
      today.time.hour,
      today.time.minute,
      today.time.second,
      today.time.zone);


  DATETIME new_today = modify_by_value(today);
  printf("\nToday is %d/%d/%d and now its %d:%d:%d [%s]",
      new_today.date.year,
      new_today.date.month,
      new_today.date.day,
      new_today.time.hour,
      new_today.time.minute,
      new_today.time.second,
      new_today.time.zone);


  modify_by_reference(&today);
  printf("\nToday is %d/%d/%d and now its %d:%d:%d [%s]",
      today.date.year,
      today.date.month,
      today.date.day,
      today.time.hour,
      today.time.minute,
      today.time.second,
      today.time.zone);

}

// Passing by value
DATETIME modify_by_value(DATETIME new_date){
  new_date.time.hour = 23;
  new_date.time.minute = 24;
  new_date.time.second = 25;

  return new_date;
}

void modify_by_reference(DATETIME *ptr_to_date){
  ptr_to_date->time.hour   = 02;
  ptr_to_date->time.minute = 03;
  ptr_to_date->time.second = 04;

  // You cannot simply do this
  //   ptr_to_date->time.zone, "Sydney Australia";
  strcpy(ptr_to_date->time.zone, "Sydney Australia");
}

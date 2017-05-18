int var_just_declared_in_another_file;  // allocated with memory; but has garbage value
int var_defined_in_another_file = 200;  // allocated and initialized with value `200`

void some_funtion();
void some_funtion(){
  extern int some_extern_var;

}

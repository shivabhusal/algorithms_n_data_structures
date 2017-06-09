# algorithms
## Intent
I wish to include as more algoritms and DataStructure implementations as possible. I need your aid because it should be a community effor. Anybody can be benifited from this repository.  

Contains common algorithms and DS implementation in various languages like C, Ruby, etc.

# Requirements
This library uses `CSpec` testing Framework to write testcases. The CSpec is a new concept, we are planning to
take this project forward and extract out as a separate library. For simpler assertion we are using `assert.h` library though. 

### Installation
For implementations libraries
In your test.c
```c
// If your file is at /sorting/algo_spec.c then
// include `cspec.c` if you wish to assert using methods defined in that library
#include '../../cspec/cspec.c'
// assuming like algorithms/cspec/cspec.c
```

And finally
```sh
# .out for linux users, .exe for windows users
$ gcc  -o test.out test_spec.c

# To execute
$ ./test.out
```

# Contributions
You are welcome to ask questions and create pull requests. Feel free to create pull requests for the following:-  
- You feel to add any missing implementation of any DS or algorithms
  - must include documentations and useful links along with it
  - code must be well aligned, covered with **test-cases** and commented
- You wish to correct any mistakes
- You wish to add documentations
- You wish to optimize code already existing

# License ( MIT )
See this [MIT License](https://opensource.org/licenses/MIT)

---

Copyright Shiva Bhusal(c) 2017

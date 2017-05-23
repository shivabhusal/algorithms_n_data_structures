# algorithms
Contains all common algorithm theories and implementation in various languages like C, Ruby, etc

# Requirements
This library uses `CSpec` testing Framework to write testcases. The CSpec is a new concept, we are planning to
take this project forward and extract out as a separate library.

### Installation
In your test.c
```c
// If your file is at /sorting/algo_spec.c then
#include '../../cspec/cspec.c'
// assuming like algorithms/cspec/cspec.c
```

And finally
```bash
gcc  -o test.out test_spec.c
```

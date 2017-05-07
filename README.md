# algorithms
Contains all common algorithm theories and implementation in various languages like C, Ruby, etc

# Requirements
This library uses `CUnit` testing Framework to write testcases.
### Installation

```
sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
```

Then in your test.c
```c
#include <CUnit/CUnit.h>
```
And finally, you must add the flag –lcunit to the gcc command (at the end)
```bash
gcc  -o test test.c  -lcunit
```

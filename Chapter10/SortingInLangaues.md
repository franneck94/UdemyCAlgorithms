# What programming languages do use what sorting algorithm?

## C and C# - Quicksort

C example:

```c
    #include <stdlib.h>

    qsort(....);
```

## C++ and Javascript - IntroSort

The algorithm used by sort() is IntroSort. Introsort being a hybrid sorting algorithm uses three sorting algorithm to minimise the running time, Quicksort, Heapsort and Insertion Sort

C++ example:

```cpp
    #include <algorithm>

    std::sort(....);
```

## Java and Python - Timsort

Timsort is a hybrid sorting algorithm, derived from merge sort and insertion sort, designed to perform well on many kinds of real-world data.

Python example:

```python
    l = [1, -1, 2]
    l.sorted()
```

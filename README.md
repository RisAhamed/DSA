# DSA

## Array

### Easy

- [Find the element that appears once in an array where every other element appears twice](array/Easy/find_element_that_appear_once.cpp)

- [Find the missing number in an array](array/Easy/find_missing_number.cpp)

- [left rotate an array by one place](array/Easy/left_rotate_d_place.cpp)

- [maximum_consecutive_ones](array/Easy/maximum_consecutive_ones.cpp)

- [move_zeros_to_end](array/Easy/move_zeros_to_end.cpp)

- [union of two sorted arrays](array/Easy/union_of_two_sorted_arrays.cpp)

- [intersection of two sorted arrays](array/Easy/intersection_of_two_sorted_arrays.cpp)


## Medium

- [two sum](array/Medium/two_sum.cpp)

- [element appear more than half](array/Medium/element_appear_morethan_half.cpp)

- [sort an array of 0s, 1s and 2s](array/Medium/sort_an_array_of_0s_1s_and_2s.cpp)

- [sort an array of 0s, 1s and 2s](array/Medium/sort_an_array_of_0s_1s_and_2s.cpp)

- [Kadane's Algorithm Maximum Subarray Sum Array](array/Medium/Kadane's_Algorithm_Maximum_Subarray_Sum_Array.cpp)

- [buy sell stocks](array/Medium/buy_sell_stocks.cpp)

- [buy sell stocks optimal](array/Medium/buy_sell_stocks_optimal.cpp)

- [next permutation](array/Medium/next_permutation.cpp)
# Next Permutation Algorithm

## Overview
This repository provides an implementation of the **Next Permutation** algorithm in C++. The algorithm rearranges a sequence of numbers into the next lexicographical permutation. If such a permutation does not exist, it rearranges the numbers into the lowest possible order (i.e., sorted in ascending order).

---

## Code Explanation
The function follows these main steps:

### 1. Find the Breakpoint:
The **breakpoint** is the rightmost index `i` where `a[i] < a[i+1]`. This indicates the position where the order starts breaking from being in descending order. 

#### Why start from `n-2`?
The loop starts at `n-2` because:
- To find the breakpoint, we need to compare `a[i]` with `a[i+1]`.
- Starting from `n-1` would not allow a valid comparison as `a[n]` does not exist.

#### Workflow of the First Loop:
- Start at index `n-2` and move backward to 0.
- For each index `i`, check if `a[i] < a[i+1]`.  
- If found, this index is the **breakpoint** (`index = i`).  
- If no such `i` is found (`index = -1`), the array is the last permutation, and we reverse it to get the smallest permutation.

### 2. Find the Next Greater Element:
From the end of the array, find the smallest element greater than `a[index]`. This ensures the permutation is as close as possible to the original.

#### Workflow of the Second Loop:
- Start at `n-1` and move backward to `index + 1`.
- Find the first element `a[j]` such that `a[j] > a[index]`.
- Swap `a[index]` and `a[j]`.

### 3. Reverse the Right Half:
Reverse the portion of the array after `index` (`a[index+1:]`) to get the smallest lexicographical order for this section. 

#### Why reverse?
Reversing ensures that the sequence after `index` is in ascending order, forming the next permutation.

---



# Next Permutation Algorithm

## Example Workflows with All Conditions

---

### Example 1: Array has a valid next permutation
#### Input:
```cpp
a = [1, 3, 5, 4, 2], n = 5
```

#### Steps:
1. **Find the Breakpoint:**
   - Start from `i = 3` (n-2):
     - Compare `a[3] = 4` and `a[4] = 2` → No breakpoint.
   - Move to `i = 2`:
     - Compare `a[2] = 5` and `a[3] = 4` → No breakpoint.
   - Move to `i = 1`:
     - Compare `a[1] = 3` and `a[2] = 5` → Breakpoint found at `index = 1`.

2. **Find the Next Greater Element:**
   - Start from `j = 4` (n-1):
     - `a[4] = 2` is not greater than `a[1] = 3`.
     - `a[3] = 4` is greater than `a[1] = 3`.
   - Swap `a[1]` and `a[3]`:  
     `a = [1, 4, 5, 3, 2]`.

3. **Reverse the Right Half:**
   - Reverse `[5, 3, 2]` → `[2, 3, 5]`.
   - Final array:  
     `a = [1, 4, 2, 3, 5]`.

#### Output:
```cpp
[1, 4, 2, 3, 5]
```

---

### Example 2: Array is the last permutation
#### Input:
```cpp
a = [5, 4, 3, 2, 1], n = 5
```

#### Steps:
1. **Find the Breakpoint:**
   - Start from `i = 3` (n-2):
     - Compare `a[3] = 2` and `a[4] = 1` → No breakpoint.
   - Move to `i = 2`: Compare `a[2] = 3` and `a[3] = 2` → No breakpoint.
   - Move to `i = 1`: Compare `a[1] = 4` and `a[2] = 3` → No breakpoint.
   - Move to `i = 0`: Compare `a[0] = 5` and `a[1] = 4` → No breakpoint.
   - No breakpoint found (`index = -1`).

2. **Reverse the Array:**
   - Reverse `[5, 4, 3, 2, 1]` → `[1, 2, 3, 4, 5]`.

#### Output:
```cpp
[1, 2, 3, 4, 5]
```

---

### Example 3: Array has only one element
#### Input:
```cpp
a = [1], n = 1
```

#### Steps:
1. **Find the Breakpoint:**
   - No comparison is needed as the array has only one element.
   - No breakpoint found (`index = -1`).

2. **Reverse the Array:**
   - Reverse `[1]` → `[1]`.

#### Output:
```cpp
[1]
```

---

### Example 4: Array has all identical elements
#### Input:
```cpp
a = [2, 2, 2], n = 3
```

#### Steps:
1. **Find the Breakpoint:**
   - Start from `i = 1` (n-2):
     - Compare `a[1] = 2` and `a[2] = 2` → No breakpoint.
   - Move to `i = 0`: Compare `a[0] = 2` and `a[1] = 2` → No breakpoint.
   - No breakpoint found (`index = -1`).

2. **Reverse the Array:**
   - Reverse `[2, 2, 2]` → `[2, 2, 2]`.

#### Output:
```cpp
[2, 2, 2]
```
```
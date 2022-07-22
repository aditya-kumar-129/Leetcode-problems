//Find maximum between two numbers.
int max(int num1, int num2)
{
  return (num1 > num2) ? num1 : num2;
}

// Find minimum between two numbers.
int min(int num1, int num2)
{
  return (num1 > num2) ? num2 : num1;
}

// This function swaps values pointed by xp and yp
void swap(int* xp, int* yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// qsort function in c
// https://iq.opengenus.org/qsort-in-c/
// Compare function for qsort
int cmpfunc(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

// qsort(values, 5, sizeof(int), cmpfunc);

// This code is contributed by Aditya Kumar (adityakumar129)
// Node * root = (Node *)malloc(sizeof(Node));

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <string.h>

// This code is contributed by Sania Kumari Gupta
// Added the code in c++ language for the first method

// TO edit 
// predict() in python https://www.askpython.com/python/examples/python-predict-function
// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
// https://www.geeksforgeeks.org/find-a-rotation-with-maximum-hamming-distance/
// https://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/
// https://www.geeksforgeeks.org/stdnext-in-cpp/   replace operator - by operator --
// https://www.geeksforgeeks.org/tiling-problem/
// https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/
// https://www.geeksforgeeks.org/tiling-with-dominoes/
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <stdio.h>
#include <math.h>

#include<iostream>

using namespace std;

//inclusive of startIndex and endIndex
int* createNewArr(int* arr, int startIndex, int endIndex) {

  int newArray[endIndex - startIndex + 1];
  int newIndex = 0;

  for(int i = startIndex; i <= endIndex; i++)
    newArray[newIndex++] = arr[i];

  return newArray;
}

int returnIndex(int* arr, int n, int size) {
  int newStartIndex = 0;
  int newEndIndex = 0;
  int middle = (int)ceil(size / 2);

  if(size == 1) {
    if(arr[0] != n)
      return -1;
    else
      return n;
  }

  if(arr[middle] == n) {
    return size / 2;
  } else if(arr[middle] >  n) {//if halfway is bigger than n
    newStartIndex = 0;
    newEndIndex = middle - 1;
  } else if(arr[middle] < n) {//if halfway is smaller than n
    newStartIndex = middle + 1;
    newEndIndex = size - 1;
  }

  return returnIndex(createNewArr(arr, newStartIndex, newEndIndex), n, newEndIndex - newStartIndex + 1);
}

int atoi(char a) {
  return (int)(a - 48);
}

int main(int argc, char* argv[]) {

  if(argc < 2) {
    printf("Missing integer parameter. Exiting.\n\n");
    exit(100);
  }

  int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int size = sizeof(arr)/sizeof(arr[0]);

  int index = returnIndex(arr, atoi(*argv[1]), size);

  if(index == -1) {
    printf("Integer not found.");
  } else {
    printf("%d\n\n", index);
  }
}

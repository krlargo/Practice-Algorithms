import java.lang.System.*;
import java.util.*;

public class MergeSort {
  private static int size = 10;
  private static int[] arr = new int[]{54, 72, 1, 24, 56, 78, 15, 76, 8, 10};

  private static void printArray(int arr[], int size) {
    if(size == 0)
      return;

    for(int i = 0; i < size; i++) {
      if(i == 0)
        System.out.print("{");
      else
        System.out.print(", ");
      System.out.print(arr[i]);
    }
    System.out.println("}");
  }

  //inputs start and end refer to index
  private static int fillArray(int source[], int dest[], int startIndex, int endIndex) {
    int i, j = startIndex;
    for(i = 0; i < endIndex - startIndex + 1; i++)
      dest[i] = source[j++];

    return i;
  }

  private static void mergeSort(int arr[], int size) {
    if(size == 0) {
      System.out.println("Array has no elements.");
      return;
    }

    if(size == 1)
      return;

    int middle = size / 2;

    int[] left = new int[middle];
    int[] right = new int[size - middle];

    int leftSize = fillArray(arr, left, 0, middle - 1);
    int rightSize = fillArray(arr, right, middle, size - 1);

    printArray(left, leftSize);
    printArray(right, rightSize);

    mergeSort(left, leftSize);
    mergeSort(right, rightSize);


    int i = 0, j = 0, k = 0;
    for(k = 0; k < size && (!(i == leftSize || j == rightSize)); k++) {
      if(left[i] < right[j])
        arr[k] = left[i++];
      else
        arr[k] = right[j++];
    }

    if(i == leftSize) {
      while(j != rightSize)
        arr[k++] = right[j++];
    } else if(j == rightSize) {
      while(i != leftSize)
        arr[k++] = left[i++];
    }
  }

  public static void main(String[] args) {
    printArray(arr, size);

    mergeSort(arr, size);

    printArray(arr, size);
  }

}

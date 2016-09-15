import java.lang.System.*;
import java.util.*;

public class MergeSort {
  private static int size = 10;
  private static int[] arr = new int[]{2, 4, 6, 8, 10, 1, 3, 5, 7, 9};

  private static void printArray(int arr[], int size) {
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
  }

  public static void main(String[] args) {
    printArray(arr, size);

    mergeSort(arr, size);
  }

}

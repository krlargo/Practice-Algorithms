import java.lang.System.*;
import java.util.*;

public class MergeSort {
  private static int size = 10;
  private static int[] arr = new int[]{2, 4, 6, 8, 10, 1, 3, 5, 7, 9};

  private static void printArray(int arr[], int size) {
    System.out.println("Main.");
    for(int i = 0; i < size; i++) {
      if(i == 0)
        System.out.print("{");
      else
        System.out.print(", ");
      System.out.print(arr[i]);
    }
    System.out.println("}");
  }

  public static void main(String[] args) {
    printArray(arr, size);
  }

}

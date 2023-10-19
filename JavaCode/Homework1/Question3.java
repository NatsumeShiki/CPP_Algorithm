package JavaCode.Homework1;

import java.io.*;
import java.util.*;

public class Question3{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  public static void main(String[] args) {
    
    FileInputStream fis = null;
    PrintStream ps = null;
    try {
      fis = new FileInputStream(INPUT);
      ps = new PrintStream(new FileOutputStream(OUTPUT));
      System.setIn(fis);
      System.setOut(ps);
    } catch (Exception e) {
      System.out.println("Error Occurred.");
    }
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] arr = new int[n];
    for(int i = 0; i < n; i++){
      arr[i] = sc.nextInt();
    }

    int resMin = divideMin(arr, 0, n - 1);
    int resMax = divideMax(arr, 0, n - 1);

    System.out.println("max = " + resMax + ", min = " + resMin);

    sc.close();
  }

  public static int divideMax(int[] arr, int l, int r){
    if(l == r) return arr[l];
    int mid = l + r >> 1;
    return Math.max(divideMax(arr, l, mid), divideMax(arr, mid + 1, r));
  }
  
  public static int divideMin(int[] arr, int l, int r){
    if(l == r) return arr[l];
    int mid = l + r >> 1;
    return Math.min(divideMin(arr, l, mid), divideMin(arr, mid + 1, r));
  }
}
// 10
// 45 12 35 48 68 19 65 85 51 34
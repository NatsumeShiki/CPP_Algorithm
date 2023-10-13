package JavaCode.Experiment1;

import java.io.*;
import java.util.*;

public class Question5{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int n;
  static int res;
  static int[] arr = new int[30];

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

    n = sc.nextInt();
    dfs(n, n, 0);
    System.out.println(res);

    sc.close();
  }

  public static void dfs(int n, int last, int u){
    if(n == 0){
      for(int i = 0; i < u; i++){
        System.out.print(arr[i] + " ");
      }
      System.out.println();
      res++;
      return;
    }

    // System.out.println(n + " " + last + " " + u);

    for(int i = Math.min(n, last); i >= 1; i--){
      arr[u] = i;
      dfs(n - i, i, u + 1);
    }
  }
}

// 30
package JavaCode.Experiment1;

import java.io.*;
import java.util.*;

public class Question3{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int n = 9;
  static int[] arr = new int[n];
  static boolean[] st = new boolean[10];
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

    dfs(0);

    sc.close();
  }

  public static void dfs(int u){
    if(u == 9){
      int a = arr[0] * 10 + arr[1], b = arr[2] * 100 + arr[3] * 10 + arr[4],
      c = arr[5] * 1000 + arr[6] * 100 + arr[7] * 10 + arr[8];
      if(a * b == c){
        System.out.println(a + " * " + b + " = " + c);
      }

      return;
    }

    for(int i = 1; i <= 9; i++){
      if(st[i]) continue;
      arr[u] = i;
      st[i] = true;
      dfs(u + 1);
      st[i] = false;
    }
  }
}

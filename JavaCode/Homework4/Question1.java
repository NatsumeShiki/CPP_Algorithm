package JavaCode.Homework4;

import java.io.*;
import java.util.*;

public class Question1{
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

    int n = sc.nextInt(), V = sc.nextInt();
    int[] v = new int[n + 1], w = new int[n + 1];
    int[] f = new int[V + 1];
    for(int i = 1; i <= n; i++){
      v[i] = sc.nextInt();
      w[i] = sc.nextInt();
    } 

    // for(int i = 1; i <= n; i++){
    //   for(int j = 0; j <= V; j++){
    //     f[i][j] = f[i - 1][j];
    //     if(j >= v[i]) f[i][j] = Math.max(f[i][j], f[i - 1][j - v[i]] + w[i]);
    //   }
    // }

    for(int i = 1; i <= n; i++){
      for(int j = V; j >= v[i]; j--){
        f[j] = Math.max(f[j], f[j - v[i]] + w[i]);
      }
    }

    System.out.println(f[V]);

    sc.close();
  }
}

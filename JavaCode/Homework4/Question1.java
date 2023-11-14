package JavaCode.Homework4;

import java.io.*;
import java.util.*;

public class Question1{
  static int n, V;
  static int[] v, w;
  static int[][] f;
  static int res = 0;
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

    n = sc.nextInt();
    V = sc.nextInt();
    v = new int[n + 1];
    w = new int[n + 1];
    f = new int[n + 2][V + 1];
    for(int i = 1; i <= n; i++){
      v[i] = sc.nextInt();
      w[i] = sc.nextInt();
    } 


    dp();
    System.out.println("动态规划：" + f[n][V]);

    dfs(0, V, 0);
    System.out.println("递归：" + res);

    sc.close();
  }
 
  public static void dp(){
    for(int i = 1; i <= n; i++){
      for(int j = 0; j <= V; j++){
        f[i][j] = f[i - 1][j];
        if(j >= v[i]) f[i][j] = Math.max(f[i][j], f[i - 1][j - v[i]] + w[i]);
      }
    }

    for(int i = 1; i <= n; i++){
      for(int j = V; j >= v[i]; j--){
        f[j] = Math.max(f[j], f[j - v[i]] + w[i]);
      }
    }
  }

  public static void dfs(int u, int capacity, int ans){
    if(u == n){
      res = Math.max(res, ans);
      return;
    }
    
    dfs(u + 1, capacity, ans);
    if(capacity >= v[u]){
      dfs(u + 1, capacity - v[u], ans + w[u]);
    }
  }
  
}

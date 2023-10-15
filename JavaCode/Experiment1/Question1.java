package JavaCode.Experiment1;

import java.io.*;
import java.util.*;

public class Question1{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";
  static int n = 9;
  static int[] arr = new int[n];
  static int[] x = new int[1], y = new int[1];
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

    int T = sc.nextInt();
    while(T-- > 0){
      for(int i = 0; i < n; i++){
        arr[i] = sc.nextInt();
      }
      int res = dfs1();
      if(res == -1) System.out.println("无解");
      else System.out.println(res);
      res = dfs2();
      if(res == -1) System.out.println("无解");
      else System.out.println(res);
    }

    sc.close();
  }

  // 蛮力法
  public static int dfs1(){
    for(int i = 0; ; i++){
      boolean flag = true;
      for(int j = 0, k = 10; j < n; j++, k--){
        if(i % k != arr[j]){
          flag = false;
          break;
        }
      }
      if(flag) return i;
    }
  }


  public static int dfs2(){
    x[0] = y[0] = 0;
    boolean flag = true;
    int a1 = 10, b1 = arr[0];
    for(int i = 1; i < n; i++){
      int a2 = 10 - i, b2 = arr[i];
      int d = exgcd(a1, a2, x, y);
      if((b2 - b1) % d != 0){
        flag = false;
        break;
      }

      x[0] *= (b2 - b1) / d;
      int t = a2 / d;
      x[0] = (x[0] % t + t) % t;
      b1 = a1 * x[0] + b1;
      a1 = Math.abs(a1 / d * a2);
    }
    if(flag) return (b1 % a1 + a1) % a1;
    return -1;
  }

  public static int exgcd(int a, int b, int[] x, int[] y){
    if(b == 0){
      x[0] = 1;
      y[0] = 0;
      return a;
    }
    int d = exgcd(b, a % b, y, x);
    y[0] -= a / b * x[0];
    return d;
  }
}

// 3
// 9 3 3 0 3 4 3 0 1
// 3 1 3 0 1 3 3 1 1
// 0 0 0 0 0 0 0 0 0
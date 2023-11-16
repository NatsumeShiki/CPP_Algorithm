package JavaCode.Experiment1;

import java.io.*;
import java.util.*;

public class Lab1{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static Scanner sc;
  static int n, m;
  static int[] arr1;
  static int[] x, y;
  static int[][] arr2;
  static int[] arr3 = new int[10];
  static boolean[] st = new boolean[10];
  static int res;
  static int[] arr5 = new int[30];

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
    sc = new Scanner(System.in);

    System.out.println("第一题：");
    Method1();
    System.out.println("\n第二题：");
    Method2();
    System.out.println("\n第三题：");
    Method3();
    System.out.println("\n第四题：");
    Method4();
    System.out.println("\n第五题：");
    Method5();

    sc.close();
  }

  public static void Method1(){
    int T = sc.nextInt();
    n = 9;
    arr1 = new int[n];
    x = new int[1];
    y = new int[1];
    for(int t = 1; t <= T; t++) {
      System.out.println("第" + t + "组测试数据");
      for(int i = 0; i < n; i++){
        arr1[i] = sc.nextInt();
      }
      int res = dfs1();
      if(res == -1) System.out.println("无解");
      else System.out.println(res);
      res = dfs2();
      if(res == -1) System.out.println("无解");
      else System.out.println(res);
      System.out.println();
    }
  }

  // 蛮力法
  public static int dfs1(){
    for(int i = 0; ; i++){
      boolean flag = true;
      for(int j = 0, k = 10; j < n; j++, k--){
        if(i % k != arr1[j]){
          flag = false;
          break;
        }
      }
      if(flag) return i;
    }
  }

  // 中国剩余定理
  public static int dfs2(){
    x[0] = y[0] = 0;
    boolean flag = true;
    int a1 = 10, b1 = arr1[0];
    for(int i = 1; i < n; i++){
      int a2 = 10 - i, b2 = arr1[i];
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

  // 扩展欧几里得算法
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

  public static void Method2(){
    int T = sc.nextInt();
    for(int t = 1; t <= T; t++) {
      System.out.println("第" + t + "组测试数据");
      n = sc.nextInt();
      m = sc.nextInt();
      arr2 = new int[n][m];
      dfs(0, 0, 1, -1, 1);
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
          System.out.printf("%2d ", arr2[i][j]);
        System.out.println();
      }
      System.out.println();
    }
  }

  static void dfs(int x, int y, int cnt, int dx, int dy){
    arr2[x][y] = cnt;
    if(x == n - 1 &&  y == m - 1) return;
    
    int a = x + dx;
    int b = y + dy;
    
    if(a < 0 && b < m){
      dx = 1;
      dy = -1;
      y++;
    }else if(a >= n){
      dx = -1;
      dy = 1;
      y++;
    }else if(b < 0){
      dx = -1;
      dy = 1;
      x++;
    }else if(b >= m){
      dx = 1;
      dy = -1;
      x++;
    }else{
      x += dx;
      y += dy;
    }
    dfs(x, y, cnt + 1, dx, dy);
  }

  public static void Method3(){
    dfs3(0);
  }

  public static void dfs3(int u){
    if(u == 9){
      int a = arr3[0] * 10 + arr3[1], b = arr3[2] * 100 + arr3[3] * 10 + arr3[4],
      c = arr3[5] * 1000 + arr3[6] * 100 + arr3[7] * 10 + arr3[8];
      if(a * b == c){
        System.out.println(a + " * " + b + " = " + c);
      }

      return;
    }

    for(int i = 1; i <= 9; i++){
      if(st[i]) continue;
      arr3[u] = i;
      st[i] = true;
      dfs3(u + 1);
      st[i] = false;
    }
  }

  public static void Method4(){
    int T = sc.nextInt();
    for(int t = 1; t <= T; t++) {
      System.out.println("第" + t + "组测试数据");
      res = 0;
      n = sc.nextInt();
      for(int i = 1; i < n; i++){
        int l = i + 1, r = n;
        while(l < r){
          int mid = l + r + 1 >> 1;
          if((i + mid) * (mid - i + 1) / 2 <= n) l = mid;
          else r = mid - 1;
        }
        if((i + l) * (l - i + 1) / 2 == n) {
          System.out.println(i + " --> " + l);
          res++;
        }
      }
      System.out.println("一共有" + res + "种方案\n");
    }
  }

  public static void Method5(){
    int T = sc.nextInt();
    for(int t = 1; t <= T; t++){
      System.out.println("第" + t + "组测试数据");
      res = 0;
      n = sc.nextInt();
      dfs5(n, n, 0);
      System.out.println("一共有" + res + "种方案\n");
    }
  }

  public static void dfs5(int n, int last, int u){
    if(n == 0){
      for(int i = 0; i < u; i++){
        System.out.print(arr5[i] + " ");
      }
      System.out.println();
      res++;
      return;
    }

    // System.out.println(n + " " + last + " " + u);

    for(int i = Math.min(n, last); i >= 1; i--){
      arr5[u] = i;
      dfs5(n - i, i, u + 1);
    }
  }
}

// 3
// 9 3 3 0 3 4 3 0 1
// 3 1 3 0 1 3 3 1 1
// 0 0 0 0 0 0 0 0 0

// 3
// 3 5
// 5 3
// 8 8

// 3
// 27
// 50
// 110

// 3
// 6
// 17
// 30
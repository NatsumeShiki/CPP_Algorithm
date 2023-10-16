package JavaCode.Experiment2;

import java.io.*;
import java.util.*;

public class Lab2{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";
  static Scanner sc;
  static int[] cnt = new int[]{1, 1, 1, 1};
  static int[] money = new int[]{10, 5, 2, 1};
  static int res = 0;
  static int n;
  static int[] maintainance;
  static int[] sell;
  static int[] dp;
  static int[] last;

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

    sc.close();
  }

  public static void Method1(){
    System.out.println("二分法：" + binary());
    System.out.println("牛顿迭代法：" + NewtonMethod());
    System.out.println("2cos20 = " + 2 * Math.cos(Math.toRadians(20)));
  }

  public static double binary(){
    double l = 1, r = 3;
    while(r - l > 1e-7){
      double mid = (l + r) / 2;
      if(mid * mid * mid - 3 * mid - 1 <= 0) l = mid;
      else r = mid; 
    }
    return l;
  }

  public static double NewtonMethod(){
    double x = 4;
    while(true){
      double tx = x - (x * x * x - 3 * x - 1) / (3 * x * x - 3);
      if(Math.abs(x - tx) < 1e-7) break;
      x = tx;
    }
    return x;
  }

  public static void Method2(){
    dfs(0, 82);
    System.out.println("一共有" + res + "种方案");
  }

  static void dfs(int u, int last){
    if(u == 3){
      cnt[u] += last;
      for(int i = 0; i < 4; i++){
        System.out.print(money[i] + "元：" + cnt[i] + "张\t");
      }
      System.out.println();
      cnt[u] -= last;
      res++;
      return;
    }

    for(int i = 0; i <= last / money[u]; i++){
      cnt[u] += i;
      dfs(u + 1, last - i * money[u]);
      cnt[u] -= i;
    }
  }

  public static void Method3(){
    int T = sc.nextInt();
    for(int index = 1; index <= T; index++) {
      System.out.println("第" + index + "组测试数据：");
      n = sc.nextInt();
      maintainance = new int[n + 1];
      sell = new int[n + 1];
      dp = new int[n + 1];
      last = new int[n + 1];
      int carCost = sc.nextInt();
      for(int i = 1; i <= n; i++) {
        maintainance[i] = sc.nextInt();
        maintainance[i] += maintainance[i - 1];
      }
      for(int i = 1; i <= n; i++) sell[i] = sc.nextInt();

      Arrays.fill(dp, 1, n + 1, Integer.MAX_VALUE);
      for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
          int t = dp[j] + carCost + maintainance[i - j] - sell[i - j];
          if(t < dp[i]){
            last[i] = j;
            dp[i] = t;
          }
        }
        // System.out.println(last[i] + " " + dp[i]);
      }
      
      int now = n;
      List<Integer> list = new ArrayList<Integer>();
      while(now != 0){
        list.add(now);
        // System.out.println(now);
        now = last[now];
      }
      Collections.reverse(list);
      System.out.println(list);
      System.out.println(n + "年一共要花" + dp[n] + "万元\n");
    }
  }
}

// 3
// 5 22
// 3 5 10 16 21
// 17 15 7 4 2
// 5 20
// 0 1 4 10 15
// 16 12 5 4 1
// 6 50
// 3 5 11 16 20 25
// 45 44 32 25 16 10
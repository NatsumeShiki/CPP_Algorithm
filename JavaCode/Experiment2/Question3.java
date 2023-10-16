package JavaCode.Experiment2;

import java.io.*;
import java.util.*;

public class Question3{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";
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
    Scanner sc = new Scanner(System.in);

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
    
    int now = 5;
    List<Integer> list = new ArrayList<Integer>();
    while(now != 0){
      list.add(now);
      // System.out.println(now);
      now = last[now];
    }
    Collections.reverse(list);
    System.out.println(list);
    System.out.println(dp[n]);


    sc.close();
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
package JavaCode.Homework2;

import java.io.*;
import java.util.*;

public class Question1 {
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int n, m;
  static int ans = 0;

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
      m = sc.nextInt();
      n = sc.nextInt();

      int res = dfs1(0, 0);
      System.out.println("从(0, 0)到(" + (m - 1) + "," + (n - 1) + ")一共有" + res + "种方案");
      ans = 0;
      dfs2(0, 0);
      System.out.println("从(0, 0)到(" + (m - 1) + "," + (n - 1) + ")一共有" + ans + "种方案");
    }

    sc.close();
  }

  public static int dfs1(int x, int y){
    if(x == m - 1 && y == n - 1) return 1;
    int res = 0;
    if(x < m - 1) res += dfs1(x + 1, y);
    if(y < n - 1) res += dfs1(x, y + 1);
    return res;
  }

  public static void dfs2(int x, int y){
    if(x == m - 1 && y == n - 1){
      ans++;
      return;
    }
    if(x < m - 1) dfs2(x + 1, y);
    if(y < n - 1) dfs2(x, y + 1);
  }
}
// 3
// 5 5
// 10 9
// 15 16

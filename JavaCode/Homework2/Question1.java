package JavaCode.Homework2;

import java.io.*;
import java.util.*;

public class Question1 {
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int n, m;

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

    m = sc.nextInt();
    n = sc.nextInt();

    int res = dfs(0, 0);
    System.out.println(res);

    sc.close();
  }

  public static int dfs(int x, int y){
    if(x == m - 1 && y == n - 1) return 1;
    int res = 0;
    if(x < m - 1) res += dfs(x + 1, y);
    if(y < n - 1) res += dfs(x, y + 1);
    return res;
  }
}

// 15 16
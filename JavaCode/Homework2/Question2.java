package JavaCode.Homework2;

import java.io.*;
import java.util.*;

public class Question2 {
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int n;
  static boolean[] col, row, deg, rdeg;
  static int res;
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
      res = 0;
      n = sc.nextInt();
      col = new boolean[n];
      row = new boolean[n];
      deg = new boolean[n * 2];
      rdeg = new boolean[n * 2];
      dfs(0, 0, 0);
      System.out.println(res);
    }

    sc.close();
  }

  public static void dfs(int x, int y, int cnt){
    if(y == n) {
      x++;
      y = 0;
    }
    if(x == n){
      if(cnt == n){
        res++;
      }
      return;
    }

    dfs(x, y + 1, cnt);

    if(!row[x] && !col[y] && !deg[x + y] && !rdeg[x - y + n]){
      row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = true;
      dfs(x, y + 1, cnt + 1);
      row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = false;
    }
  }
}

// 4
// 4 
// 6
// 8
// 12

// 2
// 4
// 92
// 14200
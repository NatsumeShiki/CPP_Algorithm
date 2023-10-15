package JavaCode.Experiment1;

import java.io.*;
import java.util.*;

public class Question2{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int n;
  static int m;
  static int[][] arr;

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
    m = sc.nextInt();
    arr = new int[n][m];
    dfs(0, 0, 1, -1, 1);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++)
        System.out.printf("%2d ", arr[i][j]);
      System.out.println();
    }

    sc.close();
  }
  
  static void dfs(int x, int y, int cnt, int dx, int dy){
    arr[x][y] = cnt;
    if(x == n - 1 &&  y == m - 1) return;
    
    int a = x + dx;
    int b = y + dy;
    // System.out.print(x + " " +  y + " " + a + " " + b + " ");
    // System.out.println(x + " " + y);
    
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
    // System.out.println(x + " " + y);
    dfs(x, y, cnt + 1, dx, dy);
  }
}

// 3
// 3 5
// 5 3
// 8 8
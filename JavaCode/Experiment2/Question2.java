package JavaCode.Experiment2;

import java.io.*;
import java.util.*;

public class Question2{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int[] cnt = new int[]{1, 1, 1, 1};
  static int[] money = new int[]{10, 5, 2, 1};
  static int res = 0;

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

    dfs(0, 82);
    System.out.println("一共有" + res + "种方案");

    sc.close();
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
}

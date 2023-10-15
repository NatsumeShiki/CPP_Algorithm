package JavaCode.Experiment1;

import java.io.*;
import java.util.*;

public class Question4{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int n;
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

    n = sc.nextInt();
    for(int i = 1; i < n; i++){
      int l = i + 1, r = n;
      while(l < r){
        int mid = l + r + 1 >> 1;
        if((i + mid) * (mid - i + 1) / 2 <= n) l = mid;
        else r = mid - 1;
      }
      if((i + l) * (l - i + 1) / 2 == n) {
        System.out.println(i + " " + l);
        res++;
      }
    }

    System.out.println(res);

    sc.close();
  }
}
// 3
// 27
// 50
// 110
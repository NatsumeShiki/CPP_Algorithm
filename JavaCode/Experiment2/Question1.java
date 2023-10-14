package JavaCode.Experiment2;

import java.io.*;
import java.util.*;

public class Question1{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

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

    
    System.out.println("二分法：" + binary());

    System.out.println("2cos20 = " + 2 * Math.cos(Math.toRadians(20)));

    System.out.println("牛顿迭代法：" + NewtonMethod());

    sc.close();
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
}

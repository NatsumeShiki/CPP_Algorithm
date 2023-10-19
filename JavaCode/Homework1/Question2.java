package JavaCode.Homework1;

import java.io.*;
import java.util.*;

public class Question2{
  static private final String INPUT = "D:\\CPP\\Algorithm\\JavaCode\\in.txt";
  static private final String OUTPUT = "D:\\CPP\\Algorithm\\JavaCode\\out.txt";

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


    int[] arr = new int[]{100, 50, 10, 5, 2, 1};
    int n = sc.nextInt();

    int res = 0;
    for(int i = 0; i < arr.length && n > 0; i++){
      int t = n / arr[i];
      res += t;
      n -= t * arr[i];
    }

    System.out.println(res);

    sc.close();
  }
}
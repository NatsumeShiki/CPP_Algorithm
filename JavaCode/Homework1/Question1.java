package JavaCode.Homework1;

import java.io.*;

public class Question1{
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

    for(int i = 100; i <= 999; i++){
      int a = i / 100, b = i / 10 % 10, c = i % 10;
      if(a < c && c > b && (a + b + c) == a * b * c){
        System.out.println(i);
      }
    }
  }
}
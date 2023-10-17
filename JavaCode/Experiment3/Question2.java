package JavaCode.Experiment3;

import java.io.*;
import java.util.*;

public class Question2{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int n = 9;
  static int[][] g = new int[9][9];
  static int[] dx = new int[]{-1, -1, -1, 0, 0, 0, 1, 1, 1};
  static int[] dy = new int[]{-1, 0, 1, -1, 0, 1, -1, 0, 1};

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

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        g[i][j] = sc.nextInt();
      }
    }

    if(sudoku()){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          System.out.print(g[i][j] + " ");
        }
        System.out.println();
      }
    }else System.out.println("无解");

    sc.close();
  }

  public static boolean sudoku(){
    Stack<Integer> st = new Stack<>();
    st.push(find());
    // int t;
    while(!st.empty() && st.peek() >= 0){
      int t = st.peek();
      int x = t / 9, y = t % 9;
      int index = g[x][y] + 1;
      for(; index <= 9 && (!check(x, y, index)); index++);

      if(index > 9){
        g[x][y] = 0;
        st.pop();
      }else{
        g[x][y] = index;
        st.push(find());
      }
    }

    return !st.isEmpty();
  }

  public static int find(){
    for(int i = 0; i < 81; i++){
      if(g[i / 9][i % 9] == 0)
        return i;
    }
    return -1;
  }

  public static boolean check(int x, int y, int t){
    for(int i = 0; i < 9; i++){
      if(g[x][i] == t || g[i][y] == t){
        return false;
      }
    }
    int tx = x / 3 * 3 + 1, ty = y / 3 * 3 + 1;
    for(int i = 0; i < 9; i++){
      int a = tx + dx[i], b = ty + dy[i];
      if(g[a][b] == t){
        return false;
      }
    }
    return true;
  } 
}

// 3
// 0 0 5 3 0 0 0 0 0
// 8 0 0 0 0 0 0 2 0
// 0 7 0 0 1 0 5 0 0
// 4 0 0 0 0 5 3 0 0
// 0 1 0 0 7 0 0 0 6
// 0 0 3 2 0 0 0 8 0
// 0 6 0 5 0 0 0 0 9
// 0 0 4 0 0 0 0 3 0
// 0 0 0 0 0 9 7 0 0

// 4 0 0 0 0 0 8 0 5
// 0 3 0 0 0 0 0 0 0 
// 0 0 0 7 0 0 0 0 0
// 0 2 0 0 0 0 0 6 0
// 0 0 0 0 8 0 4 0 0
// 0 0 0 0 1 0 0 0 0
// 0 0 0 6 0 3 0 7 0
// 5 0 0 2 0 0 0 0 0
// 1 0 4 0 0 0 0 0 0

// 0 0 0 0 0 0 5 2 0
// 0 8 0 4 0 0 0 0 0
// 0 3 0 0 0 9 0 0 0
// 5 0 1 0 0 0 6 0 0
// 2 0 0 7 0 0 0 0 0
// 0 0 0 3 0 0 0 0 0
// 6 0 0 0 1 0 0 0 0
// 0 0 0 0 0 0 7 0 4
// 0 0 0 0 0 0 0 3 0
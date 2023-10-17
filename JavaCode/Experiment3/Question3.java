package JavaCode.Experiment3;

import java.io.*;
import java.util.*;

public class Question3{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";

  static int freight[][]; // 运费
  static int sales[]; // 售价
  static int salesCopy[]; // 售价的拷贝，用于复原
  static int production[]; // 产量
  static int productionCopy[]; // 产量的拷贝，用于复原
  static int res = Integer.MAX_VALUE; // 结果，要求最小值，所以先最大化成最大值
  static int key[][] = new int[][]{{1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 2, 1}, {3, 1, 2}}; // 闭回路法数组，探寻周围空格是否存在回回路
  static int n = 3, m = 4;

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
    freight = new int[n][m];
    sales = new int[m];
    salesCopy = new int[m];
    production = new int[n];
    productionCopy = new int[n];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        freight[i][j] = sc.nextInt();
    for(int i = 0; i < m; i++) {
      sales[i] = sc.nextInt();
      salesCopy[i] = sales[i];
    }
    for(int i = 0; i < n; i++) {
      production[i] = sc.nextInt();
      productionCopy[i] = production[i];
    }
    bfs();

    sc.close();
  }

  public static void bfs(){
    Queue<NodeType> heap = new PriorityQueue<>();
    NodeType e = new NodeType();
    NodeType e1 = new NodeType();
    // e.r = new int[4];
    for(int i = 0; i < m; i++){
      e.r[i] = i;
    }
    bound(e); // 求出一个可行解，然后进行判断
    ret();
    heap.offer(e);
    int j = 0;
    while(!heap.isEmpty()){
      e = heap.poll();
      if(res > e.lb){
        res = e.lb;
      }
      e1.r[0] = e.r[0];
      for(int i = 1; i < 4; i++){
        e1.r[i] = key[j][i - 1];
      }
      j++;
      bound(e1);
      ret();
      if(e1.lb <= res){
        heap.offer(e1);
      }
    }

    System.out.println("总运费最小的方案为：\n\t  \tB1\tB2\tB3\tB4\t产量");
    for(int i = 0; i < 3; i++){
      System.out.print("A" + (i + 1) + "\t\t");
      for(j = 0; j < 4; j++){
        System.out.print(e.pro[i][j] + "\t\t");
      }
      System.out.println(production[i]);
    }
    System.out.print("销量\t");
    for(int i = 0; i < m; i++) System.out.print(sales[i] + "\t\t");
  }

  // 分支回溯的复原
  public static void ret(){
    for(int i = 0; i < m; i++) sales[i] = salesCopy[i];
    for(int i = 0; i < n; i++) production[i] = productionCopy[i];
  }

  // 分支界限的约数函数
  public static void bound(NodeType e){
    int sum = 0, j;
    for(int index = 0; index < m; index++){
      j = e.r[index];
      int temp, i = 0;
      int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
      int[] x = new int[]{0, 0, 0};
      for(int k = 0; k < n; k++){
        if(min > freight[k][j]){
          x[0] = k;
          min = freight[k][j];
        }
      }

      for(int k = 0;  k < n; k++){
        if(max < freight[k][j]){
          x[2] = k;
          max = freight[k][j];
        }
      }

      x[1] = 3 - x[0] - x[2];
      while(sales[j] > 0){
        temp = sales[j];
        e.pro[x[i]][j] = Math.min(sales[j], production[x[i]]);
        sales[j] -= production[x[i]];
        if(sales[j] > 0){
          sum = sum + production[x[i]] * freight[x[i]][j];
          production[x[i]] = 0;
          i++;
        }else{
          sales[j] = 0;
          sum = sum + freight[x[i]][j] * temp;
          production[x[i]] -= temp;
        }
      }
    }
    e.lb = sum;
  }
}

class NodeType implements Comparable{
  int[] r = new int[4];
  int lb;
  int[][] pro = new int[3][4];

  public NodeType(){

  }

  @Override
  public int compareTo(Object obj){
    NodeType NodeType = (NodeType)obj;
    return lb - NodeType.lb;
  }
}

// 3 4
// 3 11 3 10
// 1 9 2 8
// 7 4 10 5
// 3 6 5 6
// 7 4 9
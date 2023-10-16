package JavaCode.Experiment3;

import java.io.*;
import java.util.*;

public class Lab3{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";
  static Scanner sc;
  static int a, b, c, d;
  static int[][] g = new int[9][9];
  static int[] dx = new int[]{-1, -1, -1, 0, 0, 0, 1, 1, 1};
  static int[] dy = new int[]{-1, 0, 1, -1, 0, 1, -1, 0, 1};
  static int n, m;
  static int freight[][]; // 运费
  static int sales[]; // 售价
  static int salesCopy[]; // 售价的拷贝，用于复原
  static int production[]; // 产量
  static int productionCopy[]; // 产量的拷贝，用于复原
  static int res = Integer.MAX_VALUE; // 结果，要求最小值，所以先最大化成最大值
  static int key[][] = new int[][]{{1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 2, 1}, {3, 1, 2}}; // 闭回路法数组，探寻周围空格是否存在回回路

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
    sc = new Scanner(System.in);

    System.out.println("第一题：");
    Method1();
    System.out.println("\n第二题：");
    Method2();
    System.out.println("\n第三题：");
    Method3();

    sc.close();
  }

  public static void Method1(){
    int T = sc.nextInt();
    for(int i = 1; i <= T; i++) {
      System.out.println("第" + i + "组测试数据：");
      a = sc.nextInt();
      b = sc.nextInt();
      c = sc.nextInt();
      d = sc.nextInt();
      bfs();
    }
  }

  public static void bfs(){
    // System.out.println(a + " " + b + " " + c + " " + d);
    Queue<Node> q = new LinkedList();
    q.offer(new Node(a, 0, 0));
    // HashMap<Node, Node> map = new HashMap<>();
    Node[][][] pre = new Node[a + 1][a + 1][a + 1];
    boolean[][][] st = new boolean[a + 1][a + 1][a + 1];
    st[a][0][0] = true;
    
    // System.out.println(q.size());
    // System.out.println(a + " " + b + " " + c);
    while(!q.isEmpty()){
      Node t = q.poll();
      int ta = t.a, tb = t.b, tc= t.c;

      if(ta == d && (tb == d || tc == d)) break;

      // System.out.println(ta + " " + tb + " " + tc);
      int x = Math.min(ta, b - tb);
      // System.out.println(x);
      // System.out.println(st[ta - x][tb + x][tc]);
      if(!st[ta - x][tb + x][tc]){
        Node node = new Node(ta - x, tb + x, tc);
        q.offer(node);
        // map.put(node, t);
        pre[ta - x][tb + x][tc] = t;
        st[ta - x][tb + x][tc] = true;
      }

      x = Math.min(ta, c - tc);
      if(!st[ta - x][tb][tc + x]){
        Node node = new Node(ta - x, tb, tc + x);
        q.offer(node);
        // map.put(node, t);
        pre[ta - x][tb][tc + x] = t;
        st[ta - x][tb][tc + x] = true;
      }

      x = Math.min(tb, a - tb);
      if(!st[ta + x][tb - x][tc]){
        Node node = new Node(ta + x, tb - x, tc);
        q.offer(node);
        // map.put(node, t);
        pre[ta + x][tb - x][tc] = t;
        st[ta + x][tb - x][tc] = true;
      }
      
      x = Math.min(tb, c - tc);
      if(!st[ta][tb - x][tc + x]){
        Node node = new Node(ta, tb - x, tc + x);
        q.offer(node);
        // map.put(node, t);
        pre[ta][tb - x][tc + x] = t;
        st[ta][tb - x][tc + x] = true;
      }

      x = Math.min(tc, a - ta);
      if(!st[ta + x][tb][tc - x]){
        Node node = new Node(ta + x, tb, tc - x);
        q.offer(node);
        // map.put(node, t);
        pre[ta + x][tb][tc - x] = t;
        st[ta + x][tb][tc - x] = true;
      }

      x = Math.min(tc, b - tb);
      if(!st[ta][tb + x][tc - x]){
        Node node = new Node(ta, tb + x, tc - x);
        q.offer(node);
        // map.put(node, t);
        pre[ta][tb + x][tc - x] = t;
        st[ta][tb + x][tc - x] = true;
      }
    }

    // System.out.println(d);
    if(!st[d][0][d] && !st[d][d][0]){
      System.out.println("None");
    }else{
      ArrayList<Node> list = new ArrayList();
      if(st[d][d][0]){
        list.add(new Node(d, d, 0));
        int ta = d, tb = d, tc = 0;
        while(pre[ta][tb][tc] != null){
          Node node = pre[ta][tb][tc];
          list.add(node);
          ta = node.a;
          tb = node.b;
          tc = node.c;
        }
      }else{
        list.add(new Node(d, 0, d));
        int ta = d, tb = 0, tc = d;
        while(pre[ta][tb][tc] != null){
          Node node = pre[ta][tb][tc];
          list.add(node);
          ta = node.a;
          tb = node.b;
          tc = node.c;
        }
      }

      Collections.reverse(list);
      for(Node node : list){
        System.out.println(node);
      }
    }
  }

  public static void Method2(){
    int T = sc.nextInt();
    n = 9;
    for(int t = 1; t <= T; t++){
      System.out.println("第" + t + "组测试数据");
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
    }
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

  public static void Method3(){
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
    bfs3();
  }

  public static void bfs3(){
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

class Node{
  public int a, b, c;
  
  public Node(int a, int b, int c){
    this.a = a;
    this.b = b;
    this.c = c;
  }

  public String toString(){
    return a + " " + b + " " + c;
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

// 3
// 10 7 3 5
// 20 12 8 10
// 30 25 5 15

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

// 3 4
// 3 11 3 10
// 1 9 2 8
// 7 4 10 5
// 3 6 5 6
// 7 4 9
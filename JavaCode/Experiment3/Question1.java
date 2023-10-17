package JavaCode.Experiment3;

import java.io.*;
import java.util.*;

public class Question1{
  static private final String INPUT = "D:/CPP/Algorithm/JavaCode/in.txt";
  static private final String OUTPUT = "D:/CPP/Algorithm/JavaCode/out.txt";
  static int a, b, c, d;

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

    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();
    d = sc.nextInt();
    bfs();

    sc.close();
  }

  public static void bfs(){
    Queue<Node> q = new LinkedList();
    q.offer(new Node(10, 0, 0));
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

// 3
// 10 7 3 5
// 20 12 8 10
// 30 17 13 15
// 实现一个双链表，双链表初始为空，支持 5 种操作：

// 在最左侧插入一个数；
// 在最右侧插入一个数；
// 将第 k 个插入的数删除；
// 在第 k 个插入的数左侧插入一个数；
// 在第 k 个插入的数右侧插入一个数
// 现在要对该链表进行 M 次操作，进行完所有操作后，从左到右输出整个链表。

// 注意:题目中第 k 个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，这 n 个数依次为：第 1 个插入的数，第 2 个插入的数，…第 n 个插入的数。

// 输入格式
// 第一行包含整数 M，表示操作次数。

// 接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：

// L x，表示在链表的最左端插入数 x。
// R x，表示在链表的最右端插入数 x。
// D k，表示将第 k 个插入的数删除。
// IL k x，表示在第 k 个插入的数左侧插入一个数。
// IR k x，表示在第 k 个插入的数右侧插入一个数。
// 输出格式
// 共一行，将整个链表从左到右输出。

// 数据范围
// 1≤M≤100000
// 所有操作保证合法。

// 输入样例：
// 10
// R 7
// D 1
// L 3
// IL 2 10
// D 3
// IL 2 7
// L 8
// R 9
// IL 4 7
// IR 2 2
// 输出样例：
// 8 7 7 3 2 9

#include<iostream>
using namespace std;

const int N = 100010;
int l[N], r[N], e[N], idx;

// 初始化双链表
void init(){
  r[0] = 1; // 数组第一个下标是双链表的左端点
  l[1] = 0; // 数组第二个下标是双链表的右端点
  idx = 2; // 真实存储数据的节点从下标为2开始
}
void headInsert(int x){ // 头插
  e[idx] = x; // 存储数据
  l[idx] = 0, r[idx] = r[0]; // 更新新创建的节点的左右指向
  l[r[0]] = idx, r[0] = idx; // 更新原双链表
  idx++; // 节点数目增加
}
void tailInsert(int x){ // 尾插
  e[idx] = x; // 存储数据
  l[idx] = l[1], r[idx] = 1; // 更新新创建的节点的左右指向
  r[l[1]] = idx, l[1] = idx;// 更新原双链表
  idx++; // 节点数目增加
}
void remove(int k){ // 删除节点
  r[l[k]] = r[k]; // 让删除的节点的左节点的右边指向删除的节点的右边指向
  l[r[k]] = l[k]; // 让删除的节点的右节点的左边指向删除的节点的左边指向
}
void leftInsert(int k, int x){ // 插到第k个节点的左边
  e[idx] = x; // 保存数据
  l[idx] = l[k], r[idx] = k; // 更新新创建的节点的左右指向
  r[l[k]] = idx, l[k] = idx; // 更新原双链表
  idx++; // 节点数目增加
}
void rightInsert(int k, int x){ // 插到第k个节点的右边
  e[idx] = x; // 保存数据
  l[idx] = k, r[idx] = r[k]; // 更新新创建的节点的左右指向
  l[r[k]] = idx, r[k] = idx; // 更新原双链表
  idx++; // 节点数目增加
}

int main(){
  int m;
  cin >> m;
  init();
  while(m--){
      int k, x;
      string option;
      cin >> option;
      if(option == "L"){
          cin >> x;
          headInsert(x);
      }else if(option == "R"){
          cin >> x;
          tailInsert(x);
      }else if(option == "D"){
          cin >> k;
          remove(k + 1);
      }else if(option == "IL"){
          cin >> k >> x;
          leftInsert(k + 1, x);
      }else if(option == "IR"){
          cin >> k >> x;
          rightInsert(k + 1, x);
          // 其实这一步也可以用左插，但是要在k+1节点左插
          // leftInsert(r[k + 1], x);
      }
  }
  for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
  return 0;
}
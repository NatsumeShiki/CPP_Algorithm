// 满足如下条件的序列 X
// （序列中元素被标号为 1、2、3…m
// ）被称为“加成序列”：

// X[1]=1
// X[m]=n
// X[1]<X[2]<…<X[m−1]<X[m]
// 对于每个 k
// （2≤k≤m
// ）都存在两个整数 i
//  和 j
//  （1≤i,j≤k−1
// ，i
//  和 j
//  可相等），使得 X[k]=X[i]+X[j]
// 。
// 你的任务是：给定一个整数 n
// ，找出符合上述条件的长度 m
//  最小的“加成序列”。

// 如果有多个满足要求的答案，只需要找出任意一个可行解。

// 输入格式
// 输入包含多组测试用例。

// 每组测试用例占据一行，包含一个整数 n
// 。

// 当输入为单行的 0
//  时，表示输入结束。

// 输出格式
// 对于每个测试用例，输出一个满足需求的整数序列，数字之间用空格隔开。

// 每个输出占一行。

// 数据范围
// 1≤n≤100
// 输入样例：
// 5
// 7
// 12
// 15
// 77
// 0
// 输出样例：
// 1 2 4 5
// 1 2 4 6 7
// 1 2 4 8 12
// 1 2 4 5 10 15
// 1 2 4 8 9 17 34 68 77

/*
剪枝1：优先枚举较大的数
剪枝2：排除等效冗余
*/
#include<iostream>
using namespace std;

const int N = 110;
int path[N]; // 记录路径
int n;

bool dfs(int u, int depth){
    if(u > depth) return false; // 如果u大于depth，就说明在depth这一层中没有n，返回false
    if(path[u - 1] == n) return true; // 如果在depth层找到了n，就返回true
     
    bool st[N] = {0}; // 开一个bool数组，用于保存这个数是否使用过
    for(int i = u - 1; i >= 0; i--) // 剪枝1，从大往小
        for(int j = i; j >= 0; j--){
            int s = path[i] + path[j]; // 计算两个数的和
            if(s > n || s <= path[u - 1] || st[s]) continue; // 如果它比要查询的n大，比上一个数小，或者已经使用过了，就循环下一次
            path[u] = s; // 先在这一层使用s
            st[s] = true; // 并把它设置为true
            if(dfs(u + 1, depth)) return true; // 递归继续往下查询，如果找到了，返回true
        }
    return false; // 在depth层没有查询到，返回false
}

int main(){
    path[0] = 1; // 第一个数都是0
    while(cin >> n, n){
        int depth = 1; // 首先枚举第一层
        while(!dfs(1, depth)) depth++; // 如果在depth层找不到，就继续往下找
        for(int i = 0; i < depth; i++) cout << path[i] << " ";
        cout << endl;
    }
    
    return 0;
}
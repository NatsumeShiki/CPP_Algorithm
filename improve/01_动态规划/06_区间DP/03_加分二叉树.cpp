// 设一个 n
//  个节点的二叉树 tree 的中序遍历为（1,2,3,…,n
// ），其中数字 1,2,3,…,n
//  为节点编号。

// 每个节点都有一个分数（均为正整数），记第 i
//  个节点的分数为 di
// ，tree 及它的每个子树都有一个加分，任一棵子树 subtree（也包含 tree 本身）的加分计算方法如下：     

// subtree的左子树的加分 ×
//  subtree的右子树的加分 ＋
//  subtree的根的分数 

// 若某个子树为空，规定其加分为 1
// 。

// 叶子的加分就是叶节点本身的分数，不考虑它的空子树。

// 试求一棵符合中序遍历为（1,2,3,…,n
// ）且加分最高的二叉树 tree。

// 要求输出： 

// （1）tree的最高加分 

// （2）tree的前序遍历

// 输入格式
// 第 1
//  行：一个整数 n
// ，为节点个数。 

// 第 2
//  行：n
//  个用空格隔开的整数，为每个节点的分数（0<
// 分数<100
// ）。

// 输出格式
// 第 1
//  行：一个整数，为最高加分（结果不会超过int范围）。     

// 第 2
//  行：n
//  个用空格隔开的整数，为该树的前序遍历。如果存在多种方案，则输出字典序最小的方案。

// 数据范围
// n<30
// 输入样例：
// 5
// 5 7 1 2 10
// 输出样例：
// 145
// 3 1 2 4 5

/*
动态规划
  状态表示f[l, r]
    集合：所有中序遍历是[l, r]这一段的二叉树的集合
    属性：Max
  状态计算：
    根据割点计算最大值 l l+1 l+2 ... r-1 r
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;
int n, w[N], f[N][N], g[N][N]; // f[l, r]记录最大值，g[l, r]记录最大值的根节点

void dfs(int l, int r){
    if(l > r) return;
    
    int root = g[l][r]; // 前序遍历是先根节点，再左子树，最后右子树
    cout << root << " "; // 首先输出根节点
    dfs(l, root - 1); // dfs左子树
    dfs(root + 1, r); // dfs右子树
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    
    for(int len = 1; len <= n; len++)
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            if(len == 1){ // 如果长度是1，那么权值就是本身，根节点也是本身
                f[l][r] = w[l];
                g[l][r] = l;
            }else{
                for(int k = l; k <= r; k++){ // 枚举割点
                    int left = k == l ? 1 : f[l][k - 1]; // 如果l和k重合，没有左子树，此时左子树权值设置为1
                    int right = k == r ? 1 : f[k + 1][r]; 
                    int score = left * right + w[k]; // 计算分数
                    if(f[l][r] < score){ // 如果更大
                        f[l][r] = score; // 更新最大分数
                        g[l][r] = k; // 更新根节点
                    }
                }
            }
        }
        
    cout << f[1][n] << endl; // 输出中序遍历是1 - n的最大分数
    dfs(1, n); // 输出前序遍历结果
    
    return 0;
}
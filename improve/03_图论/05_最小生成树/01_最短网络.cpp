// 农夫约翰被选为他们镇的镇长！

// 他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。

// 约翰已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。

// 约翰的农场的编号是1，其他农场的编号是 2∼n
// 。

// 为了使花费最少，他希望用于连接所有的农场的光纤总长度尽可能短。

// 你将得到一份各农场之间连接距离的列表，你必须找出能连接所有农场并使所用光纤最短的方案。

// 输入格式
// 第一行包含一个整数 n
// ，表示农场个数。

// 接下来 n
//  行，每行包含 n
//  个整数，输入一个对角线上全是0的对称矩阵。
// 其中第 x+1
//  行 y
//  列的整数表示连接农场 x
//  和农场 y
//  所需要的光纤长度。

// 输出格式
// 输出一个整数，表示所需的最小光纤长度。

// 数据范围
// 3≤n≤100

// 每两个农场间的距离均是非负整数且不超过100000。

// 输入样例：
// 4
// 0  4  9  21
// 4  0  8  17
// 9  8  0  16
// 21 17 16  0
// 输出样例：
// 28


// prim算法
/*
每次选择一个点加入到连通块中，一共n个点，所以每次加进去一个点后用这个点来更新其他点到连通块的距离，一共需要加n个
如何证明当前这条边一定可以被选择？
  假设不选当前边，最终得到了一棵树，然后将这条边加上，那么必然会出现一个环，在这个环上，一定可以找出一条长度不小于当前边的边，那么把
  当前边替换上去，结果一定不会变差
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;
int d[N][N]; // 保存两个点之间的距离
int dist[N]; // 保存点到连通块的距离
int n;
bool st[N]; // 保存点是否已经在连通块中

int prim(){
    memset(dist, 0x3f, sizeof dist); // 所有点到连通块距离为无穷大
    dist[1] = 0; // 设置1到连通块距离为0
    int res = 0;
    for(int i = 1; i <= n; i++){ // 一共有n个点，所以需要添加到连通块中n次
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t])) // 如果j还没有添加到连通块中并且j到连通块距离更小
                t = j; // 保存距离连通块距离最小的点
                
        st[t] = true; // 设置为已经在连通块中
        res += dist[t]; // 结果加上这条边长度
        
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], d[t][j]); // 用t点来更新其他点到连通块距离
    }
    
    return res;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> d[i][j];
            
    cout << prim() << endl;
    
    return 0;
}
// 给定 n
//  本书，编号为 1∼n
// 。

// 在初始状态下，书是任意排列的。

// 在每一次操作中，可以抽取其中连续的一段，再把这段插入到其他某个位置。

// 我们的目标状态是把书按照 1∼n
//  的顺序依次排列。

// 求最少需要多少次操作。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据包含两行，第一行为整数 n
// ，表示书的数量。

// 第二行为 n
//  个整数，表示 1∼n
//  的一种任意排列。

// 同行数之间用空格隔开。

// 输出格式
// 每组数据输出一个最少操作次数。

// 如果最少操作次数大于或等于 5
//  次，则输出 5 or more。

// 每个结果占一行。

// 数据范围
// 1≤n≤15
// 输入样例：
// 3
// 6
// 1 3 4 6 2 5
// 5
// 5 4 3 2 1
// 10
// 6 8 5 3 4 7 2 9 1 10
// 输出样例：
// 2
// 3
// 5 or more

/*
枚举取出的书的长度len，因此一共有1 ~ n-len+1 中取的方式，有n-len中放的位置
一种长度时间复杂度是 (n-len+1) * (n-len)
求和是 (15*14 + 14*13 + ... + 2*1) / 2
由公式 1*2 + 2*3 + ... + n(n+1) = n(n+1)(n+2) / 3可以得到
总和是14 * 15 * 16 / 3 / 2 = 560，最多只需要查找四层，时间复杂度就是560^2，会TLE
如果使用双向dfs可以降低到560^2，这是一种方法
另一种方法是：每存放一定长度的书，会改变三个位置的后继，因此可以计算估价函数，至多需要 向上取整(tot/3) = 向下取整((tot+2)/3)，最终如果估价函数为0，说明排序正确
他就是结果
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 15;
int n;
int q[N]; // 摆放的书
int w[5][N]; // 用于保存备份，第一个5表示的是层数

int f(){ // 估价函数 1后面的数如果是2，就不用管，如果不是2，就加1
    int tot = 0; 
    for(int i = 0; i + 1 < n; i++)
        if(q[i + 1] != q[i] + 1)
            tot++;
    return (tot + 2) / 3;
}

bool dfs(int depth, int max_depth){
    if(depth + f() > max_depth) return false; // 如果当前层数加上通过估价函数计算所需要的层数大于5，就说明肯定找不到4层以内的正确结果
    if(f() == 0) return true; // 如果估价函数为0，就说明找到了结果
    
    for(int len = 1; len <= n; len++) // 从中取出n本书
        for(int l = 0; l + len - 1 < n; l++){ // 枚举左边界
            int r = l + len - 1; // 计算右边界
            for(int k = r + 1; k < n; k++){ // 它可以放在左边，也可以放在右边，但是会有重复，所以统一放在后面即可
                memcpy(w[depth], q, sizeof q); // 先把原来的顺序保存备份
                int y = l; // y记录开始存放的位置
                for(int x = r + 1; x <= k; x++, y++) q[y] = w[depth][x]; // 先把右边的数放到左边
                for(int x = l; x <= r; x++, y++) q[y] = w[depth][x]; // 再把左边的数放在右边
                if(dfs(depth + 1, max_depth)) return true; // 向下搜索，如果找到方案，返回true
                memcpy(q, w[depth], sizeof q); // 否则还原状态
            }
        }
    return false; // depth层找不到
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> q[i];
        
        int depth = 0; // 迭代加深
        while(depth < 5 && !dfs(0, depth)) depth++;
        
        if(depth >= 5) puts("5 or more");
        else cout << depth << endl;
    }
    
    return 0;
}
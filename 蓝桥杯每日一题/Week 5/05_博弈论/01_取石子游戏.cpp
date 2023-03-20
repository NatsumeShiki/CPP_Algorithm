// Alice 和 Bob 正在玩一个取石子游戏。

// 共有 n
//  个石子，双方轮流采取行动。

// 每当轮到一人行动时，该名玩家需要从石子堆中取走恰好 1
//  或 2
//  或 k
//  个石子。

// 如果轮到一人行动时，已经没有石子可取，则该名玩家失败。

// 已知，双方都会采取最优策略，且 Alice 率先行动。

// 请问，最终谁将获胜。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据占一行，包含两个整数 n,k
// 。

// 输出格式
// 每组数据输出一行结果，如果 Alice 获胜，则输出 Alice，否则输出 Bob。

// 数据范围
// 前三个测试点满足，1≤T≤10
// 。
// 所有测试点满足，1≤T≤100
// ，0≤n≤109
// ，3≤k≤109
// 。

// 输入样例：
// 4
// 0 3
// 3 3
// 3 4
// 4 4
// 输出样例：
// Bob
// Alice
// Bob
// Alice

#include<iostream>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, k;
        scanf("%d%d", &n, &k);
        if(k % 3){
            if(n % 3) puts("Alice");
            else puts("Bob");
        }else{
            int r = n % (k + 1);
            if(r == k || r % 3) puts("Alice");
            else puts("Bob");
        }
    }
    
    
    return 0;
}

// 打表算法
#include<iostream>
using namespace std;

const int N = 110;
int n;
int f[N];

int main(){
    int k;
    cin >> n >> k;
    f[0] = 0;
    
    for(int i = 1; i <= n; i++){
        int d[] = {1, 2, k};
        for(int x : d)
            if(i >= x && !f[i - x])
                f[i] = 1;
    }
    
    for(int i = 1; i <= n; i++)
        printf("%d ", f[i]);
    
    return 0;
}
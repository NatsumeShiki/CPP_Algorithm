// 给定 n 堆石子以及一个由 k 个不同正整数构成的数字集合 S。

// 现在有两位玩家轮流操作，每次操作可以从任意一堆石子中拿取石子，每次拿取的石子数量必须包含于集合 S，最后无法进行操作的人视为失败。

// 问如果两人都采用最优策略，先手是否必胜。

// 输入格式
// 第一行包含整数 k，表示数字集合 S 中数字的个数。

// 第二行包含 k 个整数，其中第 i 个整数表示数字集合 S 中的第 i 个数 si。

// 第三行包含整数 n。

// 第四行包含 n 个整数，其中第 i 个整数表示第 i 堆石子的数量 hi。

// 输出格式
// 如果先手方必胜，则输出 Yes。

// 否则，输出 No。

// 数据范围
// 1≤n,k≤100,
// 1≤si,hi≤10000
// 输入样例：
// 2
// 2 5
// 3
// 2 4 7
// 输出样例：
// Yes

/*
Mex运算
设S表示一个非负整数集合。定义mex(S)为求出不属于集合S的最小非负整数的运算，即：
mex(S) = min{x}, x属于自然数，且x不属于S

SG函数
在有向图游戏中，对于每个节点x，设从x出发共有k条有向边，分别到达节点y1, y2, …, yk，定义SG(x)为x的后继节点y1, y2, …, yk 的SG函数值构成的集合再执行mex(S)运算的结果，即：
SG(x) = mex({SG(y1), SG(y2), …, SG(yk)})
特别地，整个有向图游戏G的SG函数值被定义为有向图游戏起点s的SG函数值，即SG(G) = SG(s)。

设G1, G2, …, Gm 是m个有向图游戏。定义有向图游戏G，它的行动规则是任选某个有向图游戏Gi，并在Gi上行动一步。G被称为有向图游戏G1, G2, …, Gm的和。
有向图游戏的和的SG函数值等于它包含的各个子游戏SG函数值的异或和，即：
SG(G) = SG(G1) ^ SG(G2) ^ … ^ SG(Gm)

有向图游戏的某个局面必胜，当且仅当该局面对应节点的SG函数值大于0。
有向图游戏的某个局面必败，当且仅当该局面对应节点的SG函数值等于0。

这道题只需要将所有图的SG函数求出来之后异或，如果结果不为0，就是先手必胜，否则就是先手必败，证明和Nim游戏很像
*/
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

const int N = 110, M = 10010;
int n, m;
int s[N], f[M]; // s数组保存每次可以拿多少个石头，f数组：比如说 x可以指向y1,y2,...yn，f数组就保存这些数字的SG函数，用他们来求出x的SG函数

int sg(int x){
    if(f[x] != -1) return f[x]; // 
    unordered_set<int> S; // 保存它的子节点的SG值
    for(int i = 0; i < m; i++){ // 遍历每次可以取出多少石头，将取出这些石头后它的SG值保存到s这个set中，set的性质是不重复
        int sum = s[i];
        if(x >= sum) S.insert(sg(x - sum));
    }
    for(int i = 0; ; i++) // 获取最小没有出现的自然数
        if(!S.count(i)) // 如果S.count(i)等于0，就表示没有出现过，所以就返回它
            return f[x] = i;
}

int main(){
    cin >> m;
    for(int i = 0; i < m; i++) cin >> s[i]; 
    cin >> n;
    memset(f, -1, sizeof f); // 将f数组都重置成-1，表示还没有出现当前的SG值
    int res = 0;
    for(int i = 0; i < n; i++){ // 遍历每一堆石头，求出根节点的SG值，异或起来
        int x;
        cin >> x;
        res ^= sg(x);
    }
    // 如果结果不为0，就表示必胜，否则必败
    if(res) puts("Yes");
    else puts("No");
    return 0;
}
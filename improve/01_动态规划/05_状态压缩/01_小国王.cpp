// 在 n×n
//  的棋盘上放 k
//  个国王，国王可攻击相邻的 8
//  个格子，求使它们无法互相攻击的方案总数。

// 输入格式
// 共一行，包含两个整数 n
//  和 k
// 。

// 输出格式
// 共一行，表示方案总数，若不能够放置则输出0
// 。

// 数据范围
// 1≤n≤10
// ,
// 0≤k≤n2
// 输入样例：
// 3 2
// 输出样例：
// 16

/*
状态压缩DP
  状态表示f[i, j, s]
    集合：所有只摆在前i行，已经摆了j个国王，并且第i行摆放的状态是s的所有方案的集合
    属性：Count
  状态计算
    已经摆完了前i排，并且第i排的状态是a，第i-1排的状态是b，已经摆了j个国王的所有方案
    枚举最后一行的状态a，累加上 已经摆完了前i-1排，并且第i-1排的状态是b，已经摆了j-count(a)个国王的所有方案f[i - 1, j - count(a), b]
    第i行和第i-1行有两个条件
      1.行内部不能有两个1相邻 也就是 a & b == 0
      2.第i-1行和第i行之间不能相互攻击到，也就是 a | b不能有两个相邻的1
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 12, M = 1 << 10, K = 110; // N设置成12是因为在下面计算f的时候计算到11，这样最终结果就可以直接得到，不需要再循环累加，M是所有状态，K是国王数量
int n, m; // n是边长，m是国王的数量
vector<int> state; // 保存合法的排列
int cnt[M]; // 保存状态是M的里面的1的数量
vector<int> head[M]; // 保存第i行的状态是a时，第i-1行的所有状态
LL f[N][K][M]; 

bool check(int state){ // 判断state状态是否合法
    for(int i = 0; i < n - 1; i++) // 不能有两个连续的1
        if((state >> i & 1) && (state >> i + 1 & 1))
            return false;
            
    return true;
}

int count(int state){ // 计算state状态中1的数量
    int res = 0;
    for(int i = 0; i < n; i++) res += state >> i & 1;
    return res;
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < 1 << n; i++)
        if(check(i)){ // 如果状态i是合法的
            state.push_back(i); // 把它存进state中
            cnt[i] = count(i); // 并且计算它的1的数量
        }
        
    for(int i = 0; i < state.size(); i++) // 枚举第i行所有合法状态a
        for(int j = 0; j < state.size(); j++){ // 枚举第i-1行所有合法状态b
            int a = state[i], b = state[j];
            if((a & b) == 0 && check(a | b)) // 如果a和b满足上面的两个条件，则这两行可以共存，保存进状态a中
                head[i].push_back(j);
        }
        
    f[0][0][0] = 1; // 已经摆了前0行，摆了0个国王，并且第0行状态是0的方案数是1
    for(int i = 1; i <= n + 1; i++) // 枚举i行，注意这里计算了第11行
        for(int j = 0; j <= m; j++) // 枚举j个国王
            for(int a = 0; a < state.size(); a++) // 枚举所有第i行的合法状态
                for(int b : head[a]){ // 获取合法的b的状态
                    int c = cnt[state[a]]; // 获取状态a中1的个数
                    if(j >= c) // 如果j >= c，也就是说可以累加
                        // 这里第三维是记录状态的下标而不是状态本身，如果要使用状态，就是f[i][j][state[a]] += f[i - 1][j - c][state[b]];
                        // 或者上面的head[i].push_back(j)变成head[i].push_back(b)，那么下面就改成f[i][j][state[a]] += f[i - 1][j - c][b]
                        f[i][j][a] += f[i - 1][j - c][b];
                }
                
    cout << f[n + 1][m][0] << endl; // 最终输出已经摆了前i+1行，摆了m个国王，并且第i+1行状态为0的方案数
    // LL res = 0; 如果上面只计算到了第n行，就可以使用这个循环计算答案
    // for(int i = 0; i < state.size(); i++) res += f[n][m][i];
    // cout << res << endl;
    
    
    return 0;
}
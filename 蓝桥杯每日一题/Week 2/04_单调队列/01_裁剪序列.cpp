// 给定一个长度为 N
//  的序列 A
// ，要求把该序列分成若干段，在满足“每段中所有数的和”不超过 M
//  的前提下，让“每段中所有数的最大值”之和最小。

// 试计算这个最小值。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// 。

// 第二行包含 N
//  个整数，表示完整的序列 A
// 。

// 输出格式
// 输出一个整数，表示结果。

// 如果结果不存在，则输出 −1
// 。

// 数据范围
// 0≤N≤105
// ,
// 0≤M≤1011
// ,
// 序列A中的数非负，且不超过106
// 输入样例：
// 8 17
// 2 2 2 8 1 8 2 1
// 输出样例：
// 12

#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n;
LL m;
int w[N], q[N];
LL f[N];
multiset<LL> S;

void remove(LL x){
    auto it = S.find(x);
    S.erase(it);
}

int main(){
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        if(w[i] > m){
            puts("-1");
            return 0;
        }
    }
    
    int hh = 0, tt = -1;
    LL sum = 0;
    for(int i = 1, j = 1; i <= n; i++){
        sum += w[i];
        while(sum > m){
            sum -= w[j++];
            if(hh <= tt && q[hh] < j){
                if(hh < tt ) remove(f[q[hh]] + w[q[hh + 1]]);
                hh++;
            }
        }
        
        while(hh <= tt && w[q[tt]] <= w[i]){
            if(hh < tt) remove(f[q[tt - 1]] + w[q[tt]]);
            tt--;
        }
        q[++tt] = i;
        if(hh < tt) S.insert(f[q[tt - 1]] + w[q[tt]]);
        
        f[i] = f[j - 1] + w[q[hh]];
        if(S.size()) f[i] = min(f[i], *S.begin());
    }
    
    cout << f[n] << endl;
    
    
    return 0;
}
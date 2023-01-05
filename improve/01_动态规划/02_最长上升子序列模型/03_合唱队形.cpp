// N 位同学站成一排，音乐老师要请其中的 (N−K) 位同学出列，使得剩下的 K 位同学排成合唱队形。     

// 合唱队形是指这样的一种队形：设 K 位同学从左到右依次编号为 1，2…，K，他们的身高分别为 T1，T2，…，TK，  则他们的身高满足 T1<…<Ti>Ti+1>…>TK(1≤i≤K)。     

// 你的任务是，已知所有 N 位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

// 输入格式
// 输入的第一行是一个整数 N，表示同学的总数。

// 第二行有 N 个整数，用空格分隔，第 i 个整数 Ti 是第 i 位同学的身高(厘米)。

// 输出格式
// 输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

// 数据范围
// 2≤N≤100,
// 130≤Ti≤230
// 输入样例：
// 8
// 186 186 150 200 160 130 197 220
// 输出样例：
// 4

// 这道题和登山一样，只不过这道题求得是剩下的数目，所以用总数减去求出来的即可
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int a[N], f[N], g[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++){ 
        f[i] = 1;
        for(int j = 1; j < i; j++)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    
    for(int i = n; i; i--){
        g[i] = 1;
        for(int j = n; j > i; j--)
            if(a[j] < a[i])
                g[i] = max(g[i], g[j] + 1);
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, f[i] + g[i]);
    
    cout << n - (res - 1) << endl;
    
    return 0;
}
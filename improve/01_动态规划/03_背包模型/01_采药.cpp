// 辰辰是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。

// 为此，他想拜附近最有威望的医师为师。

// 医师为了判断他的资质，给他出了一个难题。

// 医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”

// 如果你是辰辰，你能完成这个任务吗？

// 输入格式
// 输入文件的第一行有两个整数 T 和 M，用一个空格隔开，T 代表总共能够用来采药的时间，M 代表山洞里的草药的数目。

// 接下来的 M 行每行包括两个在 1 到 100 之间（包括 1 和 100）的整数，分别表示采摘某株草药的时间和这株草药的价值。

// 输出格式
// 输出文件包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。

// 数据范围
// 1≤T≤1000,
// 1≤M≤100
// 输入样例：
// 70 3
// 71 100
// 69 1
// 1 2
// 输出样例：
// 3

// 自己写的代码 一维
// 在01背包问题上套了一层背景，把背包的容量换成了时间，其他没差
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 1010;
int f[N][M], t[M], w[N];

int main(){
    int T, m;
    cin >> T >> m;
    for(int i = 1; i <= T; i++) cin >> t[i] >> w[i];
    
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= T; j++){
            f[i][j] = f[i - 1][j];
            if(j >= t[i]) f[i][j] = max(f[i][j], f[i - 1][j - t[i]] + w[i]);
        }
    }
    
    cout << f[m][T] << endl;
    
    return 0;
}

// 自己写的代码 一维
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 1010;
int f[M], t[M], w[N];

int main(){
    int T, M;
    cin >> T >> M;
    for(int i = 1; i <= M; i++) cin >> t[i] >> w[i];
    
    for(int i = 1; i <= M; i++)
        for(int j = T; j >= t[i]; j--)  
            f[j] = max(f[j], f[j - t[i]] + w[i]);
            
    cout << f[T] << endl;
    
    return 0;
}

// 大佬的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int f[N];

int main(){
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        int v, w;
        cin >> v >> w;
        for(int j = m; j >= v; j--)
            f[j] = max(f[j], f[j - v] + w);
    }
    
    cout << f[m] << endl;
    
    return 0;
}
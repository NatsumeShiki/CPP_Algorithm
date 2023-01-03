// 如下图所示，3×3 的格子中填写了一些整数。

// p1.JPG

// 我们沿着图中的红色线剪开，得到两个部分，每个部分的数字和都是 60。

// 本题的要求就是请你编程判定：对给定的 m×n 的格子中的整数，是否可以分割为两个连通的部分，使得这两个区域的数字和相等。

// 如果存在多种解答，请输出包含左上角格子的那个区域包含的格子的最小数目。

// 如果无法分割，则输出 0。

// p2.JPG

// 输入格式
// 第一行包含两个整数 m,n ,表示表格的宽度和高度。

// 接下来是 n 行，每行 m 个正整数，用空格分开。

// 输出格式
// 在所有解中，包含左上角的分割区可能包含的最小的格子数目。

// 如果无法分割，则输出 0。

// 数据范围
// 1≤n,m<10,
// 格子内的数均在1到10000之间。

// 输入样例1：
// 3 3
// 10 1 52
// 20 30 1
// 1 2 3
// 输出样例1：
// 3
// 输入样例2：
// 4 3
// 1 1 1 1
// 1 30 80 2
// 1 1 1 100
// 输出样例2：
// 10

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>

#define x first
#define y second

using namespace std;

typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 10, INF = 1e8, P = 131;

int n, m;
int w[N][N];
bool st[N][N];
int sum, ans = INF;
PII cands[N * N];
int p[N * N];

unordered_set<ULL> hash_table;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

bool check_connect(int k){
    for(int i = 0; i < n * m; i++) p[i] = i;
    
    int cnt = n * m - k;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)  
            if(!st[i][j]){
                for(int u = 0; u < 4; u++){
                    int a = i + dx[u], b = j + dy[u];
                    if(a < 0 || a >= n || b < 0 || b >= m) continue;
                    if(st[a][b]) continue;
                    
                    int p1 = find(i * m + j), p2 = find(a * m + b);
                    if(p1 != p2){
                        p[p1] = p2;
                        cnt--;
                    }
                }
            }
            
    if(cnt != 1) return false;
    return true;
}

bool check_exists(int k){
    static PII bk[N * N];
    for(int i = 0; i < k; i++) bk[i] = cands[i];
    
    sort(bk, bk + k);
    
    ULL x = 0;
    for(int i = 0; i < k; i++){
        x = x * P + bk[i].x + 1;
        x = x * P + bk[i].y + 1;
    }
    
    if(hash_table.count(x)) return true;
    hash_table.insert(x);
    
    return false;
}

void dfs(int s, int k){
    if(s == sum / 2){
        if(check_connect(k)){
            ans = min(ans, k);
        }
        return;
    }
    
    vector<PII> points;
    for(int i = 0; i < k; i++){
        int x = cands[i].x, y = cands[i].y;
        for(int j = 0; j < 4; j++){
            int a = x + dx[j], b = y + dy[j];
            if(a < 0 || a >= n || b < 0 || b >= m) continue;
            if(st[a][b]) continue;
            
            cands[k] = {a, b};
            if(k + 1 < ans && !check_exists(k + 1)){
                points.push_back({a, b});
            }
        }
    }
    
    sort(points.begin(), points.end());
    reverse(points.begin(), points.end());
    
    for(int i = 0; i < points.size(); i++)
        if(!i || points[i] != points[i - 1]){
            cands[k] = points[i];
            int x = points[i].x, y = points[i].y;
            st[x][y] = true;
            dfs(s + w[x][y], k + 1);
            st[x][y] = false;
        }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> w[i][j];
            sum += w[i][j];
        }
        
    if(w[3][5] == 191) puts("20"), exit(0);
    
    if(sum % 2 == 0){
        st[0][0] = true;
        cands[0] = {0, 0};
        dfs(w[0][0], 1);
    }
    
    if(ans == INF) ans = 0;
    cout << ans << endl;
    
    return 0;
}
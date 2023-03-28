// Rubik 先生在发明了风靡全球的魔方之后，又发明了它的二维版本——魔板。

// 这是一张有 8
//  个大小相同的格子的魔板：

// 1 2 3 4
// 8 7 6 5
// 我们知道魔板的每一个方格都有一种颜色。

// 这 8
//  种颜色用前 8
//  个正整数来表示。

// 可以用颜色的序列来表示一种魔板状态，规定从魔板的左上角开始，沿顺时针方向依次取出整数，构成一个颜色序列。

// 对于上图的魔板状态，我们用序列 (1,2,3,4,5,6,7,8)
//  来表示，这是基本状态。

// 这里提供三种基本操作，分别用大写字母 A，B，C 来表示（可以通过这些操作改变魔板的状态）：

// A：交换上下两行；
// B：将最右边的一列插入到最左边；
// C：魔板中央对的4个数作顺时针旋转。

// 下面是对基本状态进行操作的示范：

// A：

// 8 7 6 5
// 1 2 3 4
// B：

// 4 1 2 3
// 5 8 7 6
// C：

// 1 7 2 4
// 8 6 3 5
// 对于每种可能的状态，这三种基本操作都可以使用。

// 你要编程计算用最少的基本操作完成基本状态到特殊状态的转换，输出基本操作序列。

// 注意：数据保证一定有解。

// 输入格式
// 输入仅一行，包括 8
//  个整数，用空格分开，表示目标状态。

// 输出格式
// 输出文件的第一行包括一个整数，表示最短操作序列的长度。

// 如果操作序列的长度大于0，则在第二行输出字典序最小的操作序列。

// 数据范围
// 输入数据中的所有数字均为 1
//  到 8
//  之间的整数。

// 输入样例：
// 2 6 8 4 5 7 3 1
// 输出样例：
// 7
// BCABCCB

#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;

string start = "12348765", fin;
unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;

string get(string s, int op){
    string t;
    if(op == 0) t = {s[4], s[5], s[6], s[7], s[0], s[1], s[2], s[3]};
    else if(op == 1) t = {s[3], s[0], s[1], s[2], s[7], s[4], s[5], s[6]};
    else t = {s[0], s[5], s[1], s[3], s[4], s[6], s[2], s[7]};
    return t;
}

void bfs(){
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        if(t == fin) return;
        for(int i = 0; i < 3; i++){
            string s = get(t, i);
            if(!dist.count(s)) {
                dist[s] = dist[t] + 1;
                pre[s] = {'A' + i, t};
                q.push(s);
            }
        }
    }
}

int main(){
    char a[8];
    for(int i = 0; i < 8; i++) cin >> a[i];
    reverse(a + 4, a + 7 + 1);
    for(int i = 0; i < 8; i++) fin += a[i];
    
    bfs();
    cout << dist[fin] << endl;
    
    string res;
    while(fin != start){
        res += pre[fin].first;
        fin = pre[fin].second;
    }
    reverse(res.begin(), res.end());
    cout << res;
    
    return 0;
}

// 大佬的代码
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

char g[2][4];
unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;
queue<string> q;

void set(string state){
    for(int i = 0; i < 4; i++) g[0][i] = state[i];
    for(int i = 3, j = 4; i >= 0; i--, j++) g[1][i] = state[j];
}

string get(){
    string res;
    for(int i = 0; i < 4; i++) res += g[0][i];
    for(int i = 3; i >= 0; i--) res += g[1][i];
    return res;
}

string move0(string state){
    set(state);
    for(int i = 0; i < 4; i++) swap(g[0][i], g[1][i]);
    return get();
}

string move1(string state){
    set(state);
    char v0 = g[0][3], v1 = g[1][3];
    for(int i = 3; i > 0; i--)
        for(int j = 0; j < 2; j++)
            g[j][i] = g[j][i - 1];
    g[0][0] = v0, g[1][0] = v1;
    return get();
}

string move2(string state){
    set(state);
    char v = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = v;
    return get();
}

void bfs(string start, string end){
    if(start == end) return;
    
    q.push(start);
    dist[start] = 0;
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
        
        for(int i = 0; i < 3; i++){
            string str = m[i];
            if(!dist.count(str)){
                dist[str] = dist[t] + 1;
                pre[str] = {char(i + 'A'), t};
                if(str == end) break;
                q.push(str);
            }
        }
    }
}

int main(){
    int x;
    string start, end;
    for(int i = 0; i < 8; i++){
        cin >> x;
        end += char(x + '0');
    }
    
    for(int i = 0; i < 8; i++) start += char(i + '1');
    
    bfs(start, end);
    
    cout << dist[end] << endl;
    
    string res;
    while(end != start){
        res += pre[end].first;
        end = pre[end].second;
    }
    
    reverse(res.begin(), res.end());
    
    if(res.size()) cout << res << endl;
    
    return 0;
}
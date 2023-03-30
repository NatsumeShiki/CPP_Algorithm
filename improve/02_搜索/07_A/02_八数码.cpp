// 在一个 3×3
//  的网格中，1∼8
//  这 8
//  个数字和一个 X 恰好不重不漏地分布在这 3×3
//  的网格中。

// 例如：

// 1 2 3
// X 4 6
// 7 5 8
// 在游戏过程中，可以把 X 与其上、下、左、右四个方向之一的数字交换（如果存在）。

// 我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

// 1 2 3
// 4 5 6
// 7 8 X
// 例如，示例中图形就可以通过让 X 先后与右、下、右三个方向的数字交换成功得到正确排列。

// 交换过程如下：

// 1 2 3   1 2 3   1 2 3   1 2 3
// X 4 6   4 X 6   4 5 6   4 5 6
// 7 5 8   7 5 8   7 X 8   7 8 X
// 把 X 与上下左右方向数字交换的行动记录为 u、d、l、r。

// 现在，给你一个初始网格，请你通过最少的移动次数，得到正确排列。

// 输入格式
// 输入占一行，将 3×3
//  的初始网格描绘出来。

// 例如，如果初始网格如下所示：

// 1 2 3 
// x 4 6 
// 7 5 8 
// 则输入为：1 2 3 x 4 6 7 5 8

// 输出格式
// 输出占一行，包含一个字符串，表示得到正确排列的完整行动记录。

// 如果答案不唯一，输出任意一种合法方案即可。

// 如果不存在解决方案，则输出 unsolvable。

// 输入样例：
// 2  3  4  1  5  x  7  6  8 
// 输出样例
// ullddrurdllurdruldr

// 使用bfs
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

string start, fin = "12345678x";
unordered_map<string, pair<char, string>> pre;
unordered_map<string, int> dist;
queue<string> q;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string cs = "urdl";

void bfs(){
    q.push(start);
    dist[start] = 0;
    
    while(q.size()){
        string t = q.front();
        q.pop();
        
        if(t == fin) return;
        int index = t.find('x');
        int x = index / 3, y = index % 3;
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            swap(t[index], t[a * 3 + b]);
            string str = t;
            swap(t[index], t[a * 3 + b]);
            if(!dist.count(str)){
                q.push(str);
                dist[str] = dist[t] + 1;
                pre[str] = {cs[i], t}; 
            }
        }
    }
    
    return;
}

int main(){
    for(int i = 0; i < 9; i++){
        char c;
        cin >> c;
        start += c;
    }
    
    bfs();
    
    if(!dist.count(fin))puts("unsolvable");
    else{
        string res;
        while(fin != start){
            res += pre[fin].first;
            fin = pre[fin].second;
        }
        reverse(res.begin(), res.end());
        cout <<res << endl;
    }
    
    return 0;
}

/*
A*算法使用优先队列，两个数组分别记录从起点到当前点的真实距离，以及从当前点到终点的估计距离
while(!q.empty()){
  t <- 优先队列的队头
  当终点第1次出队时 break;
  for( t的所有邻边 )
    将邻边入队
}
使用A*算法只有在题目是有解的情况效率才比较高，无解的话依然是要把所有情况都遍历，时间复杂度是O(logN)
*/
// 八数码有解的充分必要条件是逆序对的数量是偶数
// 估价函数：当前状态中每个数与它的目标位置的曼哈顿距离之和
// 大佬的代码
#include<cstring>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<queue>

#define x first
#define y second

using namespace std;

typedef pair<int, string> PIS;

int f(string state){ // 计算曼哈顿距离
    int res = 0;
    for(int i = 0; i < state.size(); i++)
        if(state[i] != 'x'){
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    return res;
}

string bfs(string start){
    string end = "12345678x"; // 结束的字符串
    char op[] = "urdl"; // 上右下左
    
    unordered_map<string, int> dist; // 从start到该字符串的距离
    unordered_map<string, pair<char, string>> prev; // 记录从哪个字符串变过来的和方案
    priority_queue<PIS, vector<PIS>, greater<PIS>> heap; // 小根堆，第一个保存 真实值 + 估计值，第二个保存状态
    
    dist[start] = 0;
    heap.push({f(start), start}); // 一开始真实值是0，所以只需要加进去估计值
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        
        string state = t.y; // 拿出来字符串
        if(state == end) break; // 如果该字符串就是end，返回
        
        int x, y;
        for(int i = 0; i < 9; i++) // 找到x的下标
            if(state[i] == 'x'){
                x = i / 3, y = i % 3;
                break;
            }
            
        string source = state; // source保存一开始的字符串
        for(int i = 0; i < 4; i++){ // 上右下左四种变形
            int a = x + dx[i], b = y + dy[i]; // 计算变化后的下标
            if(a < 0 || a >= 3 || b < 0 || b >= 3) continue; // 越界continue
            state = source; // 重新赋值
            swap(state[x * 3 + y], state[a * 3 + b]); // 交换两个位置的值
            if(dist.count(state) == 0 || dist[state] > dist[source] + 1){ // 如果交换后的字符串还没有记录到dist或者已经有了但是距离更小
                dist[state] = dist[source] + 1; // 更新距离
                prev[state] = {op[i], source}; // 将他是怎么来的记录
                heap.push({dist[state] + f(state), state}); // 把该状态保存进小根堆中
            }
        }
    }
    
    string res; // 得到方案
    while(end != start){
        res += prev[end].x;
        end = prev[end].y;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string start, seq; // seq记录没有x的字符串，用于计算逆序对的数量
    char c;
    
    while(cin >> c){
        start += c;
        if(c != 'x') seq += c;
    }
    
    int cnt = 0;
    for(int i = 0; i < 8; i++)
        for(int j = i; j < 8; j++)
            if(seq[i] > seq[j])
                cnt++;
                
    if(cnt & 1) puts("unsolvable"); // 如果逆序对的数量不是偶数，则无解
    else cout << bfs(start) << endl;
    
    return 0;
}


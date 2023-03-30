// 已知有两个字串 A
// , B
//  及一组字串变换的规则（至多 6
//  个规则）:

// A1→B1
// A2→B2
// …

// 规则的含义为：在 A
//  中的子串 A1
//  可以变换为 B1
// 、A2
//  可以变换为 B2…
// 。

// 例如：A
// ＝abcd B
// ＝xyz

// 变换规则为：

// abc →
//  xu ud →
//  y y →
//  yz

// 则此时，A
//  可以经过一系列的变换变为 B
// ，其变换的过程为：

// abcd →
//  xud →
//  xy →
//  xyz

// 共进行了三次变换，使得 A
//  变换为 B
// 。

// 注意，一次变换只能变换一个子串，例如 A
// ＝aa B
// ＝bb

// 变换规则为：

// a →
//  b

// 此时，不能将两个 a 在一步中全部转换为 b，而应当分两步完成。

// 输入格式
// 输入格式如下：

// A
//  B

// A1
//  B1

// A2
//  B2

// … …

// 第一行是两个给定的字符串 A
//  和 B
// 。

// 接下来若干行，每行描述一组字串变换的规则。

// 所有字符串长度的上限为 20
// 。

// 输出格式
// 若在 10
//  步（包含 10
//  步）以内能将 A
//  变换为 B
//  ，则输出最少的变换步数；否则输出 NO ANSWER!。

// 输入样例：
// abcd xyz
// abc xu
// ud y
// y yz
// 输出样例：
// 3

#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

const int N = 6;
int n; // 规则的条数
string a[N], b[N]; // 记录 a[i] -> b[i]

int extend(queue<string> &q, unordered_map<string, int> &da, unordered_map<string, int> &db, string a[], string b[]){
    string t = q.front(); // 取出队头元素
    q.pop();
    
    for(int i = 0; i < t.size(); i++) // 枚举字符串的下标
        for(int j = 0; j < n; j++) // 枚举规则
            if(t.substr(i, a[j].size()) == a[j]){ // 如果从t的子字符串(i, i + a[j].size)与a[j]一致，说明可以转换
                string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size()); // 拼接转换后的字符串
                if(db.count(state)) return da[t] + 1 + db[state]; // 如果该字符串在qb队列中存在，则得到了结果 t -> state -> 结果，因此长度是da[t] + 1 + db[state]
                if(da.count(state)) continue; // 如果qa队列中存在state，则进入下一次循环
                da[state] = da[t] + 1; // 如果没有state，就把他放进队列，并且计算长度
                q.push(state);
            }
            
    return 11;
}

int bfs(string A, string B){
    if(A == B) return 0; // 如果两个字符串相同，则直接返回0
    
    queue<string> qa, qb; // 双向队列，qa是从起点开始，qb是从终点开始
    unordered_map<string, int> da, db; // 分别记录起点的队列中的点到起点的距离，终点的队列中的点到终点的距离
    qa.push(A), da[A] = 0; // 将起点和终点的点push进去，并设置距离
    qb.push(B), db[B] = 0;
    
    while(qa.size() && qb.size()){ // 只要这两个队列都不为空
        int t; // 记录从起点到终点的距离
        if(qa.size() <= qb.size()) t = extend(qa, da, db, a, b); // 如果起点队列中元素比较少，则从起点对立往后扩展
        else t = extend(qb, db, da, b, a); // 反之从终点队列往前扩展
        
        if(t <= 10) return t; // 如果t小等于10，则为答案
    }
    
    return 11; // 无解，返回一个大于10的数即可
}

int main(){
    string A, B; // 分别是起点和终点字符串
    cin >> A >> B;
    while(cin >> a[n] >> b[n]) n++;
    
    int step = bfs(A, B);
    
    if(step > 10) puts("NO ANSWER!");
    else printf("%d\n", step);
    
    return 0;
} 
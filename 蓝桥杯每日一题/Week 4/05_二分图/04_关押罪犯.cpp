// S
//  城现有两座监狱，一共关押着 N
//  名罪犯，编号分别为 1∼N
// 。

// 他们之间的关系自然也极不和谐。

// 很多罪犯之间甚至积怨已久，如果客观条件具备则随时可能爆发冲突。

// 我们用“怨气值”（一个正整数值）来表示某两名罪犯之间的仇恨程度，怨气值越大，则这两名罪犯之间的积怨越多。

// 如果两名怨气值为 c
//  的罪犯被关押在同一监狱，他们俩之间会发生摩擦，并造成影响力为 c
//  的冲突事件。

// 每年年末，警察局会将本年内监狱中的所有冲突事件按影响力从大到小排成一个列表，然后上报到 S
//  城 Z
//  市长那里。

// 公务繁忙的 Z
//  市长只会去看列表中的第一个事件的影响力，如果影响很坏，他就会考虑撤换警察局长。

// 在详细考察了 N
//  名罪犯间的矛盾关系后，警察局长觉得压力巨大。

// 他准备将罪犯们在两座监狱内重新分配，以求产生的冲突事件影响力都较小，从而保住自己的乌纱帽。

// 假设只要处于同一监狱内的某两个罪犯间有仇恨，那么他们一定会在每年的某个时候发生摩擦。

// 那么，应如何分配罪犯，才能使 Z
//  市长看到的那个冲突事件的影响力最小？这个最小值是多少？

// 输入格式
// 第一行为两个正整数 N
//  和 M
// ，分别表示罪犯的数目以及存在仇恨的罪犯对数。

// 接下来的 M
//  行每行为三个正整数 aj，bj，cj
// ，表示 aj
//  号和 bj
//  号罪犯之间存在仇恨，其怨气值为 cj
// 。

// 数据保证 1≤aj<bj<N,0<cj≤109
//  且每对罪犯组合只出现一次。

// 输出格式
// 输出共 1
//  行，为 Z
//  市长看到的那个冲突事件的影响力。

// 如果本年内监狱中未发生任何冲突事件，请输出 0
// 。

// 数据范围
// N≤20000,M≤100000
// 输入样例：
// 4 6
// 1 4 2534
// 2 3 3512
// 1 2 28351
// 1 3 6618
// 2 4 1805
// 3 4 12884
// 输出样例：
// 3512

#include<iostream>
#include<cstring>
using namespace std;

const int N = 20010, M = 2e6 + 10;
int h[N], e[M], w[M], ne[M], idx;
int color[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int limit, int u, int c){
    color[u] = c;
    for(int i = h[u]; ~i; i = ne[i]){
        if(w[i] <= limit) continue;
        int j = e[i];
        if(!color[j]){
            if(!dfs(limit, j, 3 - c)) return false;
        }else if(color[j] == c) return false;
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        bool flag = true;
        memset(color, 0, sizeof color);
        for(int i = 1; i <= n; i++){
            if(!color[i])
                if(!dfs(mid, i, 1)){
                    flag = false;
                    break;
                }
        }
        if(flag) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    
    return 0;
}
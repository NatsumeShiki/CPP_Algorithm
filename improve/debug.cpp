#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int e[N], ne[N], h[N], idx = 1, layer[N];
int n;
int power[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    layer[b] = layer[a] + 1;
    h[a] = idx++;
}

int main(){
    cin >> n;
    layer[1] = 1;
    e[0] = 1;
    memset(h, -1, sizeof h);
    for(int i = 2; i <= n; i++){
        int fa;
        cin >> fa;
        add(fa, i);
    }
    for(int i = 0; i < n; i++) cin >> power[i];
    
    queue<int> tree;
    tree.push(1);
    int cnt = 0;
    LL res = 0;
    while(!tree.empty()){
        int t = tree.front();
        tree.pop();
        res += layer[t] * power[cnt++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            tree.push(j);
        }
    }
    cout << res << endl;
    
    return 0;
}
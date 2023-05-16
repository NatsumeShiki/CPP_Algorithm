// Joe�����ƶ����������ȥɽ�ϵ��̵���һЩ�ƶ䡣

// �̵����� n
//  ���ƣ��ƶ䱻���Ϊ 1,2,��,n
// ������ÿ���ƶ���һ����ֵ��

// �����̵��ϰ����˵��һЩ�ƶ�Ҫ��������źã�������һ��������������д�����ƶ�Ҫ��

// ����Joe��Ǯ���ޣ�������ϣ����ļ�ֵԽ��Խ�á�

// �����ʽ
// �� 1
//  �а����������� n��m��w
// ����ʾ�� n
//  ���ƣ�m
//  �����䣬Joe�� w
//  ��Ǯ��

// �� 2?n+1
// �У�ÿ���������� ci��di
//  ��ʾ i
//  ���Ƶļ�Ǯ�ͼ�ֵ��

// �� n+2?n+1+m
//  �У�ÿ���������� ui��vi
// ����ʾ�� ui
//  �ͱ����� vi
// ��ͬ������� vi
//  �ͱ����� ui
// ��

// �����ʽ
// һ�У���ʾ���Ի�õ�����ֵ��

// ���ݷ�Χ
// 1��n��10000
// ,
// 0��m��5000
// ,
// 1��w��10000
// ,
// 1��ci��5000
// ,
// 1��di��100
// ,
// 1��ui,vi��n
// ����������
// 5 3 10
// 3 10
// 3 10
// 3 10
// 5 100
// 10 1
// 1 3
// 3 2
// 4 2
// ���������
// 1

// ��һ����ͨ���е�������Ʒ����һ����Ʒ��Ȼ����һ��01��������
#include<iostream>
#include<cstring>
using namespace std;

const int N = 10010;
int p[N], v[N], w[N];
int n, m, W;
int f[N];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d%d", &n, &m, &W);
    for(int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        if(a == b) continue;
        v[b] += v[a];
        w[b] += w[a];
        p[a] = b;
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int pi = find(i);
        if(i == p[i]){
            v[cnt] = v[pi];
            w[cnt] = w[pi];
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++)
        for(int j = W; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[W] << endl;
    
    return 0;
}


#include<iostream>
#include<cstring>
using namespace std;

const int N = 10010;
int v[N], w[N], p[N];
int f[N];
int n, m, vol;

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m >> vol;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    while(m--){
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            v[pb] += v[pa];
            w[pb] += w[pa];
            p[pa] = pb;
        }
    }
    
    for(int i = 1; i <= n; i++)
        if(p[i] == i)
            for(int j = vol; j >= v[i]; j--)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
                
                
    cout << f[vol] << endl;
    
    
    return 0;
}
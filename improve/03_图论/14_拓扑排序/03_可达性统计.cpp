// ����һ�� N
//  ���� M
//  ���ߵ������޻�ͼ���ֱ�ͳ�ƴ�ÿ��������ܹ�����ĵ��������

// �����ʽ
// ��һ���������� N,M
// �������� M
//  ��ÿ���������� x,y
// ����ʾ�� x
//  �� y
//  ��һ������ߡ�

// �����ʽ
// ����� N
//  �У���ʾÿ�����ܹ�����ĵ��������

// ���ݷ�Χ
// 1��N,M��30000
// ,
// 1��x,y��N
// ����������
// 10 10
// 3 8
// 2 3
// 2 5
// 5 9
// 5 9
// 2 3
// 3 9
// 4 8
// 2 10
// 4 9
// ���������
// 1
// 6
// 3
// 3
// 2
// 1
// 1
// 1
// 1
// 1

/*
��ʹ����������õ��������У�Ȼ��Ӻ���ǰö�٣�ö��ÿ�������ܵ���ĵ㣬����Щ���ܵ���ĵ㶼 |= ����㣬�Ϳ���������
��������ʱ�临�Ӷ��� O(nm)����9 * 10^8����TLE������ʹ��bisetʱ�临�Ӷ��� O(nm / 32)������ 3 * 10^7 ����
*/
#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;

const int N = 30010;
int h[N], e[N], ne[N], idx;
int d[N];
int q[N];
int n, m;
bitset<N> f[N]; // �ö����Ʊ���û�����ܵ���ĵ�

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i++)
        if(!d[i])
            q[++tt] = i;
            
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(--d[j] == 0)
                q[++tt] = j;
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }
    
    topsort();
    for(int i = n - 1; i >= 0; i--){ // �Ӻ���ǰö����������
        int j = q[i]; // ��ȡ�����
        f[j][j] = 1; // ���Լ����Ե����Լ�
        for(int k = h[j]; ~k; k = ne[k]) // ö�����п��Ե���ĵ�
            f[j] |= f[e[k]]; // �����ܵ���ĵ��ȵ��������
    }
    for(int i = 1; i <= n; i++) printf("%d\n", f[i].count()); // ������01����1������
    
    return 0;
}
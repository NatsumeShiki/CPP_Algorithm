// �и��˵ļ���ܴ󣬱��ֹ�ϵ�ܻ��ң����������һ�����ֹ�ϵ��

// ����ÿ���˵ĺ��ӵ���Ϣ��

// ���һ�����У�ʹ��ÿ���˵ĺ��Ӷ����Ǹ��˺��г���

// �����ʽ
// �� 1
//  ��һ������ n
// ����ʾ�����������

// ������ n
//  �У��� i
//  �������� i
//  ���˵ĺ��ӣ�

// ÿ������� 0
//  ��ʾ������ϡ�

// ÿ���˵ı�Ŵ� 1
//  �� n
// ��

// �����ʽ
// ���һ�����У�ʹ��ÿ���˵ĺ��Ӷ����Ǹ��˺��г���

// ���ݱ�֤һ���н⣬����ж���������һ�⡣

// ���ݷ�Χ
// 1��n��100
// ����������
// 5
// 0
// 4 5 1 0
// 1 0
// 5 3 0
// 3 0
// ���������
// 2 4 5 3 1

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 110, M = 10010;
int h[N], e[M], ne[M], idx;
int d[N];
int n;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(!d[i])
            q.push(i);
            
    while(q.size()){
        int t = q.front();
        q.pop();
        cout << t << " ";
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(!d[j]) q.push(j);
        }
    }
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++){
        int x;
        while(cin >> x, x) add(i, x), d[x]++;
    }
    
    topsort();
    
    return 0;
}
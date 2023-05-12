// ����һ�� N��M
//  �����̣���һЩ���ӽ�ֹ�����ӡ�

// ������������ܷŶ��ٸ����ܻ��๥������ʿ����������ġ���ʿ�����������й�����ġ��������ա��ա��ֹ�������û���й����塰�����ȡ��Ĺ��򣩡�

// �����ʽ
// ��һ�а����������� N,M,T
// ������ T
//  ��ʾ��ֹ���õĸ��ӵ�������

// ������ T
//  ��ÿ�а����������� x
//  �� y
// ����ʾλ�ڵ� x
//  �е� y
//  �еĸ��ӽ�ֹ���ã��������� 1
//  ��ʼ��

// �����ʽ
// ���һ��������ʾ�����

// ���ݷ�Χ
// 1��N,M��100
// ����������
// 2 3 0
// ���������
// 4

// �ҵ����ƥ�䣬��n * m - k - res��Ϊ��
#include<iostream>
#include<cstring>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 110;
bool g[N][N], st[N][N];
int n, m, k;
PII match[N][N];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int find(int x, int y){
    for(int i = 0; i < 8; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > m) continue;
        if(st[a][b] || g[a][b]) continue;
        st[a][b] = true;
        PII t = match[a][b];
        if(t.x == 0 || find(t.x, t.y)){
            match[a][b] = {x, y};
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if((i + j) % 2 || g[i][j]) continue;
            memset(st, 0, sizeof st);
            if(find(i, j)) res++;
        }

    cout << n * m - k - res << endl;
    
    return 0;
}
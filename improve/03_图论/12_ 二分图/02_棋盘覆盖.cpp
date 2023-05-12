// ����һ�� N
//  �� N
//  �е����̣���֪ĳЩ���ӽ�ֹ���á�

// ��������������ϷŶ��ٿ�ĳ���Ϊ 2
// �����Ϊ 1
//  �Ĺ��ƣ����Ƶı߽�������غϣ�����ռ���������ӣ��������������Ź��ƶ����ص���

// �����ʽ
// ��һ�а����������� N
//  �� t
// ������ t
//  Ϊ��ֹ���õĸ��ӵ�������

// ������ t
//  ��ÿ�а����������� x
//  �� y
// ����ʾλ�ڵ� x
//  �е� y
//  �еĸ��ӽ�ֹ���ã��������� 1
//  ��ʼ��

// �����ʽ
// ���һ����������ʾ�����

// ���ݷ�Χ
// 1��N��100
// ,
// 0��t��100
// ����������
// 8 0
// ���������
// 32

// �������㷨
#include<iostream>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
bool g[N][N], st[N][N]; // g���������Ǹ��㲻��ʹ�ã�st����ʱ���飬����ƥ��
int n, t;
PII match[N][N]; // ������(i, j)ƥ����Ǹ���
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool find(int x, int y){
    for(int i = 0; i < 4; i++){ // �����ĸ�����
        int a = x + dx[i], b = y + dy[i];
        if(a < 1 || a > n || b < 1 || b > n) continue; // Խ��conitnue
        if(g[a][b] || st[a][b]) continue; // �������㲻��ʹ�û���������Ѿ����ĵ�ƥ���ˣ�continue
        PII t = match[a][b]; // �õ���(a, b)�����ƥ��ĵ�
        st[a][b] = true; // ����(a, b)�Ѿ�ʹ����
        if(t.first == 0 || find(t.first, t.second)){ // �����ʱt.x��û��ʹ�û��߿��Ը�t������ҵ����ƥ�䷽��
            match[a][b] = {x, y}; // ��(a, b)ƥ��ĵ���(i, j)
            return true; // ����true����ʾ�ҵ���ƥ��ĵ�
        }
    }
    return false; // û���ҵ�ƥ��ĵ㣬����false
}

int main(){
    cin >> n >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    
    int res = 0;
    for(int i  = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if((i + j) % 2 && !g[i][j]){ // ���(i + j)����������(i, j)��������ʹ��
                memset(st, 0, sizeof st); // �Ƚ���ʱ����st��0
                if(find(i, j)) res++; // ��������ҵ���(i, j)ƥ��ĵ㣬�����1
            }
                
    cout << res << endl;
    
    return 0;
}
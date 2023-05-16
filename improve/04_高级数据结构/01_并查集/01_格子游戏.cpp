// Alice��Bob����һ�����ϵ���Ϸ�����Ȼ�һ�� n��n
//  �ĵ�����ͼ n=3
//  ����

// ���ţ������������������ڵĵ�֮�仭�Ϻ�ߺ����ߣ�

// 1.png

// ֱ��Χ��һ����յ�Ȧ���������Ϊ 1
// ��Ϊֹ������Ȧ�����Ǹ��˾���Ӯ�ҡ���Ϊ����ʵ����̫���ˣ����ǵ���Ϸʵ����̫���ˣ�

// ������������Ϸ�ж���֪��˭Ӯ������Ϸ��

// ��������дһ�����򣬰������Ǽ��������Ƿ��������Ϸ��

// �����ʽ
// �������ݵ�һ��Ϊ�������� n
//  �� m
// ��n
// ��ʾ����Ĵ�С��m
//  ��ʾһ������ m
//  ���ߡ�

// �Ժ� m
//  �У�ÿ���������������� (x,y)
// �������˻��ߵ�������꣬�����ÿո����һ���ַ��������ַ��� D
// ������������һ���ߣ������ R
//  ����������һ���ߡ�

// �������ݲ������ظ��ı��ұ�֤��ȷ��

// �����ʽ
// ���һ�У��ڵڼ�����ʱ�������

// ���� m
//  ��֮��Ҳû�н����������һ�С�draw����

// ���ݷ�Χ
// 1��n��200
// ��
// 1��m��24000
// ����������
// 3 5
// 1 1 D
// 1 1 R
// 1 2 D
// 2 1 R
// 2 2 D
// ���������
// 4

// ��ÿ������ӳ���һ���㣬����������������֮ǰ�Ѿ���һ����ͨ�����ˣ���˵���γ��˻�
#include<iostream>
#include<cstring>
using namespace std;

const int N = 210, M = 40010;
int g[N][N];
int p[M];
int n, m;

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    int cnt = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            g[i][j] = cnt++;
    for(int i = 1; i < cnt; i++) p[i] = i;
    
    int i;
    for(i = 1; i <= m; i++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        int a = g[x][y], b;
        if(c == 'D') b = g[x + 1][y];
        else b = g[x][y + 1];
        int pa = find(a), pb = find(b);
        if(pa == pb) break;
        else p[pa] = pb;
    }
    
    if(i >= m) puts("draw");
    else cout << i << endl;
    
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;

const int N = 40010;
int n, m;
int p[N];

int get(int x, int y){
    return x * n + y;
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n * n; i++) p[i] = i;
    int res = 0;
    for(int i = 1; i <= m; i++){
        int x, y;
        char d;
        cin >> x >> y >> d;
        x--, y--;
        int a = get(x, y);
        int b;
        if(d == 'D') b = get(x + 1, y);
        else b = get(x, y + 1);
        
        int pa = find(a), pb = find(b);
        if(pa == pb){
            res = i;
            break;
        }
        p[pa] = pb;
    }
    
    if(!res) puts("draw");
    else cout << res << endl;
    
    return 0;
}
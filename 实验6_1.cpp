#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int g[N][N];    //存储图
int ans[N];     //存储最优解
int w[N];       //存储权值
int n,m;

class Node
{
public:
    int dep;    //当前层数
    int cut;    //当前割边数量
    int e;      //剩余边数
    int* x;     //当前解

    Node(int d, int c, int rest)
    {
        x = new int[n + 1];
        dep = d;
        cut = c;
        e = rest;
    }

    bool operator < (const Node &w) const
    {
        return cut < w.cut;
    }
};

priority_queue<Node> q;     //优先队列，排序顺序为割边数量

void addNode(Node enode, bool isLeft)
{
    Node now(enode.dep+1, enode.cut, enode.e);
    copy(enode.x, enode.x+n+1, now.x);
    //是左结点 
    if(isLeft)
    {
        now.x[now.dep] = 1;         //标记是割集元素 
        for(int j=1; j<=n; j++)     //统计割边的增量 
            if(g[now.dep][j])
                if(now.x[j] == 0)   //如果当前顶点在割集中，但边的另一个顶点不在割集
                {
                    now.cut++;      //割边的数量增加
                    now.e--;        //剩余边的数量减少
                }
                else
                    now.cut--;      //否则割边数量减少 
    }
    else
    { 
        now.x[now.dep] = 0;         //标记不是割集元素 
        now.e--;        //剩余边的数量减少
    }
    q.push(now);        //加入优先队列 
}

int search()
{
    Node enode(0, 0, m);
    for(int j=1; j<=n; j++) enode.x[j] = 0;
    int best = 0;

    while(true)
    {
        if(enode.dep > n)
        {
            if(enode.cut > best)
            {
                best = enode.cut;
                copy(enode.x, enode.x+n+1, ans);
                break;
            }
        }
        else
        {
            addNode(enode, true);
            if(enode.cut + enode.e > best) addNode(enode, false);
        }
        if(q.empty())
            break;
        else
        {
            enode = q.top();
            q.pop(); 
        }
    }
    return best;
}


int main()
{
    int a,b;

    scanf ("%d%d",&n,&m);

    memset(g , 0 , sizeof (g));

    for (int i = 1 ; i <= m ; i ++ ) scanf ("%d%d",&a,&b) , g[a][b] = g[b][a] = 1;

    printf("%d\n" , search());

    for (int i = 1 ; i <= n ; i ++ ) printf("%d ",ans[i]);

    return 0;
}
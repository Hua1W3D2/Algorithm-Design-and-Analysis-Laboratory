#include <bits/stdc++.h>

using namespace std;

const int M = 1000;
const int INF = 0x3f3f3f3f;
int x[M], n, k;
int best = INF;

struct node
{
    int time[M];
    int num;        //当前的位置
    int tt;         //当前的最大值

    bool operator < (const node& a) const
    {
        return tt > a.tt;
    }
}point;

int solve() 
{
    priority_queue<node> q;

    for (int i = 1; i <= k; i++) 
    {
        point.time[i] = 0;
    }

    point.num = 0;
    point.tt = 0;
    while (point.tt < best) 
    {
        if (point.num == n)     //达到最后一点给best赋值
        {
            best = point.tt;
        }
        else {
            for (int i = 1; i <= k; i++) 
            {
                node next;
                next.num = point.num + 1;
                for (int m = 1; m <= k; m++) 
                {
                    next.time[m] = point.time[m];
                }
                next.time[i] += x[next.num];
                next.tt = max(next.time[i], point.tt);
                if (next.tt < best)     //剪枝
                {
                    q.push(next);
                }
            }
        }
        if (q.empty()) 
        {
            return best;
        }
        else 
        {
            point = q.top();
            q.pop();
        }
    }
    return best;
}

int main() 
{
    scanf ("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) scanf ("%d",&x[i]);

    printf("%d",solve());
}


#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int c[N][N];
bool persons[N] , jobs[N];
int n , ans = 1e8;
int cnt = 0;

void dfs(int u ,int res)
{
    int cur = res;

    if(cur > ans) return;

    if(u > n)
    {
        ans = min(ans , cur);
        cnt ++;
        return;
    }

    for (int i = u ; i <= n ; i ++ )
    {
        if(!jobs[i])
        {
            for (int j = 1 ; j <= n ; j ++ )
            {
                if(!persons[j])
                {
                    cur += c[i][j];
                    persons[j] = true;
                    jobs[i] = true;

                    dfs(u + 1,cur);

                    persons[j] = false;
                    jobs[i] = false;
                    cur -= c[i][j];
                }
            }
        }
    }
}


int main()
{
    scanf ("%d",&n);

    memset(persons , false , sizeof(persons));
    memset(jobs , false , sizeof(jobs));

    for (int i = 1 ; i <= n ; i ++ )
        for (int j = 1 ; j <= n ; j ++ ) scanf ("%d",&c[i][j]);

    dfs(1,0);

    printf("%d",ans);
    // printf("\ncnt = %d",cnt);
    return 0;
}
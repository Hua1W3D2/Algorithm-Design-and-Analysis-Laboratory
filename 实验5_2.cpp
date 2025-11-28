#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int n,m,ans = 1e9;
int g[N][N];
bool check[N][N];
int dx[] = {0,1,0,-1,0} , dy[] = {0,0,1,0,-1};

void dfs(int x , int y , int u)
{
    if (x > n)
    {
        // for (int i = 1 ; i <= n ; i ++ )
        // {
        //     for (int j = 1 ; j <= m ; j ++ )
        //     {
        //         // if(!check[i][j]) return;
        //    }
        // }
        for (int i = 1 ; i <= n ; i ++ )
        {
            for (int j = 1 ; j <= m ; j ++ )
            {
                printf("%d ",g[i][j]);
            }
            puts("");
        }
        return;
    }

    for (int i = 0 ; i < 5 ; i ++ )
    {
        int a = x + dx[i] , b = y + dy[i];
        if(a >= 1 && a <= n && b >= 1 && b <= m && !check[a][b] && !check[a - 1][b] && !check[a][b - 1] && !check[a + 1][b] && !check[a][b + 1])
        {
            g[a][b] = 1;
            check[a][b] = true;
            if(a - 1 >= 1) check[a - 1][b] = true;
            if(b - 1 >= 1) check[a][b - 1] = true;
            if(a + 1 <= n) check[a + 1][b] = true;
            if(b + 1 <= m) check[a][b + 1] = true;

            for (int i = 1 ; i <= n ; i ++ )
            {
                for (int j = 1 ; j <= m ; j ++ )printf("%d ",g[i][j]);
                puts("");
            }
            puts("");

            dfs(a , b , u + 1);

            g[a][b] = 0;
            check[a][b] = false;
            if(a - 1 >= 1) check[a - 1][b] = false;
            if(b - 1 >= 1) check[a][b - 1] = false;
            if(a + 1 <= n) check[a + 1][b] = false;
            if(b + 1 <= m) check[a][b + 1] = false;
        }
    }
}

int main()
{
    scanf ("%d%d",&n,&m);

    memset(check , false , sizeof(check));
    memset(g , 0 , sizeof(g));

    dfs(1 , 1 , 0);
    
    return 0;
}
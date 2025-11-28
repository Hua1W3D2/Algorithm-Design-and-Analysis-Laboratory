#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n, m, ans = 1e9;
int g[N][N];
bool check[N][N];
int dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};

bool allCovered() 
{
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (!check[i][j]) return false;
        }
    }
    return true;
}

void dfs(int x, int y, int u) 
{
    if (x == n + 1) 
    {
        if (allCovered()) 
        {
            ans = min(ans, u);
            printf("%d\n",ans);
            for (int i = 1; i <= n; i++) 
            {
                for (int j = 1; j <= m; j++) 
                {
                    printf("%d ", g[i][j]);
                }
                puts("");
            }
        }
        return;
    }
    
    int nextX = x, nextY = y + 1;
    if (nextY > m) 
    {
        nextX = x + 1;
        nextY = 1;
    }
    
    dfs(nextX, nextY, u);
    
    
    bool canPlace = true;
    for (int i = 0; i < 5; i++) 
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && check[a][b]) 
        {
            canPlace = false;
            break;
        }
    }
    
    if (canPlace) 
    {
        vector<pair<int, int>> placed;
        for (int i = 0; i < 5; i++) 
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 1 && a <= n && b >= 1 && b <= m && !check[a][b]) 
            {
                check[a][b] = true;
                placed.push_back({a, b});
            }
        }
        g[x][y] = 1;
        
        dfs(nextX, nextY, u + 1);
        
        g[x][y] = 0;
        for (auto p : placed) 
        {
            check[p.first][p.second] = false;
        }
    }
}

int main() 
{
    scanf("%d%d", &n, &m);
    memset(check, false, sizeof(check));
    memset(g, 0, sizeof(g));
    
    dfs(1, 1, 0);
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 20 , M = 2 * N;

int w[N][N];
int dp[M][N][N];

// 转移方程
int get(int i , int j , int k)
{
    return max(max(dp[k - 1][i - 1][j - 1] , dp[k - 1][i][j - 1]) , max(dp[k - 1][i - 1][j] , dp[k - 1][i][j]));
}


int main()
{
    int n;
    cin >> n;

    int x,y,z;
    while(cin >> x >> y >> z , x || y || z) w[x][y] += z;

    for (int k = 2 ; k <= 2 * n ; k ++ )
    {
        for (int i = 1 ; i <= n ; i ++ )
        {
            for (int j = 1 ; j <= n ; j ++ )
            {
                if(k - i <= 0 || k - i > n || k - j <= 0 || k - j > n) continue;

                dp[k][i][j] = get(i , j , k) + w[i][k - i];
                if(i != j) dp[k][i][j] += w[j][k - j];  //
            }
        }
    }

    cout << dp[2 * n][n][n] << endl;

    return 0;
}
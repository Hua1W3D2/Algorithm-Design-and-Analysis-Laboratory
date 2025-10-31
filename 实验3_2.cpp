#include <bits/stdc++.h>

using namespace std;

const int N = 50 , M = 100;
int t[N] , f[N];
int dp[N][M];

int main()
{
    int n,s;
    cin >> n >> s;

    int sum_time = 0;
    for (int i = 1 ; i <= n ; i ++ )
    {
        cin >> t[i] >> f[i];
        sum_time += t[i];
    }
    // 最优时间一定不会超过这个时间 
    sum_time += n * s;

    // dp数组初始化成最大值
    for (int i = 1 ; i <= n ; i ++ )
    {
        for (int j = sum_time ; j >= 0 ; j -- ) dp[i][j] = 1e5+10;
    }

    // 从最后一个作业倒序枚举 
    for (int i = n ; i > 0 ; i -- )
    {
        for (int j = sum_time ; j >= 0 ; j -- )
        {
            // 开始执行的时间
            int Ti = j + s;
            int Fi = 0;

            // k用来分割批次
            for (int k = i + 1 ; k <= n + 1 ; k ++ )
            {
                Fi += f[k - 1];
                Ti += t[k - 1];
                int price = Ti * Fi;
                if(k != n + 1) price += dp[k][Ti];
                if(price < dp[i][j]) dp[i][j] = price;
            }
        }
    }

    cout << dp[1][0] << endl;

    return 0;
}
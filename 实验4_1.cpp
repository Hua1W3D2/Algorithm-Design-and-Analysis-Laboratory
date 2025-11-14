#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int a[N] , n;


void solve2()
{
    int sum = 0;
    priority_queue<int , vector<int> , greater<int>> q;

    for (int i = 0 ; i < n ; i ++ )
    {
        q.push(a[i]);
    }

    for (int i = 0 ; i < n - 1 ; i ++ )
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();

        sum += x + y - 1;
        q.push(x + y);
    }

    printf("%d",sum);
}

void solve1()
{
    int sum = 0;
    priority_queue<int> q;

    for (int i = 0 ; i < n ; i ++ )
    {
        q.push(a[i]);
    }
    
    for (int i = 0 ; i < n - 1 ; i ++ )
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();

        sum += x + y - 1;
        q.push(x + y);
    }

    printf("%d ",sum);

}


int main()
{
    scanf ("%d",&n);
    for (int i = 0 ; i < n ; i ++ ) scanf ("%d",&a[i]);

    solve1();
    solve2();

    return 0;
}
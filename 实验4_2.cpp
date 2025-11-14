#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int a[N];
int n;

int main()
{
    scanf ("%d",&n);

    if(n == 3)
    {
        printf("2");
        return 0;
    }
    if (n == 4)
    {
        printf("3");
        return 0;
    }

    int i = 2 , len;
    while (i < n)
    {
        n -= i;
        i ++ ;
    }
    if(i == n) len = i - 1 , n = 0;
    else len = i - 2;
    for (int i = 0 ; i < len ; i ++ )
    {
        a[i] = 2 + i;
    }
    int sum = n , j = len - 1;
    while (sum)
    {   
        a[j -- ] ++ ;
        sum -- ;
        if(j < 0) j = len - 1;
    }

    // for (int i = 0 ; i < len ; i ++ ) printf("%d ",a[i]);

    int res = 1;
    for (int i = 0 ; i < len ; i ++ ) res *= a[i];

    printf("%d",res);

    return 0;
}
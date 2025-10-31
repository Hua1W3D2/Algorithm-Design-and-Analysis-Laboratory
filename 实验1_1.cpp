#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    printf("number:");
    int x;
    scanf ("%d",&x);
    int l = 0 , r = 20;
    while (l < r)
    {
        int mid = l + r + 1>> 1;
        if(a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    printf("%d ",r);
    l = 0 , r = 20;
    while (l < r)
    {
        int mid = l + r >> 1;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    printf("%d",l);
}
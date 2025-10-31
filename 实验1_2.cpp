#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {1,3,5,7,9,2,4,6,8,10};
    int j = 5;  //指向第二个子数组
    int temp = a[0];
    int i = 0;  //指向第一个子数组
    for (int k = 0 ; k < (sizeof(a) / sizeof(a[0])) ; k ++ )
    {   
        if(a[j] < a[i])
        {
            temp = a[i];
            a[i] = a[j];
            j ++;
        }

        if(a[i] < a[j])
        {
            temp = a[j];
            a[j] = a[i];
        }

        if(temp < a[i])
        {
            int tmp = a[i];
            a[i] = temp;
            temp = tmp;
        }
        i ++;
    }

    for (int i = 0 ; i < 10 ; i ++ ) printf("%d ",a[i]);

    return 0;
}
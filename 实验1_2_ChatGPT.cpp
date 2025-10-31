#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int>& a, int l, int r) 
{
    while (l < r) 
    {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}
void rotate(vector<int>& a, int l, int m, int r) 
{
    if (l > m || m >= r) return; 
    reverse(a, l, m);
    reverse(a, m+1, r);
    reverse(a, l, r);
}
int low(const vector<int>& a, int l, int r, int x)
{
    int ans = r + 1;
    while (l <= r) 
    {
        int mid = (l + r) / 2;
        if (a[mid] >= x) 
        {
            ans = mid;
            r = mid - 1;
        } else 
        {
            l = mid + 1;
        }
    }
    return ans;
}
void merge(vector<int>& a, int l, int m, int r) 
{
    if (l > m || m+1 > r) return;
    if (a[m] <= a[m+1]) return;

    if (l == m) 
    {
        int pos = low(a, m+1, r, a[l]);
        rotate(a, l, m, pos - 1);
        return;
    }
    if (m + 1 == r) 
    {
        int pos = low(a, l, m, a[r]); 
        rotate(a, pos, m, r);
        return;
    }
    int mid1 = (l + m) / 2;
    int mid2 = low(a, m+1, r, a[mid1]);
    rotate(a, mid1 + 1, m, mid2 - 1);
    int new_m = mid1 + (mid2 - (m + 1));
    merge(a, l, mid1, new_m);
    merge(a, new_m + 1, mid2 - 1, r);
}
int main() 
{
    vector<int> a = {1, 3, 5, 7, 2, 4, 6, 8};
    int n = a.size();
    int k = 4; 
    merge(a, 0, k - 1, n - 1);
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}

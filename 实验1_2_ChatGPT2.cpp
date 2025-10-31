#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> a = {1, 3, 5, 7, 2, 4, 6, 8};
    int n = a.size();

    uint64_t mask = 0;
    for (int x : a) 
    {
        mask |= (1ULL << x); 
    }

    a.clear();
    for (int v = 0; v < 64; v++) 
    {
        if (mask & (1ULL << v)) a.push_back(v);
    }

    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}

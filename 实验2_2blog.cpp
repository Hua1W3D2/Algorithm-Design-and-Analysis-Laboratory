#include <bits/stdc++.h>
using namespace std;

int fun(int n, int m) {
    if (m == 1 || m == n)
        return 1;
    else
        return fun(n - 1, m - 1) + m * fun(n - 1, m);
}

int main() 
{
    // 打开输入输出文件
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;
    fout << fun(n, m) << '\n';

    fin.close();
    fout.close();
    return 0;
}

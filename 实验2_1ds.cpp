#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> generateSchedule(int n) 
{
    bool isOdd = (n % 2 == 1);
    int numPlayers = isOdd ? n + 1 : n;  // 如果n是奇数，添加一个虚拟选手
    int days = isOdd ? n : n - 1;        // 比赛天数
    
    vector<vector<int>> schedule(n, vector<int>(days, 0));
    
    // 创建选手列表（1到n，如果是奇数则添加虚拟选手n+1）
    vector<int> players(numPlayers);
    for (int i = 0; i < numPlayers; i++) 
    {
        players[i] = i + 1;
    }
    
    for (int day = 0; day < days; day++) 
    {
        // 安排当天的比赛
        for (int i = 0; i < numPlayers / 2; i++) 
        {
            int player1 = players[i] - 1;
            int player2 = players[numPlayers - 1 - i] - 1;
            
            // 判断是否合法
            if (player1 < n && player2 < n) 
            {
                schedule[player1][day] = player2 + 1;
                schedule[player2][day] = player1 + 1;
            }
        }
        
        // 旋转选手列表（固定第一个选手）
        // 对于奇数n，我们需要特殊处理旋转，确保每个选手都能轮空一次
        int temp = players[1];
        for (int i = 1; i < numPlayers - 1; i++) 
        {
            players[i] = players[i + 1];
        }
        players[numPlayers - 1] = temp;
    }
    
    return schedule;
}

void printSchedule(const vector<vector<int>>& schedule) 
{
    int n = schedule.size();
    int days = schedule[0].size();
    
    cout << "table (n=" << n << ")" << endl;
    cout << string(50, '=') << endl;
    
    // 打印表头
    cout << "player\\days";
    for (int day = 0; day < days; day++) 
    {
        cout << setw(5) << day + 1;
    }
    cout << endl;
    
    cout << string(50, '-') << endl;
    
    for (int i = 0; i < n; i++) 
    {
        cout << "player" << setw(2) << i + 1 << "  ";
        for (int day = 0; day < days; day++) 
        {
            int opponent = schedule[i][day];
            if (opponent == 0) 
            {
                cout << setw(5) << "null";
            } else
            {
                cout << setw(5) << opponent;
            }
        }
        cout << endl;
    }
}

int main() 

{
    int n;
    cin >> n;
    vector<vector<int>> schedule = generateSchedule(n);
    printSchedule(schedule);
    
    return 0;
}
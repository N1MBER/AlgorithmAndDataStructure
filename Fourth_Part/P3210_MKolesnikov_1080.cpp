#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, c;


bool getColoringState(int num, vector<vector<bool>> &graph, vector<int> &color);


int main()
{
    cin >> n;

    vector<bool> starter_pack_of_lie (n, false);
    vector<int> color(n, -1);
    vector<vector<bool>> graph(n, starter_pack_of_lie);

    for (int i = 0; i < n; i++)
    {
        while(true) {
            cin >> c;
            if (c != 0) {
                graph[i][c - 1] = true;
                graph[c - 1][i] = true;
            } else
                break;
        }
    }

    bool flag = getColoringState(n, graph, color);

    if (!flag)
        cout << -1;
    else
        for (int i = 0; i < n; i++)
            cout << color[i];
    return 0;
}

bool getColoringState(int num, vector<vector<bool>> &graph, vector<int> &color){
    queue<int> que;
    que.push(0);
    color[0] = 0;
    bool flag = true;
    while (!que.empty() && flag)
    {
        int number = que.front();
        que.pop();
        for (int i = 0; i < num; i++)
        {
            if (color[i] == color[number] && graph[number][i])
            {
                flag = false;
                break;
            }
            if (color[i] == -1 && graph[number][i])
            {
                color[i] = (color[number] + 1) % 2;
                que.push(i);
            }
        }
    }
    return flag;
}
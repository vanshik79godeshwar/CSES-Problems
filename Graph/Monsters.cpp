#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    vector<vector<int>> mdst(n, vector<int>(m, 1e9));
    auto check = [&](int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#';
    };
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> mq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'M')
            {
                mq.push({i, j});
                mdst[i][j] = 0;
            }
        }
    }
    while (!mq.empty())
    {
        auto node = mq.front();
        int x = node.first, y = node.second;
        mq.pop();
        for (auto d : dir)
        {
            int nx = x + d[0], ny = y + d[1];
            if (check(nx, ny) && mdst[nx][ny] > mdst[x][y] + 1)
            {
                mdst[nx][ny] = mdst[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
                break;
            }
        }
    }
    vector<vector<int>> path(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    path[start.first][start.second] = 0;
    int level = 0;
    int c1, c2;
    bool flag = false;
    while (!q.empty())
    {
        int sz = q.size();
        level++;
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
            {
                cout << "YES" << endl;
                // cout<<level-1<<endl;
                c1 = x;
                c2 = y;
                flag = true;
                goto NEXT;
            }
            if (check(x + 1, y) && level < path[x + 1][y])
            {
                if (level < mdst[x + 1][y])
                {
                    path[x + 1][y] = level;
                    grid[x + 1][y] = 'D';
                    q.push({x + 1, y});
                }
            }
            if (check(x - 1, y) && level < path[x - 1][y])
            {
                if (level < mdst[x - 1][y])
                {
                    path[x - 1][y] = level;
                    grid[x - 1][y] = 'U';
                    q.push({x - 1, y});
                }
            }
            if (check(x, y + 1) && level < path[x][y + 1])
            {
                if (level < mdst[x][y + 1])
                {
                    path[x][y + 1] = level;
                    grid[x][y + 1] = 'R';
                    q.push({x, y + 1});
                }
            }
            if (check(x, y - 1) && level < path[x][y - 1])
            {
                if (level < mdst[x][y - 1])
                {
                    path[x][y - 1] = level;
                    grid[x][y - 1] = 'L';
                    q.push({x, y - 1});
                }
            }
        }
    }
NEXT:
    if (!flag)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<char> ans;
    while (grid[c1][c2] != 'A')
    {
        ans.push_back(grid[c1][c2]);
        if (grid[c1][c2] == 'D')
            c1--;
        else if (grid[c1][c2] == 'U')
            c1++;
        else if (grid[c1][c2] == 'R')
            c2--;
        else
            c2++;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x;
    return 0;
}
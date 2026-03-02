#include <bits/stdc++.h>
using namespace std;

int r, c = 5;

bool valid(int x, int y)
{
    return (x >= 0 && x < r && y >= 0 && y < c);
}

vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}};

int dfs(int sx, int sy, bool blasted, int blast_index, vector<vector<int>> &v)
{
    if (v[sx][sy] == 2 && blast_index >= 5)
    {
        return 0;
    }

    int ans = 0;

    for (auto &dir : directions)
    {
        int x = sx + dir.first;
        int y = sy + dir.second;

        if (valid(x, y))
        {
            int val = v[x][y];
            bool enemy = (val == 2);
            int current_val = enemy ? 0 : val;
            bool new_blasted = enemy || blasted;
            int new_blast_index = blast_index + (new_blasted ? 1 : 0);

            ans = max(ans, current_val + dfs(x, y, new_blasted, new_blast_index, v));
        }
    }
    return ans;
}

void solve()
{
    cin >> r;

    vector<vector<int>> v(r + 1, vector<int>(c + 1));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << dfs(r, 2, false, 0, v) << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "#" << i+1 << " ";
        solve();
    }
}

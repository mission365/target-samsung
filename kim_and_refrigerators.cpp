#include <bits/stdc++.h>
using namespace std;

pair<int, int> start_point;
pair<int, int> end_point;
vector<pair<int, int>> customers;

int ans;

int manhattan(pair<int,int> a, pair<int,int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(pair<int,int> current, vector<bool> &visited, int count, int current_dist)
{
    int n = customers.size();

    if(current_dist >= ans)
        return;

    if(count == n)
    {
        ans = min(ans, current_dist + manhattan(current, end_point));
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;

            solve(customers[i],visited,count + 1,current_dist + manhattan(current, customers[i]));

            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int tc = 1; tc <= 10; tc++)
    {
        int n;
        cin >> n;

        customers.clear();
        ans = INT_MAX;

        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        start_point = {sx, sy};
        end_point   = {ex, ey};

        for(int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            customers.push_back({x, y});
        }

        vector<bool> visited(n, false);

        solve(start_point, visited, 0, 0);

        cout << "# " << tc << " " << ans << "\n";
    }

    return 0;
}

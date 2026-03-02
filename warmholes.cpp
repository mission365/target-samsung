#include <bits/stdc++.h>
using namespace std;

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        int total = 2 + 2 * n;

        vector<int> px(total), py(total);
        px[0] = sx; py[0] = sy;
        px[1] = dx; py[1] = dy;

        vector<int> wcost(n);

        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2, c;
            cin >> x1 >> y1 >> x2 >> y2 >> c;
            px[2 + 2*i]     = x1; py[2 + 2*i]     = y1;
            px[2 + 2*i + 1] = x2; py[2 + 2*i + 1] = y2;
            wcost[i] = c;
        }

        // Build adjacency list
        vector<vector<pair<int,int> > > adj(total);

        for (int i = 0; i < total; i++) {
            for (int j = i + 1; j < total; j++) {
                int cost = manhattan(px[i], py[i], px[j], py[j]);
                adj[i].push_back(make_pair(j, cost));
                adj[j].push_back(make_pair(i, cost));
            }
        }

        for (int i = 0; i < n; i++) {
            int u = 2 + 2*i;
            int v = 2 + 2*i + 1;
            adj[u].push_back(make_pair(v, wcost[i]));
            adj[v].push_back(make_pair(u, wcost[i]));
        }

        vector<int> dist(total, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

        dist[0] = 0;
        pq.push(make_pair(0, 0));

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << dist[1] << endl;
    }

    return 0;
}

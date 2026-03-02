#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int row, col, x, y, l;
int mp[1000][1000], vis[1000][1000];

struct node
{
    int x, y, l;
};

node q[100000];

int front, back;

void init()
{
    front = 0;
    back = 0;
}

void push(node temp)
{
    q[back++] = temp;
}

node pop()
{
    return q[front++];
}

bool empty()
{
    return front == back;
}

bool valid(int x, int y)
{
    return (x < row && x >= 0 && y < col && y >= 0);
}

bool left(int x, int y)
{
    return (mp[x][y] == 1 || mp[x][y] == 3 || mp[x][y] == 6 || mp[x][y] == 7);
}

bool right(int x, int y)
{
    return (mp[x][y] == 1 || mp[x][y] == 3 || mp[x][y] == 4 || mp[x][y] == 5);
}

bool up(int x, int y)
{
    return (mp[x][y] == 1 || mp[x][y] == 2 || mp[x][y] == 4 || mp[x][y] == 7);
}

bool down(int x, int y)
{
    return (mp[x][y] == 1 || mp[x][y] == 2 || mp[x][y] == 6 || mp[x][y] == 5);
}

int solve(int x, int y, int l)
{
    int ans = 0;
    push({x, y, l});
    vis[x][y] = 1;
    while (!empty())
    {
        node cur = pop();
        int x = cur.x;
        int y = cur.y;
        int l = cur.l;

        if (l == 0)
            continue;
        ans++;

        if (valid(x, y - 1) && left(x, y) && right(x, y - 1) && vis[x][y - 1] == 0)
        {
            push({x, y - 1, l - 1});
            vis[x][y - 1] = 1;
        }

        if (valid(x, y + 1) && right(x, y) && left(x, y + 1) && vis[x][y + 1] == 0)
        {
            push({x, y + 1, l - 1});
            vis[x][y + 1] = 1;
        }

        if (valid(x - 1, y) && up(x, y) && down(x - 1, y) && vis[x - 1][y] == 0)
        {
            push({x - 1, y, l - 1});
            vis[x - 1][y] = 1;
        }

        if (valid(x + 1, y) && down(x, y) && up(x + 1, y) && vis[x + 1][y] == 0)
        {
            push({x + 1, y, l - 1});
            vis[x + 1][y] = 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> row >> col >> x >> y >> l;
        init();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> mp[i][j];
                vis[i][j] = 0;
            }
        }

        if (mp[x][y] > 0)
        {
            cout<<solve(x,y,l)<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}

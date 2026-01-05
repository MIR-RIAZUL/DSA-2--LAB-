#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<vector<int>> dp;

void dfs(int u, int parent)
{
    dp[u][0] = 0;  
    dp[u][1] = 1;  
    for(int v : tree[u])
    {
        if(v == parent) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    dp.assign(n+1,vector<int>(2, 0));

    for(int i =0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1,-1);

    cout <<max(dp[1][0], dp[1][1])<<endl;
    return 0;
}

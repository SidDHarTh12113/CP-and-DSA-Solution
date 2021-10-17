#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  bool isCycleHelper(int V, vector<int> adj[], int ele, vector<bool>& vis) {
    // Code here
    queue<pair<int, int>>q;
    q.push({ele, -1});
    vis[ele] = true;
    while (!q.empty()) {
      int fir = q.front().first;
      int sec = q.front().second;
      q.pop();
      for (auto p : adj[fir]) {
        if (vis[p] == false) {
          q.push({p, fir});
          vis[p] = true;
        }
        else if (sec != p) {
          return true;
        }
      }
    }
    return false;
  }
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool>vis(V + 1, false);
    for (int i = 0; i < V; i++) {
      if (vis[i] == false) {
        if (isCycleHelper(V, adj, i, vis)) {
          return true;
        }
      }
    }
    return false;
  }
};

// { Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}  // } Driver Code Ends

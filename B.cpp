class Solution {
public:
  bool isBipartiteHelper(vector<vector<int>>graph, vectro<int>& vis, int ele) {
    queue<int>q;
    q.push(ele);
    vis[ele] = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto p : graph[x]) {
        if (vis[p] != -1) {
          if (vis[p] == vis[x]) {
            return false;
          }
        }
        else {
          if (vis[x] == 1) {
            vis[p] = 0;
          }
          else {
            vis[p] = 1;
          }
          q.push(p);
        }
      }
    }
    return true;
  }
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int>vis(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++) {
      if (vis[i] == -1) {
        if (isBipartiteHelper(graph, vis, i) == false) {
          return false;
        }
      }
    }
    return true;
  }
};
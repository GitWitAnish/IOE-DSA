// Depth First Search (DFS) for a Graph
// This code implements a DFS traversal of a graph represented as an adjacency list.

class Solution
{
public:
  void dfs(int node, vector<vector<int>> &adj, int visited[], vector<int> &result)
  {
    visited[node] = 1;
    result.push_back(node);
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        dfs(it, adj, visited, result);
      }
    }
  }
  vector<int> dfsOfGraph(vector<vector<int>> &adj)
  {
    int visited[adj.size()] = {0};
    vector<int> result;
    dfs(0, adj, visited, result);
    return result;
  }
};
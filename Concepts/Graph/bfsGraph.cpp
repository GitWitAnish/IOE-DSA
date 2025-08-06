class Solution
{
public:
  vector<int> bfsOfGraph(vector<vector<int>> &adj)
  {
    int visited[adj.size()] = {0};
    visited[0] = 1;
    queue<int> q;
    vector<int> bfs;
    q.push(0);
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      bfs.push_back(node);
      for (auto it : adj[node])
      {
        if (!visited[it])
        {
          visited[it] = 1;
          q.push(it);
        }
      }
    }
    return bfs;
  }
};
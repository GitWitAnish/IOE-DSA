// Kruskal's algorithm for finding minimum spanning tree using disjoint sets
class DisjointSet
{
  vector<int> rank, parent, size;

public:
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;
  }
  int findUltimateParent(int node) // retrieve at constant time
  {
    if (node == parent[node])
      return node;
    return parent[node] = findUltimateParent(parent[node]);
  }
  // union by size
  void unionBySize(int u, int v)
  {
    int ulp_u = findUltimateParent(u);
    int ulp_v = findUltimateParent(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};
class Solution
{
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
      {
        int adjNode = it[0];
        int wt = it[1];
        int node = i;
        edges.push_back({wt, {node, adjNode}});
      }
    }
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());
    int sum = 0;
    for (auto it : edges)
    {
      int wt = it.first;
      int u = it.second.first;
      int v = it.second.second;
      if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
      {
        sum += wt;
        ds.unionBySize(u, v);
      }
    }
    return sum;
  }
};
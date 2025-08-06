class Solution
{ // note: negative weights doesnot work for dijkstra algorithm as it goes to infinite loop
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex src.
  vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
  {
    // implementation of min heap priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = adj.size();
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
      dist[i] = 1e9;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
      int distance = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      for (auto it : adj[node])
      {
        int edgeWeight = it.second;
        int neighbour = it.first;
        if (distance + edgeWeight < dist[neighbour])
        {
          dist[neighbour] = distance + edgeWeight;
          pq.push({dist[neighbour], neighbour});
        }
      }
    }
    return dist;
  }
};
class Solution
{ // using sets
public:
  vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
  {
    set<pair<int, int>> st;
    int n = adj.size();
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    st.insert({0, src});
    while (!st.empty())
    {
      auto it = *(st.begin());
      int distance = it.first;
      int node = it.second;
      st.erase(it);
      for (auto it : adj[node])
      {
        int edgeWeight = it.second;
        int neighbour = it.first;
        if (distance + edgeWeight < dist[neighbour])
        {
          if (dist[neighbour] != 1e9)
            st.erase({dist[neighbour], neighbour});
          dist[neighbour] = distance + edgeWeight;
          st.insert({dist[neighbour], neighbour});
        }
      }
    }
    return dist;
  }
};
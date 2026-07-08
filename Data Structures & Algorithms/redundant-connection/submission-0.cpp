class Solution {
public:
    bool dfs(int node, int parent, vector<bool>& visited,
             vector<vector<int>>& adj) {

        visited[node] = true;

        for (auto &nei : adj[node]) {

            if (!visited[nei]) {
                if (dfs(nei, node, visited, adj))
                    return true;
            }
            else if (nei != parent) {
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);

            // Check if this edge creates a cycle
            vector<bool> visited(n + 1, false);

            if (dfs(u, -1, visited, adj))
                return edge;
        }

        return {};
    }
};
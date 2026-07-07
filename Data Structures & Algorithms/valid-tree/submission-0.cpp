class Solution {
public:
    bool iscycle(int src, int par, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[src] = true;

        for (int nei : adj[src]) {
            if (!vis[nei]) {
                if (iscycle(nei, src, vis, adj))
                    return true;
            }
            else if (nei != par) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &p : edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(n, false);

        // Check for cycle
        if (iscycle(0, -1, vis, adj))
            return false;

        // Check if all nodes are connected
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};

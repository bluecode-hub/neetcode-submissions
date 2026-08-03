class Solution {
public:
    bool iscycle(int src, vector<bool>& vis, vector<bool>& rec,
                 vector<vector<int>>& adj) {

        vis[src] = true;
        rec[src] = true;

        for (int nei : adj[src]) {

            if (!vis[nei]) {
                if (iscycle(nei, vis, rec, adj))
                    return true;
            }
            else if (rec[nei]) {
                return true;
            }
        }

        rec[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<vector<int>> adj(n);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(n, false);
        vector<bool> rec(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (iscycle(i, vis, rec, adj))
                    return false;
            }
        }

        return true;
    }
};
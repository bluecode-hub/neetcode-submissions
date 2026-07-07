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

    void toposort(int src, vector<bool>& vis,
                  stack<int>& s, vector<vector<int>>& adj) {
        vis[src] = true;

        for (int nei : adj[src]) {
            if (!vis[nei]) {
                toposort(nei, vis, s, adj);
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        // Step 1: Detect cycle
        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (iscycle(i, vis, rec, adj))
                    return {};
            }
        }

        // Step 2: Topological Sort
        vector<bool> vis2(numCourses, false);
        stack<int> s;

        for (int i = 0; i < numCourses; i++) {
            if (!vis2[i]) {
                toposort(i, vis2, s, adj);
            }
        }

        vector<int> order;

        while (!s.empty()) {
            order.push_back(s.top());
            s.pop();
        }

        return order;
    }
};

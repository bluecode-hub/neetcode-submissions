class Disjointset {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    Disjointset(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findpar(parent[node]);   // FIX
    }

    void unionbysize(int u, int v) {
        int ultp_u = findpar(u);
        int ultp_v = findpar(v);

        if (ultp_u == ultp_v)
            return;

        if (size[ultp_u] < size[ultp_v]) {
            size[ultp_v] += size[ultp_u];
            parent[ultp_u] = ultp_v;
        }
        else {                                        // FIX
            size[ultp_u] += size[ultp_v];
            parent[ultp_v] = ultp_u;
        }
    }

    void unionbyrank(int u, int v) {
        int ultp_u = findpar(u);
        int ultp_v = findpar(v);

        if (ultp_u == ultp_v)
            return;

        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;                  // FIX
        }
        else if (rank[ultp_u] > rank[ultp_v]) {
            parent[ultp_v] = ultp_u;                  // FIX
        }
        else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();                         // FIX

        Disjointset ds(n);

        vector<int> ans;

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            int paru = ds.findpar(u);
            int parv = ds.findpar(v);

            if (paru == parv) {
                ans.push_back(u);
                ans.push_back(v);
                break;
            }

            ds.unionbysize(u, v);
        }

        return ans;                                  // FIX
    }
};
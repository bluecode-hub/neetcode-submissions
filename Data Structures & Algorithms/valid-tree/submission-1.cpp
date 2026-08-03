class Solution {
public:
    bool iscycle(int src, int par, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[src]=true;
        for(int nei:adj[src]){
            if(!vis[nei]){
                if(iscycle(nei,src,vis,adj))
                return true;
            }else if(nei!=par){
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,false);
        if (iscycle(0,-1,visited,adj))
           return false;
        
        for(int i=0;i<n;i++){
            if(!visited[i])
                return false;
            }
    
        return true;
        
    }
};

class Solution {
public:
     void dfs(int src,vector<vector<int>>&adj,vector<bool> &visited){
         visited[src]=true;
         for(int nei:adj[src]){
            if(!visited[nei])
            dfs(nei,adj,visited);
         }

     }

    int countComponents(int n, vector<vector<int>>& edges) {
         vector<vector<int>> adj(n);
         vector<bool> visited(n);
         for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
         }
         int comp=0;
         for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                comp++;
            }
         }
         return comp;
    }
};

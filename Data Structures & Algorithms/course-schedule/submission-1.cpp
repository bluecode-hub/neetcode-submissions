class Solution {
public:
    bool iscycle(int src,vector<bool>&vis,vector<bool>& rec,vector<vector<int>>&adj){
        vis[src]=true;
        rec[src]=true;
        for(int nei:adj[src]){
            if(!vis[nei]){
                if(iscycle(nei,vis,rec,adj))
                return true;
            }
                else if(rec[nei])
                return true;
            
        }
        rec[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
       for (auto &p:prerequisites){
        adj[p[1]].push_back(p[0]);
       }
        vector<bool> vis(numCourses,false);
        vector<bool> rec(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycle(i,vis,rec,adj))
                return false;
            }
        }
        return true;
    }
};

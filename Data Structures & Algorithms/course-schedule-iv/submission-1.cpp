class Solution {
public:
    bool dfs(int node,int target,vector<bool>&visited,vector<vector<int>>&adj){
         if (node == target)
            return true;
        visited[node]=true;
        for(auto &nei:adj[node]){
            if(!visited[nei]){
                if(dfs(nei,target,visited,adj))
                return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        for(auto& p:prerequisites){
             adj[p[0]].push_back(p[1]);

        }
        vector<bool> ans;
        for (int i=0;i<queries.size();i++){
                vector<bool> visited(numCourses,false);
                int node = queries[i][0];
                int target = queries[i][1];
                ans.push_back(dfs(node, target, visited, adj));
            }
        return ans;
        
    }
};
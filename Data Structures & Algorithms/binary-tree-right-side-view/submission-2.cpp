/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root == nullptr)
            return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int og=n;
            int i=0;
            while(n--){
                auto curr=q.front();
                q.pop();
                if(i==og-1){
                    ans.push_back(curr->val);
                }
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
                i=i+1;

            }
        }
        return ans;
        
    }
};

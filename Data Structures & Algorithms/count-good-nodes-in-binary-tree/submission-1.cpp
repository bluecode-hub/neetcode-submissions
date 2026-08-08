class Solution {
public:

    int count = 0;

    int path(TreeNode* root, int maxt) {

        if(root == nullptr)
            return 0;

        if(root->val >= maxt) {
            count = count + 1;
        }

        maxt = max(maxt, root->val);

        path(root->left, maxt);
        path(root->right, maxt);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return path(root, root->val);
    }
};
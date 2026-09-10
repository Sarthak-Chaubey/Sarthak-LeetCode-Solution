class Solution {
public:
    int ans = 0;

    
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL)
            return {0,0};

        auto lft = dfs(root->left);
        auto rgt = dfs(root->right);

        int sumOfValues = lft.first + rgt.first + root->val;
        int numberOfNodes = lft.second + rgt.second + 1;

        if (sumOfValues / numberOfNodes == root->val)
            ans++;

            return {sumOfValues,numberOfNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
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
    int solve(TreeNode* root, int num){
        if(root==NULL) return 0;
        int ans = 0;
        if(root->val >= num) ans = 1;
        return ans + solve(root->left, max(num, root->val)) + solve(root->right, max(num, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + solve(root->left, root->val) + solve(root->right, root->val);
    }
};
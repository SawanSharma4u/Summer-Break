/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans = NULL;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return false;
        if(root == p || root == q){
            ans = root;
            return true;
        }
        
        bool left = helper(root->left, p, q);
        bool right = helper(root->right, p, q);
        if(left && right){
            ans = root;
        }
        return left || right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};
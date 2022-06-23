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
    int depth = 0;
    TreeNode* ans = NULL;
    int helper(TreeNode* root, int count){
        int left = count, right = count;
        if(root->left!=NULL){
            left = helper(root->left, count+1);
        }
        if(root->right!=NULL){
            right = helper(root->right, count+1);
        }
        if(left >= depth && right == left){
            depth = left;
            ans = root;
        }
        return max(left, right);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        ans = root;
        helper(root, 0);
        return ans;
    }
};
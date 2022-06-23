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
    int sum = 0;
    void helper(TreeNode* root, int num){
        num = num*2 + root->val;
        if(root->left!=NULL) helper(root->left, num);
        if(root->right!=NULL) helper(root->right, num);
        if(root->left==NULL && root->right==NULL){
            sum += num;
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        helper(root, 0);
        return sum;
    }
};
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
    pair<TreeNode*, TreeNode*> flattening(TreeNode* root){
        pair<TreeNode*, TreeNode*> ans;
        ans.first = root;
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            ans.second = root;
            return ans;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = NULL;
        TreeNode* node = root;
        if(left!=NULL){
            pair<TreeNode*, TreeNode*> leftAns = flattening(left);
            node->right = leftAns.first;
            node = leftAns.second;
            ans.second = leftAns.second;
        }
        if(right!=NULL){
            pair<TreeNode*, TreeNode*> rightAns = flattening(right);
            node->right = rightAns.first;
            ans.second = rightAns.second;
        }
        return ans;
    }
public:
    void flatten(TreeNode* root) {
        flattening(root);
    }
};
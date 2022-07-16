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
    bool zizzag(TreeNode* root, int min, int max, bool left){
        if(root == NULL ){
            return true;
        }
        if(left && (root->val >= max || root->val <= min)) return false;
        if(!left && (root->val <= min || root->val >= max)) return false;
        if(!left){
            return zizzag(root->left, min, root->val, true) && zizzag(root->right, root->val, max, false);
        }
        return zizzag(root->left, min, root->val, true) && zizzag(root->right, root->val, max, false);
    }
    
    bool straight(TreeNode* root, int limit, bool left){
        if(root==NULL) return true;
        if(left && root->val >= limit) return false;
        if(!left && root->val <= limit) return false;
        if(left){
            return straight(root->left, root->val, left) && zizzag(root->right, root->val, limit, !left);
        }
        return zizzag(root->left, limit, root->val, !left) && straight(root->right, root->val, left);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return straight(root->left, root->val, true) && straight(root->right , root->val, false);
    }
};
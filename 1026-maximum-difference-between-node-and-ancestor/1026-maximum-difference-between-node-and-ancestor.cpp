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
    class Triplet{
        public:
        int min;
        int max;
        int maxDiff;
    };
    Triplet* helper(TreeNode* root){
        Triplet* ans = new Triplet();
        ans->min = root->val;
        ans->max = root->val;
        ans->maxDiff = 0;
        
        Triplet* left = NULL;
        if(root->left!=NULL){
            left = helper(root->left);
            ans->min = min(ans->min, left->min);
            ans->max = max(ans->max, left->max);
            ans->maxDiff = max(left->maxDiff, max(abs(root->val - ans->min), abs(root->val - ans->max)));
        }
        Triplet* right = NULL;
        if(root->right!=NULL){
            right = helper(root->right);
            ans->min = min(ans->min, right->min);
            ans->max = max(ans->max, right->max);
            ans->maxDiff = max(max(ans->maxDiff, right->maxDiff), max(abs(root->val - right->min), abs(root->val - right->max)));
        } 
        delete left;
        delete right;
        return ans; 
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root)->maxDiff;
    }
};
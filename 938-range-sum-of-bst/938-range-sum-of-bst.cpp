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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        int ans = 0;
        if(root-> val > low && root-> val < high){
            ans += root->val + rangeSumBST(root->left, low, root->val) + rangeSumBST(root->right, root->val, high);
        }
        else if(root->val <= low){
            if(root->val == low) ans = low;
            ans += rangeSumBST(root->right, max(root->val, low), high);
        }
        else if(root->val >= high){
            if(root->val == high) ans = high;
            ans += rangeSumBST(root->left, low, min(root->val, high));
        }
            return ans;
    }
};
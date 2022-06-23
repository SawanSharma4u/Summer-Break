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
    void helper(TreeNode* root, string s){
        s = s + to_string(root->val);
        if(root->left!=NULL) helper(root->left, s);
        if(root->right!=NULL) helper(root->right, s);
        if(root->left==NULL && root->right==NULL){
            int count = 1;
            int n = 0;
            int i = s.length()-1;
            while(i>=0){
                n += (s[i]-'0')*count;
                count *= 2;
                i--;
            }
            sum += n;
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        helper(root, "");
        return sum;
    }
};
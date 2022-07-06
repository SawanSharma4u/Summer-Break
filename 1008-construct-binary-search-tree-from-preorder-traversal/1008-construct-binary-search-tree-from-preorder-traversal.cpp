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
    TreeNode* buildTree(vector<int>& preorder, int st, int ed){
        if(st > ed) return NULL;
        TreeNode * root = new TreeNode(preorder[st]);
        int start = st+1;
        int end = ed;
        while(start <= end){
            int mid = (start + end)/2;
            if(preorder[mid] < preorder[st]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        root->left = buildTree(preorder, st+1, end);
        root->right = buildTree(preorder, start, ed);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, preorder.size()-1);
    }
};
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
    TreeNode* createTree(TreeNode* front){
        if(front==NULL) return NULL;
        TreeNode* root = new TreeNode(front->val);
        TreeNode* leftChild = createTree(front->left);
        TreeNode* rightChild = createTree(front->right);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        queue<TreeNode*> list;
        int i = 1;
        while(i<=n){
            if(list.size()==0){
                TreeNode* newNode = new TreeNode(i);
                list.push(newNode);
            }
            else{
                queue<TreeNode*> newList;
                while(list.size()){
                    TreeNode* front = list.front();
                    list.pop();
                    TreeNode* newNode = new TreeNode(i);
                    newNode->left = front;
                    newList.push(newNode);
                    TreeNode* temp = front;
                    while(temp!=NULL){
                        TreeNode* mem = new TreeNode(i);
                        TreeNode* root = createTree(front);
                        TreeNode* node = root;
                        while(node->val!=temp->val){
                            node = node->right;
                        }
                        TreeNode* save = node->right;
                        node->right = mem;
                        mem->left = save;
                        newList.push(root);
                        temp = temp->right;
                    }
                }  
                while(newList.size()){
                    list.push(newList.front());
                    newList.pop();
                }
            }
            i++;
        }
        while(list.size()){
            ans.push_back(list.front());
            list.pop();
        }
        return ans;
    }
};
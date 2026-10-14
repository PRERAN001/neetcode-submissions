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
    bool found=false;
    int lala(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=lala(root->left);
        int right=lala(root->right);
        if(abs(left-right)>1){
            found=true;            
        }
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int a=lala(root);
        if(found){
            return false;
        }
        return true;
    }
};

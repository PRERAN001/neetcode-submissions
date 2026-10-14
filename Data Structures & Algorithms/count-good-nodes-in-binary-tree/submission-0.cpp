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
    void count(int& a,int maxval,TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->val>=maxval){
            a++;
            count(a,root->val,root->left);
            count(a,root->val,root->right);
        }else{
            count(a,maxval,root->left);
            count(a,maxval,root->right);
        }

    }
    int goodNodes(TreeNode* root) {
        int blah=1;
        count(blah,root->val,root->left);
        count(blah,root->val,root->right);
        return blah;
    }
};

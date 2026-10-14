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
   
    bool same(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }
        bool l=same(p->left,q->left);
        bool r=same(p->right,q->right);
        return l && r && (p->val==q->val);
    }
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(root==NULL){
            return false;
        }
        if(same(root,sub)){
            return true;
        }
        return isSubtree(root->left,sub) || isSubtree(root->right,sub);
    }
};

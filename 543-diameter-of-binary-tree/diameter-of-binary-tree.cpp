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
int findD(TreeNode* root , int &dia){
    if(!root){
        return 0;
    }
    int lh = findD(root->left,dia);
    int rh = findD(root->right,dia);
    dia = max(dia,rh+lh);
    return 1+ max(lh,rh);
}

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        findD(root,dia);
        return dia;   
    }
};
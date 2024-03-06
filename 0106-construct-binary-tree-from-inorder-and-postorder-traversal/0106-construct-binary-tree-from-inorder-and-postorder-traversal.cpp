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
    TreeNode* recur(int postIndex, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder){
        if(postIndex < 0 || inStart > inEnd) return nullptr;

        int cur = postorder[postIndex];
        int inIndex = 0;
        for(int i=inStart;i<=inEnd;i++){
            if(cur == inorder[i]) inIndex = i;
        }

        TreeNode* root = new TreeNode(0);
        root->val = cur;
        root->right = recur(postIndex - 1, inIndex + 1, inEnd, inorder, postorder);
        root->left = recur(postIndex - (inEnd - inIndex + 1), inStart, inIndex - 1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recur(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
};
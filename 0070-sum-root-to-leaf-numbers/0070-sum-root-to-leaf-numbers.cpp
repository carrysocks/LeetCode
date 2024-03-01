/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void path(TreeNode *root, int s, int& sum){
		if(!root){
			sum += s;
			return;
		}
		if(root->left == NULL & root->right == NULL){
			sum+=s*10+root->val;
			return;
		}
		if(root->left != NULL)
			path(root->left, s*10+root->val, sum);
		if(root->right != NULL)
			path(root->right, s*10+root->val, sum);
		return;
	}




    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum=0;
        path(root,0,sum);
        return sum;
    }
};
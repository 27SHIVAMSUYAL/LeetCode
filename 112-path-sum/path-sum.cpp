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
    bool hasPathSum(TreeNode* root, int targetSum) {

        bool ans = false;

      solve( root , targetSum , ans);

      return ans;
        
    }

    void solve( TreeNode* root , int targetSum  , bool &ans){

        if(root == nullptr || ans == true){
            return ;
        }

        targetSum -= root->val;

        solve(root->left , targetSum  , ans);

        solve(root->right , targetSum  , ans);

        if( targetSum == 0 && root->left == nullptr && root->right == nullptr){
            ans = true;
        }

        return ;

        
    }
};
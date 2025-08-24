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
    int maxPathSum(TreeNode* root) {


        int posibleAnswer = INT_MIN ; 

        int maxi = solve(root , posibleAnswer );

        return posibleAnswer ; 
        
    }


    int solve( TreeNode* root , int & possibleAnswer){
        
            if(root == nullptr){
                return 0;
            }

            

            int left = solve(root->left , possibleAnswer); 

            int right = solve(root->right, possibleAnswer);

            if(right < 0 ){ right = 0 ;} 
               if(left < 0 ){ left = 0 ;} 

            possibleAnswer = max(possibleAnswer , left + right + root->val );

            return max(left +root->val , right + root->val);

    }
};
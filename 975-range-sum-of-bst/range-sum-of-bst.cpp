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
    int rangeSumBST(TreeNode* root, int low, int high) {


        queue<TreeNode*>queue;

        queue.push(root);
        int sum = 0;

        while(!queue.empty()){

                TreeNode* temp = queue.front();
                queue.pop();

                if(low <= temp->val && temp->val <= high ){
                    sum += temp->val;
                }
                
                if(temp->left != nullptr){
                    queue.push(temp->left);
                }
                if(temp->right != nullptr){
                    queue.push(temp->right);
                }


        }

        return sum;
        
    }
};
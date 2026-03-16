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
    bool isCompleteTree(TreeNode* root) {


        // level order traversal 


        queue<TreeNode*> que;

        que.push(root);

        bool ans = true;
        int flag = 1;


        while(!que.empty()){



            TreeNode* hero = que.front();
            que.pop();

        

            if( flag == 0 && hero != NULL){
                ans = false;
                break;
            }else if ( flag == 1 && hero == NULL){
                flag = 0;
                continue;
            }else if( flag == 0 && hero == NULL ){
                continue;
            }

            if( hero->left){

            que.push(hero->left);
            }else{
                que.push(NULL);
            }

            if( hero->right){

            que.push(hero->right);
            }else{
                que.push(NULL);
            }


        }


        return ans;
        
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {



        int ans = 1 ;

        if( root == NULL){
            return 0;
        }

        queue<pair<Node* , int > > que;
        que.push( { root , 1 } );
   

        while( !que.empty() ){

            

            Node* hero = que.front().first;
            int currentCount = que.front().second;

            ans = ans > currentCount ? ans : currentCount;

            que.pop();

            // if(  hero->children.size() > 0 ){

            

            for( int i = 0 ; i < hero->children.size() ; i++){
                if( hero->children[i] != nullptr){
                que.push( { hero->children[i] , currentCount+1 } );
                }
            }

            // }

        }


        return ans;
        
    }



};
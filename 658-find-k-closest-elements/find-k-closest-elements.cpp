class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {


        // find x position if it exists in the array or its possible possition 

        // left and right pointers go in both directions till k number are got 

        // if left or right reach end point stop that pointer 

        // eg [3 , 5 , 6 , 8 , 29 , 89 , 4839 , 980 , 445460]
        // k = 5 ,  x = 56;
        priority_queue<int , vector<int> , greater<int> >answer;
        int left , right , flag = -1;
        for( int i = 0 ; i < arr.size(); i++){
            if( arr[i] == x){
                flag = 0;
                answer.push(arr[i]);
                left = i-1;
                right = i+1;
                break;
            }
            else if ( arr[i] < x && i+1 < arr.size() && x < arr[i+1]  ){
                flag = 0;
                left = i;
                right = i+1;
                break;
            }else if ( arr[i] < x){
               flag = 1;
            }


        }
        int ll , rr ;
        if(flag == -1){
            for( int i = 0 ; i < k ; i++){
                answer.push(arr[i]);
            }
        }else if (flag == 1){
            for( int i = arr.size()-k ; i < arr.size() ; i++){
                answer.push(arr[i]);
            }
        }else{

            while(answer.size() < k){

               if(left >= 0){
                ll = arr[left];
               }else{
                ll = INT_MAX;
               }

               if(right <= arr.size() - 1){
                rr = arr[right];
               }else{
                rr = INT_MAX;
               }

               

                if( rr == INT_MAX && ll != INT_MAX){
                    answer.push(arr[left]);
                    left--;
                    continue;
                }else if ( ll == INT_MAX && rr != INT_MAX ){
                    answer.push(arr[right]);
                    right++;
                     continue;
                }else if (ll == INT_MAX && rr == INT_MAX){
                    break;
                }
               if(  rr-x < x-ll){
                answer.push(arr[right]);
                right++;
               }else{
                answer.push(arr[left]);
                left--;
               }



            }

        }

        vector<int>ans;

        while(answer.size() > 0){
            ans.push_back(answer.top());
            answer.pop();
        }

        return ans;



        
    }
};
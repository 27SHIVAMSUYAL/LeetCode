class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int ans , currentSum = 0 , sum = 0;

        for( int i = 0 ; i < apple.size() ; i++){
            sum += apple[i];
        }

        sort(capacity.begin() , capacity.end() , greater<int>());

        for( int i = 0 ; i < capacity.size() ; i++){
            currentSum += capacity[i];
            if(currentSum >= sum){
                ans = i+1;
                break;
            }
        }

        return ans;


        
    }
};
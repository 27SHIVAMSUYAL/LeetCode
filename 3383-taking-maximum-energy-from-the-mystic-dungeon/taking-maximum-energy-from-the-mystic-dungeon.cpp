class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int maxEnergy = INT_MIN , l = energy.size();
        vector<int> dp(l,0);

        for(int i = l-1 ; i >= 0 ;i--){

            if(i + k < l ){
                dp[i] = dp[i+k] + energy[i];
            }else{
                dp[i] = energy[i];
            }

            maxEnergy = max(dp[i] , maxEnergy);
        }

        return maxEnergy;
        
    }

    
};
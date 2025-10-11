class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int maxEnergy = INT_MIN , l = energy.size();
        map<int,int> dp;

        for(int i = l-1 ; i >= 0 ;i--){

            maxEnergy = max(maxEnergy , solve(energy , k , i ,dp));
        }

        return maxEnergy;
        
    }

    int solve(vector<int> &energy , int k , int i , map<int,int> &dp ){
        int temp = i;
        int sum = 0 ;
        int l = energy.size();

         if(i+k < l && dp.find(i+k) != dp.end()){
                sum = energy[i] + dp[i+k];
                return dp[temp]= sum;
            }

        while( i < l ){
            sum += energy[i];
            i = i+k ;
        }
        return dp[temp] = sum;
    }
};
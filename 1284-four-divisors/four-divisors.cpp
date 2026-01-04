class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        
        // map<int,int> map;
        set<int> set;
        int sum = 0;
        for( int i = 0 ; i < nums.size() ; i++){
            set.clear();
           sum += solve( nums[i] , set );
           
        
        }


        return sum;
        
    }


    int solve( int n , set<int>&set){
        int count = 0;
        int sum = 0;

        for( int i = 1 ; i <= sqrt(n) ; i++){
            if(n%i == 0){
                set.insert(i);
                set.insert(n/i);
            }
        }

        if(set.size() == 4){
            for( int i : set){
                sum += i;
            }
            return sum;
        }
        

        return 0;

    }
};
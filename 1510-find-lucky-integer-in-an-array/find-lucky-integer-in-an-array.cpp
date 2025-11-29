class Solution {
public:
    int findLucky(vector<int>& arr) {

            map<int , int > map ;

        for(int i : arr){
            if(map.find(i) == map.end()){
                map[i] = 1;
            }else{
            map[i]++;
            }
        }

        int ans = -1;

        for( pair<int , int > pair : map){
            if(pair.first == pair.second){
                ans = max(ans , pair.first);
            }
        }

        return ans;
        
    }
};
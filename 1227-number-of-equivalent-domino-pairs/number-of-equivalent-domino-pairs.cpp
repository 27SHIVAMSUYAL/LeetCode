class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        int ans = 0, small, big, key;
        unordered_map<int, int> map;

        for (int i = 0; i < dominoes.size(); i++) {

            small = min(dominoes[i][0], dominoes[i][1]);
            big = max(dominoes[i][0], dominoes[i][1]);
            key = small * 10 + big;
            if (map.find(key) != map.end()) {
                map[key]++;
                
            } else {
                map[key] = 1;
            }
        }

        for( auto i : map){
            int count = i.second;
            ans += (count*(count-1))/2;
        }



        return ans;
    }
};
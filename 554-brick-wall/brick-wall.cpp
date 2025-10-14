class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        int totalWidth = wall.size();
        int totalHeight = wall.size();
        long long sum;
        int maxi = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < wall.size(); i++) {
            sum = 0;
            for (int j = 0; j < wall[i].size()-1; j++) {
                // sum = sum + (1LL * wall[i][j]);
                sum = sum + wall[i][j];
                if (map.find(sum) != map.end()) {
                    map[sum]++; // already exists → increment
                } else {
                    map[sum] = 1; // first occurrence
                }
                maxi = max(map[sum], maxi);
            }
        }

        return totalHeight - maxi;
    }
};
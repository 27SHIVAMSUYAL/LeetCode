class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int count1 = 0, count2 = 0;

        int ans1 = 0, ans2 = 0;

        int limit = nums.size() / 3;

        for (int i = 0; i < nums.size(); i++) {

            if (ans1 == nums[i]) {
                count1 += 1;
            } else if (ans2 == nums[i]) {
                count2 += 1;
            } else if (count1 == 0) {
                ans1 = nums[i];
                count1 = 1;
               
            } else if (count2 == 0) {
                ans2 = nums[i];
                count2 = 1;
               
            } else {
                count1--;
                count2--;
            }
        }

        vector<int> ans;

        int valid1 = 0, valid2 = 0;

        cout << "ans1 -->" << ans1 << "    ans2 -->" << ans2 << endl;

        for (auto j : nums) {

            if (j == ans1) {
                valid1++;
            } else if (j == ans2) {
                valid2++;
            }
        }

        if (valid1 > limit) {
            ans.push_back(ans1);
        }
        if (valid2 > limit) {
            ans.push_back(ans2);
        }

        return ans;
    }
};
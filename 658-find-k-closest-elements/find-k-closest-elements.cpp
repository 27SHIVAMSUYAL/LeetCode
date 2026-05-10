class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;

        vector<int> answer;

        cout<<"left " << left << " right " << right << "\n";

        while (answer.size() < k) {

            if (left < 0 && right >= arr.size()) {
                break;
            } else if (left < 0 ) {
                answer.push_back(arr[right]);
                right++;
               
            } else if (right >= arr.size()) {
                answer.push_back(arr[left]);
                left--;
              
            }else if(   abs(arr[right] - x) <  abs(arr[left] - x)   ) {
                answer.push_back(arr[right]);
                right++;
            } else {
                answer.push_back(arr[left]);
                left--;
            }
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};
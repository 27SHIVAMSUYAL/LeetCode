class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        if (k == 0) {
            vector<int> ans(code.size(), 0);
            return ans;
        }

        int sum = 0;
        int n = code.size();
        int i;

    

        if (k > 0) {
            for (i = 1; i <= k; i++) {
                sum += code[i];
            }
        } else {

             
            for (i = n - 1; i >= n + k; i--) {
                sum += code[i];
               
            }
        }


  
    vector<int> answer;
    for (i = 0; i < n; i++) {

        answer.push_back(sum);

        if (k > 0) {
            sum -= code[(i + 1) % n];
                sum += code[(i+k+1)%n];
        } else {
       
            sum -= code[(n + k  + i) % n];
        
         
            sum += code[i % n];
        }
    }

    return answer;
}
}
;
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

        int tempk = k;

        if (k > 0) {
            while(k > 0){
                sum += code[((k%n)+n)%n];
                k--;
            }
        } else {

             
            while( k < 0){
                sum += code[ ((k%n)+n)%n];
               k++;
            }
        }

        k = tempk;

  
    vector<int> answer;
    for (i = 0; i < n; i++) {

        answer.push_back(sum);

        if (k > 0) {
            sum -= code[((i + 1) % n + n )%n];
                sum += code[((i+k+1)%n + n )%n];
        } else {
       
            sum -= code[((n + k  + i) % n + n )%n];
            sum += code[((i % n)+n)%n];
        }
    }

    return answer;
}
}
;
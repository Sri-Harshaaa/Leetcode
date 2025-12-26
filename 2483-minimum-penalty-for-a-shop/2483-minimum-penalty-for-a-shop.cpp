class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(),N = 0,Y = 0, ans = 0, temp = 0;
        for(int i=1; i<=n; i++) {
            if(customers[i-1] == 'Y') Y++;
            else N++;
            if(Y - N > temp) {
                temp = Y-N;
                ans = i;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> N(n+1,0), Y(n+1,0);
        for(int i=1; i<n+1; i++) {
            if(customers[i-1] == 'N') N[i] = N[i-1]+1;
            else N[i] = N[i-1];
        }
        for(int j=n-1; j>=0; j--) {
            if(customers[j] == 'Y') Y[j] = Y[j+1]+1;
            else Y[j] = Y[j+1];
        }
        int penalty = INT_MAX, ans = -1;
        for(int k=0; k<n+1; k++) {
            if(Y[k]+N[k] < penalty) {
                penalty = Y[k]+N[k];
                ans = k;
            }
        }
        return ans;
    }
};
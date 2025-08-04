class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(),cnt = 0;
        for(int i=0; i<n; i++) {
            int j;
            for(j=0; j<n; j++) {
                if(baskets[j]>=fruits[i]) {
                    baskets[j] = -1;
                    break;
                }
            }
            if(j==n) cnt++;
        }
        return cnt;
    }
};
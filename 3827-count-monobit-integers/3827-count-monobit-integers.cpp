class Solution {
public:
    int countMonobit(int n) {
        int cnt = 1;
        for(int i=1; i<=n; i++) {
            if((i & (i+1)) == 0) cnt++;
        }
        return cnt;
    }
};
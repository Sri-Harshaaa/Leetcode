class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(),m = capacity.size(),sum = 0;
        sort(capacity.begin(), capacity.end());
        for(int &v : apple) sum+=v;
        int cnt = 0,i = m-1;
        while(sum>0) {
            sum-=capacity[i];
            cnt++;
            i--;
        }
        return cnt;
    }
};
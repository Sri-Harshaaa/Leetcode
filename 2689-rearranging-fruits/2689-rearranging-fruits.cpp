class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int mini = INT_MAX;
        unordered_map<int,int> mpp;
        for(int i=0; i<basket1.size(); i++) {
            mini = min(mini,basket1[i]);
            mini = min(mini,basket2[i]);
            mpp[basket1[i]]++;
            mpp[basket2[i]]--;
        }
        long long ans = 0;
        vector<int> temp;
        for(auto it : mpp) {
            if(it.second % 2!= 0) return -1;
            int x = abs(it.second)/2;
            while(x--) temp.push_back(it.first);
        }
        sort(temp.begin(),temp.end());
        for(int i=0; i<temp.size()/2; i++) ans+=min(2*mini,temp[i]);
        return ans;
    }
};
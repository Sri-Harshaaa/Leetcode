class Solution {
public:
    bool checkPrime(int x) {
        if(x==1 || x==0) return false;
        for(int i=2; i<=x/2; i++) {
            if(x%i==0) return false;
        }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++) mpp[nums[i]]++;
        for(auto it : mpp) {
            if(checkPrime(it.second)) return true;
        }
        return false;
    }
};
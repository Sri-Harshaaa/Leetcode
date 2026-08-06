class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }
        int a = nums[0];
        int b = nums[nums.size()-1];
        vector<int> ans;
        for(int i=a; i<=b; i++) {
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        int i = 1, j = 1;
        st.insert(nums[0]);
        while(j<n) {
            if(st.find(nums[j])== st.end()) {
                st.insert(nums[j]);
                swap(nums[i],nums[j]);
                i++;
            }
            else j++;
        }
        return st.size();
    }
};
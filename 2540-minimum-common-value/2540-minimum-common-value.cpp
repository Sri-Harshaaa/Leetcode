class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        set<int> st;
        for(int i=0; i<m; i++) {
            st.insert(nums1[i]);
        }
        for(int i=0; i<n; i++) {
            if(st.count(nums2[i])) return nums2[i];
        }
        return -1;
    }
};
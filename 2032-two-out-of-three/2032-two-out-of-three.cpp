class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,unordered_set<int>> mpp;
        for(int i=0; i<nums1.size(); i++) {
            mpp[nums1[i]].insert(1);
        }
        for(int i=0; i<nums2.size(); i++) {
            mpp[nums2[i]].insert(2);
        }
        for(int i=0; i<nums3.size(); i++) {
            mpp[nums3[i]].insert(3);
        }
        vector<int> ans;

        for(auto& it : mpp) {
            if(it.second.size() >= 2) ans.push_back(it.first);
        }

        return ans;
    }
};
class FindSumPairs {
private:
    int n1,n2;
    vector<int> arr1,arr2;
    unordered_map<int,int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        n1 = nums1.size();
        n2 = nums2.size();
        for(int i=0; i<n2; i++) freq[nums2[i]]++;
    }
    
    void add(int index, int val) {
        freq[arr2[index]]--;
        arr2[index]+=val;
        freq[arr2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i=0; i<n1; i++) {
            int tar = tot-arr1[i];
            if(freq.find(tar)!=freq.end()) cnt+=freq[tar];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
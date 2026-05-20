class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        set<int> stA, stB;
        for(int i=0; i<n; i++) {
            int a = A[i], b = B[i];
            if(a == b) {
                if(i == 0) ans[i]++;
                else {
                    ans[i] += ans[i-1]+1;
                }
            }
            else {
                if(stB.count(a)) ans[i]++;
                else stA.insert(a);
                if(stA.count(b)) ans[i]++;
                else stB.insert(b);
                if(i != 0 ) ans[i]+=ans[i-1];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int> mpp;
        for(int i=0; i<row.size(); i++) {
            mpp[row[i]] = i;
        }
        int swaps = 0;
        for(int i=0; i<row.size(); i+=2) {
            if(!((min(row[i],row[i+1])%2==0) && max(row[i],row[i+1])%2 && abs(row[i]-row[i+1])==1)) {
                swaps++;
                int a = row[i]%2 ? row[i]-1 : row[i]+1;
                int b = row[i+1];
                swap(row[i+1],row[mpp[a]]);
                mpp[b] = mpp[a];
                mpp[a] = i+1;
            }
        }
        return swaps;
    }
};
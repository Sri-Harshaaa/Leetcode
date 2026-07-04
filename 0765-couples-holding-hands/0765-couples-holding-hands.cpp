class Solution {
public:
    bool isCouple(int a, int b) {
        return (min(a,b)%2==0) && max(a,b)%2 && abs(a-b)==1;
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int swaps = 0;
        for(int i=0; i<n; i+=2) {
            if(!isCouple(row[i],row[i+1])) {
                int a = row[i]%2 ? row[i]-1 : row[i]+1;
                int b = row[i+1]%2 ? row[i+1]-1 : row[i+1]+1;
                int j = i+2;
                while(j<n) {
                    if(row[j] == a) {
                        swap(row[j],row[i+1]);
                        swaps++;
                        break;
                    }
                    else if(row[j] == b) {
                        swap(row[j],row[i]);
                        swaps++;
                        break;
                    }
                    j++;
                }
            }
        }
        
        return swaps;
    }
};
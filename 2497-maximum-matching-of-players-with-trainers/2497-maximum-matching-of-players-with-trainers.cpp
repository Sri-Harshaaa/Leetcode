class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n1=players.size(),n2=trainers.size();
        int i=0,j=0;
        int cnt=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<n1 && j<n2) {
            if(players[i]<=trainers[j]) {
                cnt++;
                i++;
                j++;
            }
            else j++;
        }
        return cnt;
    }
};
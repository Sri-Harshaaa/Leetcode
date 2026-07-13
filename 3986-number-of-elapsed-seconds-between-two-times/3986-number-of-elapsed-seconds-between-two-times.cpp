class Solution {
public:
    int solve(string& time) {
        int hrs = stoi(time.substr(0,2));
        int mins = stoi(time.substr(3,2));
        int secs = stoi(time.substr(6,2));

        return hrs*3600 + mins*60 + secs;
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        return solve(endTime)-solve(startTime);
    }
};
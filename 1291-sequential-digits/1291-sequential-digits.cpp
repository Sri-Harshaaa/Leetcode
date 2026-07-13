class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        string l = to_string(low);
        int len = l.size();
        int f_digit = l[0]-'0';
        int i = f_digit-1;
        string s1 = s.substr(i,len);
        int l1 = stoi(s1);
        if(l1 < low) i++;
        while(i <= 9-len) {
            string x = s.substr(i,len);
            int y = stoi(x);
            if(y > high) return ans;;
            ans.push_back(y);
            i++;
        }
        
        len++;

        while(len <= 9) {
            int i = 0;
            while(i <= 9-len) {
                string x = s.substr(i,len);
                int y = stoi(x);
                if(y > high) return ans;
                ans.push_back(y);
                i++;
            }
            len++;
        }
        
        return ans;
    }
};
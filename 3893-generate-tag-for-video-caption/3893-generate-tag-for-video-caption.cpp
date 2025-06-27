class Solution {
public:
    string generateTag(string caption) {
        string tag="#";
        int n = caption.size();
        for(int i=0; i<n; i++) {
            if(tag.size()==100) break;
            if(isalpha(caption[i]) || caption[i]==' ') {
                if(caption[i]==' ') {
                    if(isalpha(caption[i+1])) {
                        if(i+1!=n) {
                            if(tag.size()==1) tag+=tolower(caption[i+1]);
                            else tag+=toupper(caption[i+1]);
                        }
                        i++;
                    }
                    else continue;
                }
              else {
                if(tag.size()==1) tag+=tolower(caption[i]);
                else tag+=tolower(caption[i]);
              }
            }
        }
        return tag;
    }
};


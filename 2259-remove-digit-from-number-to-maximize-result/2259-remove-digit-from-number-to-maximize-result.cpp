class Solution {
public:
    string removeDigit(string s, char digit) {
        string ans = "";
        int idx;
        for(int i = 0; i < s.length(); i++){
            if(s[i]==digit){
                idx = i;
                if(i < s.length()-1 && s[i+1] > s[i]){
                    ans = s.substr(0, i) + s.substr(i+1);
                    return ans;
                }
            }
        }
        ans = ans + s.substr(0, idx) + s.substr(idx+1);
        return ans;
    }
};
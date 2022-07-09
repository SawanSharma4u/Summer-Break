class Solution {
public:
    int titleToNumber(string c) {
        int ans = c[0]-'A'+1;
        for(int i = 0; i < c.size()-1; i++){
            ans = ans*26;
            ans += c[i+1]-'A'+1;
        }
        return ans;
    }
};
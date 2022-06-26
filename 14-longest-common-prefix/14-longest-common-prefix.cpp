class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int y = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            if(y > strs[i].length()){
                y = strs[i].length();
            }
        }
        string str = "";
        for(int i = 0; i < y; i++){
            int k = 1;
            for(int j = k; j < strs.size(); j++){
                if(strs[j-1][i] != strs[j][i]){
                    return str;
                }
            }
            str = str + strs[k-1][i];
        }
        return str;
    }
};
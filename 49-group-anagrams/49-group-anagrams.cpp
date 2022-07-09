class Solution {
    static bool compare(string s1, string s2){
        return s1.length() < s2.length();
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), compare);
        vector<vector<int>> ans(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < strs[i].length(); j++){
                ans[i][strs[i][j]-'a']++;
            }
        }
        vector<vector<string>> op;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                visited[i] = true;
                vector<string> temp;
                temp.push_back(strs[i]);
                for(int j = i+1; j < n; j++){
                    if(!visited[j]){
                        int k;
                        for(k = 0; k < 26; k++){
                            if(ans[i][k]!=ans[j][k]){
                                break;
                            }
                        }
                        if(k==26){
                            visited[j] = true;
                            temp.push_back(strs[j]);
                        }
                    }
                }
                op.push_back(temp);
            }
        }
        return op;
    }
};
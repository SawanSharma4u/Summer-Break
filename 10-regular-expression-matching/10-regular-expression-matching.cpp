class Solution {
//     vector<vector<int>> dp;
//     bool help(string &s, string &p, int i, int j){
//         if(i==s.length()){
//             while(j!=p.length()){
//                 if(p[j]=='*')
//                     j++;
//                 else if(j+1<p.length() && p[j+1]=='*'){
//                     j = j+2;
//                 }
//                 else break;
//             }
//             if(j==p.length()) return true;
//             return false;
//         }
//         if(j == p.length()) return false;
        
//         if(dp[i][j]!=-1) return dp[i][j];
//         bool ans = false;
//         if(s[i] == p[j] || p[j]=='.'){
//             bool a = help(s,p, i+1, j+1);
//             bool b = false;
//             if(j+1!=p.length() && p[j+1]=='*'){
//                 b = help(s, p, i, j+2);
//             }
//             ans = a || b;
//         }
//         else if(p[j]=='*'){
//             if(j!=0 && (s[i]==p[j-1] || p[j-1]=='.')){
//                 ans = help(s, p, i+1, j) || help(s, p, i, j+1);
//             }
//             else{
//                 ans = help(s, p, i, j+1);
//             }
//         }
//         else if(j!=p.length()-1 && p[j+1] == '*'){
//             ans = help(s, p, i, j+2);
//         }
//         return dp[i][j] = ans;
//     }
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1));
        dp[0][0] = true;
        for(int i = 1; i <= p.length(); i++){
            if(p[i-1]=='*'){
                dp[0][i] = dp[0][i-2];
            }
            else dp[0][i] = false;
        }
        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= p.length(); j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2]=='.' || p[j-2]==s[i-1]){
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
                else dp[i][j] = false;
            }
        }
        return dp[s.length()][p.length()];
    }
};
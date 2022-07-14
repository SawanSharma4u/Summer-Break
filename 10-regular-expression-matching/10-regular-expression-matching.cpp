class Solution {
    vector<vector<int>> dp;
    bool help(string &s, string &p, int i, int j){
        cout<<i<<" "<<j<<endl;
        if(i==s.length()){
            while(j!=p.length()){
                if(p[j]=='*')
                    j++;
                else if(j+1<p.length() && p[j+1]=='*'){
                    j = j+2;
                }
                else break;
            }
            if(j==p.length()) return true;
            return false;
        }
        if(j == p.length()) return false;
        
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(s[i] == p[j] || p[j]=='.'){
            bool a = help(s,p, i+1, j+1);
            bool b = false;
            if(j+1!=p.length() && p[j+1]=='*'){
                b = help(s, p, i, j+2);
            }
            ans = a || b;
        }
        else if(p[j]=='*'){
            if(j!=0 && (s[i]==p[j-1] || p[j-1]=='.')){
                ans = help(s, p, i+1, j) || help(s, p, i, j+1) || help(s, p, i+1, j+1);
            }
            else{
                ans = help(s, p, i, j+1);
            }
        }
        else if(j!=p.length()-1 && p[j+1] == '*'){
            ans = help(s, p, i, j+2);
        }
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        dp.resize(s.length(), vector<int>(p.length(), -1));
        return help(s, p, 0, 0);
    }
};
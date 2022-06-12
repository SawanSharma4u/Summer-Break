class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> arr(s.length(), vector<bool>(s.length(), false));
        string ans = "";
        int len = 1, srt=0;
        for(int i = 0; i < s.length(); i++){
            for(int j= 0, k = i; k < s.length(); k++, j++){
                if(k-j == 0){
                    arr[j][k] = true;
                }
                else if(k-j == 1){
                    if(s[j]==s[k]){
                        arr[j][k] = true;
                        len = 2;
                        srt = j;
                    }
                    else arr[j][k] = false;
                }
                else{
                    if(s[k]==s[j] && arr[j+1][k-1]){
                        arr[j][k] = true;
                        len = k-j+1;
                        srt = j;
                    }
                    else arr[j][k] = false;
                }
            }
        }
        while(len){
            ans += s[srt];
            srt++;
            len--;
        }
        return ans;
    }
};
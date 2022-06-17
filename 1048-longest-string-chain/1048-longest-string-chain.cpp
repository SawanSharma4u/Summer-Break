class Solution {
    bool static Compare(string &s1, string &s2){
        return s1.length() < s2.length();
    }
public:
    bool compare(string &s1, string &s2){
        bool eligible = false;
        if(s1.length()+1 == s2.length()){
            int k = 0;
            while(k < s1.length() && s1[k]==s2[k]){
                k++;
            }
            while(k < s1.length() && s1[k]==s2[k+1]){
                k++;
            }
            if(k==s1.length()) {
                eligible = true;
            }
        }
        return eligible;
    }
         
    int longestStrChain(vector<string>& nums){
        sort(nums.begin(), nums.end(), Compare);
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (compare(nums[j], nums[i]) && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        return *max_element(dp.begin(), dp.end());
    }
};
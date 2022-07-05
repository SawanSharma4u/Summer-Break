class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <=1) return nums.size();
        unordered_map<int,int> ans;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(auto i : nums){
            ans[i]++;
            mx = max(mx, i);
            mn = min(mn, i);
        }
        int temp = 0;
        int cnt = INT_MIN;
        for(int i = mn; i <= mx; i++){
            if(ans.count(i)!=0){
                temp++;
                cnt = max(cnt, temp);
            }
            else{
                temp = 0;
                if(nums.size()-cnt < cnt){
                    break;
                }
            }
        }
        return cnt;
    }
};
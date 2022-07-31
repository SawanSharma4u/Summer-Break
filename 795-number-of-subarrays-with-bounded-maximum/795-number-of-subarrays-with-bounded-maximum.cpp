class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int l, int r) {
        vector<int> left(nums.size());
        for(int i = 0; i < nums.size(); i++){
           if(nums[i] >= l){
               if(i!=0 && nums[i-1] < l) left[i] = left[i-1];
               else left[i] = i;
           }
            else{
                if(i==0 || nums[i-1] >= l) left[i] = i;
                else left[i] = left[i-1];
            }
        }
        vector<int> right(nums.size());
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] <= r){
                if(i==nums.size()-1) right[i] = nums.size();
                else right[i] = right[i+1];
            }
            else{
                right[i] = i;
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            cout<<left[i]<<" ";
            if(nums[i] >= l && nums[i] <= r){
                // cout<<(i-left[i]+1)<<" "<<(right[i]-i)<<endl;
                ans += (i-left[i]+1)*(right[i]-i);
            }
        }
        return ans;
    }
};
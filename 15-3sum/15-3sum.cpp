class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> output;
        for(int i = 0; i < n-2; i++){
            if(i==0 || (i > 0 && nums[i] != nums[i-1])){
                int sum = 0 - nums[i];
                int j = i+1;
                int k = n-1;
                while(k>j){
                    if(nums[j]+nums[k] == sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        output.push_back(temp);
                        while(k > j && nums[j] == nums[j+1]){
                            j++;
                        }
                        while(k > j && nums[k] == nums[k-1]){
                            k--;
                        }
                        j++;
                        k--;
                    }
                    else if(nums[j]+nums[k] < sum){
                        j++;
                    }
                    else{
                        k--;
                    }  
                }
            }
        }
        return output;
    }
};
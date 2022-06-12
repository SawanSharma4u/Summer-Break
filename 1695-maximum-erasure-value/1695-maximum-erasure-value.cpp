class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0; 
        vector<int> total;
        for(int i : nums){
            sum += i;
            total.push_back(sum);
        }
        int ans = 0;
        unordered_map<int, int> myMap;
        int index = -1;
        for(int i = 0; i < nums.size(); i++){
            if(myMap.count(nums[i])==0 || myMap[nums[i]] <= index){
                myMap[nums[i]]=i;
            }
            else{
                if(index==-1){
                    ans = total[i-1];
                }
                else{
                    ans = max(ans, total[i-1] - total[index]);
                }
                index = myMap[nums[i]];
                myMap[nums[i]] = i;
            }
        }
        if(index==-1) return sum;
        return max(ans, sum - total[index]);
    }
};
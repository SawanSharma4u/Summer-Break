class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int tar = sum - x;
        if(tar<0) return -1;
        int len = INT_MIN;
        sum = 0;
        for(int i = 0, j = 0; j < nums.size(); j++){
            sum += nums[j];
            
            while(sum > tar){
                sum -= nums[i];
                i++;
            }
            if(sum==tar){
                len = max(len, j-i+1);
            }
        }
        if(len==INT_MIN) return -1;
        return nums.size() - len;
        
//         Method - 2
//         int n= nums.size();
//         vector<int> ans(n+1);
//         ans[0] = 0;
//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             sum += nums[i];
//             ans[i+1] = sum;
//         }
        
//         if(sum < x) return -1;
//         if(sum==x) return n;
//         x = sum - x;
//         int temp = INT_MIN;
//         for(int i = 0; i < n; i++){
//             int j = i, k = n-1;
//             while(j<=k){
//                 int mid = (j+k)/2;
//                 if(ans[mid+1]-ans[i] == x){
//                     temp = max(temp, mid-i+1);
//                     break;
//                 }
//                 else if(ans[mid+1]-ans[i] > x){
//                     k = mid-1;
//                 }
//                 else{
//                     j = mid+1;
//                 }
//             }
//         }
//         if(temp == INT_MIN) return -1;
//         return n-temp;
    }
};
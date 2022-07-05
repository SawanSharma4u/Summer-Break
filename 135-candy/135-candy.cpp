class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = 0;
        vector<int> forward(n);
        vector<int> backward(n);
        int tempf = 1;
        int tempb = 1;
        forward[0] = 1;
        backward[n-1] = 1;
        for(int i = 1 , j = n-2; i < n && j >= 0; i++, j--){
            if(ratings[i] > ratings[i-1]){
                tempf++;
            }
            else{
                tempf = 1;
            }
            forward[i] = tempf;
            if(ratings[j] > ratings[j+1]){
                tempb++;
            }
            else{
                tempb = 1;
            }
            backward[j] = tempb; 
        }
        for(int i = 0; i < n; i++){
            candy += max(forward[i], backward[i]);
        }
        return candy;
//         while(i<n){
//             if(ratings[i] == ratings[i-1]){
//                 i++;
//                 continue;
//             }
            
//             //For increasing slope
//             int peak = 0;
//             while(ratings[i] > ratings [i-1]){
//                 peak++;
//                 candy += peak;
//                 i++;
//                 if(i == n) return candy;
//             }
            
//             //For decreasing slope
//             int valley = 0;
//             while(i<n && ratings[i] < ratings[i-1]){
//                 valley++;
//                 candy += valley;
//                 i++;
//             }
//             candy -= min(peak, valley); //Keep only the higher peak
//         }
        return candy;
    }
};
class Solution {
public:
    int minDeletions(string s) {
        int arr[26] = {0};
        for(int i = 0; i < s.length(); i++){
            arr[s[i]-'a']++;
        }
        sort(arr, arr+26);
        reverse(arr, arr+26);
        int ans = 0;
        int i = 1;
        for(; i < 26; i++){
            if(arr[i-1] <= arr[i]){
                ans += arr[i]-arr[i-1] + 1;
                arr[i] = arr[i-1] - 1;
            }
            if(arr[i]==0){
                break;
            }
        }
        for(; i < 26; i++){
            ans += arr[i];
        }
        return ans;
    }
};
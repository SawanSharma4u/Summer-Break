class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> arr(s.length()+1);
        
        vector<int> aph(26, -1);
        arr[0] = 1;
        int count = 1;
        for(int i = 0; i < s.length(); i++){
            if(aph[s[i]-'a']==-1){
                count = ((long)count*2)%1000000007;
            }
            else count = ((long)2*count - arr[aph[s[i]-'a']] + 1000000007)%1000000007;
            arr[i+1] = count;
            aph[s[i]-'a'] = i;
        }
        return count-1;
    }
};
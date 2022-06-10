class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++){
            unordered_map<char, int> my;
            int sum = 0;
            int index = i;
            for(int j = i; j < s.length(); j++){
                if(my.count(s[j])==0){
                    sum++;
                    my[s[j]] = j;
                }
                else {
                    index = my[s[j]];
                    break;
                }
            }
            maxlen = max(maxlen, sum);
            i = index;
        }
        return maxlen;
    }
};
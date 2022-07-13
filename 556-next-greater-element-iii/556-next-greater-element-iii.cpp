class Solution {
public:
    int nextGreaterElement(int n) {
        bool ans = false;
        string s = to_string(n);
        for(int i = s.length()-1; i >= 0; i--){
            for(int j = s.length()-1; j > i; j--){
                for(int k = j-1; k >= i; k--){
                    if(s[j] > s[k]){
                        swap(s[j], s[k]);
                        ans = true;
                        sort(s.begin()+k+1, s.end());
                        break;
                    }
                }
                if(ans) break;
            }
            if(ans) break;
        }
        if(!ans) return -1;
        if(stol(s) > INT_MAX) return -1;
        return stoi(s);
    }
};
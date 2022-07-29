class Solution {
private:
    bool match(string w, string p){
        if(w.length()!=p.length()) return false;
        unordered_map<char,char> map1;
        unordered_map<char,char> map2;
        for(int i = 0; i < w.length(); i++){
            if(map1.count(w[i])==0) map1[w[i]] = p[i];
            if(map2.count(p[i])==0) map2[p[i]] = w[i];
            if(map1[w[i]]!=p[i] || map2[p[i]]!=w[i])
                return false;
        }
        return true;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> output;
        for(int i = 0;i < words.size(); i++){
            if(match(words[i],pattern)){
                output.push_back(words[i]);
            }
        }
        return output;
    }
};
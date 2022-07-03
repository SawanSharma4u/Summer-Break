class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        char Decode = 'a';
        for(auto i : key){
            if(m.count(i)==0 && i!=' '){
                m[i] = Decode;
                Decode++;
            }
        }
        string ans = "";
        for(auto i : message){
            if(i==' ') ans += " ";
            else ans += m[i];
        }
        return ans;
    }
};
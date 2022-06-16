class Solution {
    unordered_map<string, bool> myMap;
public:
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)==0){
            return true;
        }
        string key = s1;
        key.push_back('_');
        key = key + s2;
        if(myMap.find(key)!=myMap.end()) return myMap[key];
        bool flag = false;
        int j = s1.length()-1;
        
        for(int i = 1; i <= j; i++){
            
            if((isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i, j-i+1), s2.substr(i, j-i+1))) || (isScramble(s1.substr(0,i),s2.substr(j+1-i,i)) && isScramble(s1.substr(i, j+1-i), s2.substr(0, j+1-i)))){
                flag = true;
                break;
            }
            
        }
        
        return myMap[key] = flag;
    }
    
    // recursive solution
    // bool isScramble(string s1, string s2) {
    //     if(s1.compare(s2)==0){
    //         return true;
    //     }
    //     bool flag = false;
    //     int j = s1.length()-1;
    //     for(int i = 1; i <= j; i++){
    //         if((isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i, j-i+1), s2.substr(i, j-i+1))) || (isScramble(s1.substr(0,i),s2.substr(j+1-i,i)) && isScramble(s1.substr(j+1-i, i), s2.substr(0, i)))){
    //             flag = true;
    //             break;
    //         }
    //     }
    //     return flag;
    // }
};
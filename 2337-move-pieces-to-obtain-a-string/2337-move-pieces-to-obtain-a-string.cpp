class Solution {
public:
    bool canChange(string start, string target) {
        char lasts = start[0];
        char lastt = target[0];
        for(int i = 1; i < start.length(); i++){
            if(start[i]=='_' && lasts == 'R'){
                start[i] = 'r';
            }
            else{
                lasts = start[i];
            }
            if(target[i]=='_' && lastt == 'R'){
                target[i] = 'r';
            }
            else{
                lastt = target[i];
            }
        }
        int n = start.size();
        lasts = start[n-1];
        lastt = target[n-1];
        for(int i = n-2; i >= 0; i--){
            if(start[i]=='r' && lasts == 'L'){
                start[i] = 'b';
            }
            else if(start[i]=='_' && lasts == 'L'){
                start[i] = 'L';
            }
            else{
                lasts = start[i];
            }
            
            if(target[i]=='r' && lastt == 'L'){
                target[i] = 'b';
            }
            else if(target[i]=='_' && lastt == 'L'){
                target[i] = 'L';
            }
            else{
                lastt = target[i];
            }
        }
        for(int i = 0; i < n; i++){
            if(start[i]=='b' || target[i]=='b') continue;
            if(start[i]=='L' && (target[i]=='L' || target[i]=='_')) continue;
            if((start[i]=='R' || start[i]=='r') && (target[i]=='R' || target[i]=='r'|| target[i]=='_')) continue;
            if(start[i]=='_' && target[i]=='_') continue;
            else return false;
        }
        return true;
    }
};
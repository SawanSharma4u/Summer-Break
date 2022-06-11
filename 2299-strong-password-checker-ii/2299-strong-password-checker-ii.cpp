class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        if(p.length() < 8) return false;
        cout<<p.length()<<endl;
        bool num=false, sc=false, uc=false, sp = false;
        for(int i = 0; i < p.length(); i++){
            if(i < p.length()-1 && p[i]==p[i+1]) return false;
            if(p[i]==33 || p[i]==64 || (p[i]>=35 && p[i]<=38) || p[i]==94 || (p[i]>=40 && p[i]<=43) || p[i]==45){
                if(!sp){
                    sp = true;
                }
            }
            else if(p[i] >= 48 && p[i] <= 57){
                if(!num) num = true;
            }
            else if(p[i] >= 65 && p[i] <= 90){
                if(!uc) uc = true;
            }
            else if(p[i]>=97 && p[i]<=122){
                if(!sc) sc = true;
            }
            else return false;
        }
        if(num && sc && uc && sp) return true;
        return false;
    }
};
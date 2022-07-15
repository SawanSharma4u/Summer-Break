class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> temp;
        for(string s: tokens){
            if(s!="+" && s!="-" && s!="*" && s!="/"){
                temp.push(s);
            }
            else{
                string a = temp.top(); 
                temp.pop();
                string b = temp.top();
                temp.pop();
                if(s=="+"){
                    temp.push(to_string(stoi(a)+stoi(b)));
                }
                else if(s=="-"){
                    temp.push(to_string(stoi(b)-stoi(a)));
                }
                else if(s=="*"){
                    temp.push(to_string(stoi(a)*stoi(b)));
                }
                else temp.push(to_string(stoi(b)/stoi(a)));
            }
        }
        return stoi(temp.top());
    }
};
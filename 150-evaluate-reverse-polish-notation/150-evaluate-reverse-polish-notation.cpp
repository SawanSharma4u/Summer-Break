class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s, temp;
        for(int i = tokens.size()-1; i >= 0; --i){
            s.push(tokens[i]);
        }
        while(!s.empty()){
            while(!s.empty() && s.top()!="+" && s.top()!="-" && s.top()!="*" && s.top()!="/"){
                temp.push(s.top());
                s.pop();
            }
            if(!s.empty()){
                string a = temp.top(); 
                temp.pop();
                string b = temp.top();
                temp.pop();
                string opr = s.top();
                s.pop();
                if(opr=="+"){
                    temp.push(to_string(stoi(a)+stoi(b)));
                }
                else if(opr=="-"){
                    temp.push(to_string(stoi(b)-stoi(a)));
                }
                else if(opr=="*"){
                    temp.push(to_string(stoi(a)*stoi(b)));
                }
                else temp.push(to_string(stoi(b)/stoi(a)));
            }
        }
        return stoi(temp.top());
    }
};
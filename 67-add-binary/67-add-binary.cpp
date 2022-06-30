class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.length()-1, j = b.length()-1;
        string ans = "";
        while(i>=0 && j>= 0){
            int x = a[i]-'0';
            int y = b[j]-'0';
            int temp = x + y + carry;
            carry = temp/2;
            temp = temp%2;
            ans = to_string(temp) + ans;
            i--; j--;
        }
        while(i >= 0){
            int x = a[i]-'0';
            int temp = x + carry;
            carry = temp/2;
            temp = temp%2;
            ans = to_string(temp) + ans;
            i--;
        }
        while( j >= 0){
            int y = b[j]-'0';
            int temp = y + carry;
            carry = temp/2;
            temp = temp%2;
            ans = to_string(temp) + ans;
            j--;
        }
        if(carry){
            ans = '1' + ans;
        }
        return ans;
    }
};
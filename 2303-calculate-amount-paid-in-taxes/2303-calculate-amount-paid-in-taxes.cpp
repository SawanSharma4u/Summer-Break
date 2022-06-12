class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int income) {
        double ans = 0;
        if(income == 0) return ans;
        double sum = 0;
        int n = b.size();
        for(int i = 0; i < n; i++){
            if(b[i][0] <= income){
                if(i==0){
                    sum = (double)(b[0][0]*b[0][1])/100;
                }
                else sum += (double)((b[i][0]-b[i-1][0])*b[i][1])/100;
            }
            else{
                if(i==0){
                    sum += (double)((income)*b[i][1])/100;
                }
                else{
                    sum += (double)((income-b[i-1][0])*b[i][1])/100;
                }
                break;
            }
        }
        return sum;
        
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,pro=0,maxpro=0,buy=prices[0];
        
        for(i=0 ; i<prices.size() ; i++)
        {
            if(buy<prices[i])
            {
                pro=prices[i]-buy;
                if(maxpro<pro)
                    maxpro=pro;
            }
            
            else
                buy=prices[i];
        }
       return maxpro;
    }
};
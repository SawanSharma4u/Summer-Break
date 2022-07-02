class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        int maxdiffH = max(h-hC[hC.size()-1], hC[0]);
        int maxdiffV = max(w-vC[vC.size()-1], vC[0]);
        for(int i = 1; i < hC.size(); i++){
            maxdiffH = max(maxdiffH, hC[i]-hC[i-1]);
        }
        for(int i = 1; i < vC.size(); i++){
            maxdiffV = max(maxdiffV, vC[i]-vC[i-1]);
        }
        
        return (long)maxdiffV*maxdiffH%1000000007;
    }
};
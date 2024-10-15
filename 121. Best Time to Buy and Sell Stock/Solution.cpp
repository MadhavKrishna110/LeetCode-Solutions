class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm=INT_MAX;
        int maxm=0,ind=0,maxProfit =0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minm){
                minm = prices[i];
                ind = i;
            }
            if(prices[i]>=minm && i>ind){
                maxm= prices[i];
                maxProfit= max(maxProfit,maxm-minm);
            }
        }

        return maxProfit;
    }
};
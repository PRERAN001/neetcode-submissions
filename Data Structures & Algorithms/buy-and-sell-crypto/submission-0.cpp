class Solution {
public:
    int maxProfit(vector<int>& p) {
        int min_val=INT_MIN;
        int max_profit=0;
        for(int i=p.size()-1;i>=0;i--){
            min_val=p[i];
            for(int j=i-1;j>=0;j--){
                if(p[j]<min_val){
                    min_val=p[j];
                }
            }
            max_profit=max(max_profit,p[i]-min_val);
        }
        return max_profit;
    }
};

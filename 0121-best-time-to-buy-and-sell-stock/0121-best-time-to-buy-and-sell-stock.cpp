class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;
        int minSoFar = prices[0];

        for(int i = 0; i < prices.size(); i++){
            minSoFar = std::min(prices[i], minSoFar);
            int profit = prices[i] - minSoFar;
            maxProfit = std::max(profit, maxProfit);
        }

        return maxProfit;
    }
};
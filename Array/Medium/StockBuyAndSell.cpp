class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];  // make the first purchase
        int profit = 0;   //initial profit is zero
        for(int i = 1; i<prices.size(); i++){  //iterate through the loop
            if(prices[i] < buy){
                buy = prices[i];  //if you find a better price, buy it.
            }
            else if(prices[i] - buy > profit){ //check the profit with that purchase, if there is no better purchase
                profit = prices[i] - buy;
            }
        }
        return profit;  
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];  // max profit while holding a share
        int free = 0;           // max profit while not holding

        for (int i = 1; i < (int)prices.size(); i++) {
            free = max(free, hold + prices[i]);   // rest or sell
            hold = max(hold, -prices[i]);          // rest or buy
        }

        return free;
    }
};
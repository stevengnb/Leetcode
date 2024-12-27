class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size(), 0);
        stack<int> stc;

        for(int i = prices.size() - 1; i >= 0; i--) {
            int price = prices[i];
            if(stc.empty()) {
                ans[i] = price;
            } else if(stc.top() <= price) {
                ans[i] = price - stc.top();
            } else {
                while(!stc.empty() && stc.top() > price) stc.pop();
                if(stc.empty()) ans [i] = price;
                else ans[i] = price - stc.top();
            }
            
            stc.push(price);
        }

        return ans;
    }
};
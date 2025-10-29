class StockSpanner {
    stack<pair<int, int>> stack{};
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count{1};

        while (!stack.empty() && stack.top().first <= price) {
            count += stack.top().second;
            stack.pop();
        }
    
        stack.push(make_pair(price, count));

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

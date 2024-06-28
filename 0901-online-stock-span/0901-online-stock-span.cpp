class StockSpanner {
    stack<pair<int,int>> s;
    int i=0;
public:
    StockSpanner() {
        
    }
    
   int next(int price) {
        while (!s.empty() && s.top().first <= price) {
            s.pop();
        }

        int span;
        if (s.empty()) {
            span = i + 1;
        } else {
            span = i - s.top().second;
        }

        s.push({price, i});
        i++;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
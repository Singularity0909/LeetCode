
// @Title: 股票价格跨度 (Online Stock Span)
// @Author: Singularity0909
// @Date: 2020-09-29 19:48:26
// @Runtime: 456 ms
// @Memory: 73.6 MB

class StockSpanner {
public:
    stack<int> price, step;

    StockSpanner() {}
    
    int next(int price) {
        int sum = 1;
        while (!this->price.empty() and this->price.top() <= price) {
            this->price.pop();
            sum += this->step.top();
            step.pop();
        }
        this->price.push(price);
        step.push(sum);
        return sum;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

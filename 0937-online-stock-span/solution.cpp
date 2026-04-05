class StockSpanner {
public:
    stack<pair<int,int>> st; 
    int idx;
    StockSpanner() {
        idx=-1;
    }
    
    int next(int price) {
        idx++;
        //prev greater
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int previdx=(st.empty())?-1:st.top().second;
        int span=idx-previdx;
        st.push({price,idx});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

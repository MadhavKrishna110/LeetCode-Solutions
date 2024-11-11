class StockSpanner {
    vector<int> v;
    int ctr;
public:
    StockSpanner() {
        ctr=0;
    }
    
    int next(int price) {
        int i=ctr,cnt=0;
        while(i>0 && v[i-1]<=price){
            cnt++;
            i--;
        }
        v.push_back(price);
        ctr++;
        return cnt+1;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
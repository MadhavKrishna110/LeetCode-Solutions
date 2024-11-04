class MedianFinder {
    priority_queue<int> pqMax;
    priority_queue<int,vector<int>,greater<int>> pqMin;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqMax.empty() || pqMax.top()>num){
            pqMax.push(num);
        } else {
            pqMin.push(num);
        }

        if(pqMax.size()>pqMin.size()+1){
            pqMin.push(pqMax.top());
            pqMax.pop();
        } else if(pqMin.size()>pqMax.size()+1){
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
    }
    
    double findMedian() {
        if(pqMax.size()==pqMin.size()){
            if(pqMax.empty()) return 0;
            double avg = (pqMax.top()+pqMin.top())/2.0;
            return avg;
        } else {
           return (double) pqMax.size()>pqMin.size()?pqMax.top():pqMin.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
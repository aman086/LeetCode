/*
   We maintain 2 heaps:
    1. Max Heap (Left Side)
    2. Min Heap (Right Side)
    
    for furthur details, Follow youtube Anuj Bhaiya tutorial
*/
class MedianFinder {
public:
    priority_queue<int , vector<int> , greater<int>> right;
    priority_queue<int> left;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==0)
         left.push(num);
        else{

            if(num > left.top())
                right.push(num);
            else
                left.push(num);
            
        } 

        if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }

        if(left.size() - right.size() > 1){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        double result;
        if(left.size() == right.size()){
            result = (left.top() + right.top())/2.0;
            return result;
        }
            return (double)left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

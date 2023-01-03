class MedianFinder {
public:
    // 思路：维护一个大根堆和一个小根堆
    // 小根堆在上(倒三角形)，大根堆在下(三角形)，从上到下递减排序
    // 每次插入都先插入到大根堆
    // 1. 如果大根堆的堆顶元素大于小根堆的堆顶元素, 则交换这两个数
    // 2. 如果大根堆的元素个数大于小根堆的元素个数+1, 则将大根堆的堆顶元素插入小根堆
    priority_queue<int> maxHeap; // 大根堆
    priority_queue<int, vector<int>, greater<int>> minHeap; //小根堆
    
    void addNum(int num) {
        maxHeap.push(num);
        // 如果大根堆的堆顶大于小根堆的堆顶, 则交换这两个数
        if (minHeap.size() && maxHeap.top() > minHeap.top()) {
            int maxv = maxHeap.top(); maxHeap.pop();
            int minv = minHeap.top(); minHeap.pop();
            maxHeap.push(minv);
            minHeap.push(maxv);
        }
        // 如果大根堆的元素个数大于小根堆的元素个数+1
        // 则将大根堆的堆顶加入小根堆
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() != minHeap.size()) return maxHeap.top();
        else return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
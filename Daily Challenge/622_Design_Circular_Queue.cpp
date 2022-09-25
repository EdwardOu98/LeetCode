using namespace std;

class MyCircularQueue {
private:
    int* q;
    int front, rear;
    bool tag;
    int maxSize;
public:
    MyCircularQueue(int k) {
        maxSize = k;
        q = new int[k];
        front = rear = 0;
        tag = false;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        q[rear] = value;
        rear = (rear + 1) % maxSize;
        tag = true;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        
        front = (front + 1) % maxSize;
        tag = false;
        
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        
        int idx = (rear - 1 + maxSize) % maxSize;
        
        return q[idx];
    }
    
    bool isEmpty() {
        return (front == rear) && (!tag);
    }
    
    bool isFull() {
        return (front == rear) && tag;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

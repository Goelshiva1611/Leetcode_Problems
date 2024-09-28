class MyCircularDeque {
public:
    queue<int> qu;
    int size = 0;
    MyCircularDeque(int k) { size = k; }

    bool insertFront(int value) {
        if (qu.size() < size) {
            queue<int> p;
            while (!qu.empty()) {
                p.push(qu.front());
                qu.pop();
            }
            qu.push(value);
            while (!p.empty()) {
                qu.push(p.front());
                p.pop();
            }
            return true;
        }
        return false;
    }

    bool insertLast(int value) {
        if (qu.size() < size) {
            qu.push(value);
            return true;
        }
        return false;
    }

    bool deleteFront() {
        if (!qu.empty()) {
            qu.pop();
            return true;
        }
        return false;
    }

    bool deleteLast() {
        if (!qu.empty()) {
            queue<int> p;
            while (qu.size() != 1) {
                p.push(qu.front());
                qu.pop();
            }
            qu.pop();
            while (!p.empty()) {
                qu.push(p.front());
                p.pop();
            }
            return true;
        }
        return false;
    }

    int getFront() {
        if (!qu.empty()) {
            return qu.front();
        }
        return -1;
    }

    int getRear() {
        queue<int> p;
        p = qu;
        if (!qu.empty()) {
            queue<int> p;
            p = qu;
            while (p.size() != 1) {
                p.pop();
            }
            return p.front();
        }
        return -1;
    }

    bool isEmpty() {
        if (!qu.empty()) {
            return false;
        }
        return true;
    }

    bool isFull() {
        if (qu.size() == size) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
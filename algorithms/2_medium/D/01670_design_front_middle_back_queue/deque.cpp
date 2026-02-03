class FrontMiddleBackQueue {
    deque<int> q_l;
    deque<int> q_r;

    inline void balance_queues() {
        while (q_l.size() > q_r.size()) {
            q_r.push_front(q_l.back());
            q_l.pop_back();
        }

        while (q_r.size() - q_l.size() > 1) {
            q_l.push_back(q_r.front());
            q_r.pop_front();
        }
    }

public:
    FrontMiddleBackQueue(): q_l{}, q_r{} {
    }

    void pushFront(int val) {
        q_l.push_front(val);
    }

    void pushMiddle(int val) {
        balance_queues();
        q_l.push_back(val);
    }

    void pushBack(int val) {
        q_r.push_back(val);
    }

    int popFront() {
        if (!q_l.empty()) {
            const int val{ q_l.front() };
            q_l.pop_front();
            return val;
        } else if (!q_r.empty()) {
            const int val{ q_r.front() };
            q_r.pop_front();
            return val;
        }

        return -1;
    }

    int popMiddle() {
        balance_queues();

        if (q_l.size() == q_r.size()) {
            if (!q_l.empty()) {
                const int val{ q_l.back() };
                q_l.pop_back();
                return val;
            }
        } else {
            if (!q_r.empty()) {
                const int val{ q_r.front() };
                q_r.pop_front();
                return val;
            }
        }

        return -1;
    }

    int popBack() {
        if (!q_r.empty()) {
            const int val{ q_r.back() };
            q_r.pop_back();
            return val;
        } else if (!q_l.empty()) {
            const int val{ q_l.back() };
            q_l.pop_back();
            return val;
        }

        return -1;
    }
};

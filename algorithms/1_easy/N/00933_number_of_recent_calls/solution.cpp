class RecentCounter {
    queue<int> queue;
public:
    RecentCounter() : queue{} {}

    int ping(int t) {
        while (!queue.empty() && queue.front() < t - 3000) {
            queue.pop();
        }

        queue.push(t);

        return static_cast<int>(queue.size());
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

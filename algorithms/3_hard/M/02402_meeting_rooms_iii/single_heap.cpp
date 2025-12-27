class Solution {
    struct Room {
        long long free_at;
        int id;
        int count;

        bool operator<(const Room& other) const {
            if (free_at == other.free_at) {
                return id > other.id;
            }

            return free_at > other.free_at;
        }
    };
public:
    static int mostBooked(int n, vector<vector<int>>& meetings) {
        ranges::sort(meetings, [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        priority_queue<Room> rooms_heap;

        for (int i{0}; i < n; ++i) {
            rooms_heap.push({0, i, 0});
        }

        for (const auto& m : meetings) {
            const long long start {static_cast<long long>(m[0])};
            const long long end {static_cast<long long>(m[1])};

            while (rooms_heap.top().free_at < start) {
                auto temp_room {rooms_heap.top()};
                rooms_heap.pop();
                temp_room.free_at = start;
                rooms_heap.push(temp_room);
            }

            auto room {rooms_heap.top()};
            rooms_heap.pop();
            room.free_at += end - start;;
            room.count += 1;
            rooms_heap.push(room);
        }

        int max_count {-1};
        int max_id {-1};

        while (!rooms_heap.empty()) {
            const auto room {rooms_heap.top()};
            rooms_heap.pop();

            if (room.count > max_count) {
                max_id = room.id;
                max_count = room.count;
            } else if (room.count == max_count && room.id < max_id) {
                max_id = room.id;
            }
        }

        return max_id;
    }
};

class Solution {
    struct Room {
        long long free_at;
        int id;

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

        priority_queue<Room> in_use_rooms;
        priority_queue<int, vector<int>, greater<int>> free_rooms;
        vector<int> counts(static_cast<size_t>(n), 0);

        for (int i{0}; i < n; ++i) {
            free_rooms.push(i);
        }

        for (const auto& m : meetings) {
            const long long start {static_cast<long long>(m[0])};
            const long long end {static_cast<long long>(m[1])};

            while (!in_use_rooms.empty() && in_use_rooms.top().free_at <= start) {
                int id {in_use_rooms.top().id};
                in_use_rooms.pop();
                free_rooms.push(id);
            }

            if (free_rooms.empty()) {
                auto room {in_use_rooms.top()};
                in_use_rooms.pop();
                room.free_at += end - start;
                counts[static_cast<size_t>(room.id)] += 1;
                in_use_rooms.push(room);
            } else {
                int id {free_rooms.top()};
                free_rooms.pop();
                counts[static_cast<size_t>(id)] += 1;
                in_use_rooms.push({end, id});
            }
        }

        int max_count {-1};
        int max_id {-1};

        for (int i{0}; const auto& count : counts) {
            if (count > max_count) {
                max_count = count;
                max_id = i;
            }

            i += 1;
        }

        return max_id;
    }
};

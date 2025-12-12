class Solution {
    struct Data {
        char event_type;
        int timestamp;
        string body;
    };
public:
    inline static vector<int> countMentions(int& numberOfUsers, vector<vector<string>>& events) {
        const size_t len_users{static_cast<size_t>(numberOfUsers)};
        vector<int> res(len_users , 0);
        const size_t len_events{events.size()};
        vector<Data> events_data;
        events_data.reserve(len_events);
        int count_all{0};
        int count_here_minus_60{0};
        int count_here{0};
        queue<int> q{};

        for (auto& event : events) {
            const char event_type{event[0][0]};
            int ts{stoi(event[1])};

            if (event_type == 'O') {
                ts += 60;
            }

            events_data.emplace_back(event_type, ts, event[2]);
        }

        sort(events_data.begin(), events_data.end(), [](const auto& a, const auto &b) {
            if (a.timestamp == b.timestamp) {
                return a.event_type != 'M';
            }

            return a.timestamp < b.timestamp;
        });

        for (const auto& event : events_data) {
            while (!q.empty() && q.front() + 60 < event.timestamp) {
                count_here_minus_60 += 1;
                q.pop();
            }

            if (event.event_type == 'O') {
                const size_t id{static_cast<size_t>(stoi(event.body))};
                res[id] = res[id] - (count_here + count_here_minus_60);
            } else if (event.body[0] == 'H') {
                count_here += 1;
                q.push(event.timestamp);
            } else if (event.body[0] == 'A') {
                count_all += 1;
            } else {
                istringstream ss{move(event.body)};
                string part;

                while (ss>>part) {
                    const size_t id{static_cast<size_t>(stoi(part.substr(2)))};
                    res[id] += 1;
                }
            }
        }

        for (size_t i{0}; i < len_users; ++i) {
            res[i] += count_all + count_here;
        }

        return res;
    }
};

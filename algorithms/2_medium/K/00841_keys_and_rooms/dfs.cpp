class Solution {
    void dfs(vector<vector<int>>& rooms, vector<bool> &visiteds, size_t curr_room) {
        if (visiteds[curr_room]) {
            return;
        }

        visiteds[curr_room] = true;

        for (int &key: rooms[curr_room]) {
            dfs(rooms, visiteds, static_cast<size_t>(key));
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        vector<bool> visiteds{vector<bool>(rooms.size(), false)};

        dfs(rooms, visiteds, 0);

        for (const bool &is_visited: visiteds) {
            if (!is_visited) {
                return false;
            }
        }

        return true;
    }
};

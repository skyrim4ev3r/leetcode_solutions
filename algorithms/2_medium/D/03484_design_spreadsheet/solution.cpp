class Spreadsheet {
    unordered_map<string, int> grid;
public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        if (value != 0) {
            grid[cell] = value;
        }
    }

    void resetCell(string cell) {
        grid.erase(cell);
    }

    int getValue(string formula) {
        int sum = 0;

        stringstream ss(formula);
        string part;
        getline(ss, part, '='); // skip the '=' char

        while (getline(ss, part, '+')) {
            if (part[0] >= '0' && part[0] <= '9') {
                int num = std::stoi(part);
                sum += num;
            } else {
                auto it = grid.find(part);
                if (it != grid.end()) {
                    sum += it->second;
                }
            }
        }

        return sum;
    }
};

class Solution {
    static inline pair<string, size_t> get_atom_with_end_index(const string& formula, const size_t start, const size_t len) {
        size_t end{ start + 1};
        while (end < len && formula[end] >= 'a' && formula[end] <= 'z') {
            end += 1;
        }
        return { formula.substr(start, end - start), end };
    }

    static inline pair<int, size_t> get_count_with_end_index(const string& formula, const size_t start, const size_t len) {
        if (start >= len || !(formula[start] >= '0' && formula[start] <= '9')) {
            return {1, start};
        }

        int count{ 0 };
        size_t end{ start };

        while (end < len && formula[end] >= '0' && formula[end] <= '9') {
            count = count * 10 + static_cast<int>(formula[end] - '0');
            end += 1;
        }

        return { count, end };
    }
public:
    static string countOfAtoms(const string& formula) {
        const size_t len{ formula.size() };
        vector<unordered_map<string, int>> levels{};
        levels.push_back(unordered_map<string, int>{});
        size_t i{ 0 };

        while (i < len) {
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                const auto[atom, next_index] = get_atom_with_end_index(formula, i, len);
                const auto[atom_count, end_index] = get_count_with_end_index(formula, next_index, len);
                levels.back()[atom] += atom_count;
                i = end_index;
            } else if (formula[i] == '(') {
                levels.push_back(unordered_map<string, int>{});
                i += 1;
            } else if (formula[i] == ')') {
                const auto[multiplier, end_index] = get_count_with_end_index(formula, i + 1, len);
                const size_t curr_len_levels{ levels.size() };

                for (const auto& [atom, atom_count] : levels[curr_len_levels - 1]) {
                    levels[curr_len_levels - 2][atom] += atom_count * multiplier;
                }

                levels.pop_back();
                i = end_index;
            } else {
                throw "panic!(invalid input)";
            }
        }

        vector<string> res_vec;
        res_vec.reserve(levels[0].size());

        for (const auto& [atom, atom_count] : levels[0]) {
            if (atom_count == 1) {
                res_vec.push_back(atom);
            } else {
                res_vec.push_back(atom + to_string(atom_count));
            }
        }

        ranges::sort(res_vec);
        string final_res{};

        for (const auto& s : res_vec) {
            final_res += s;
        }

        return final_res;
    }
};

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        const size_t len_name{name.size()};
        const size_t len_typed{typed.size()};

        size_t index_typed{0};

        for (size_t i{0}; i < len_name; ++i) {
            if (typed[index_typed] != name[i]) {
                if (index_typed == 0) {
                    return false;
                }

                while (index_typed < len_typed && typed[index_typed] == typed[index_typed - 1]) {
                    index_typed += 1;
                }

                if (index_typed == len_typed || typed[index_typed] != name[i]) {
                    return false;
                }
            }

            index_typed += 1;

            if (index_typed == len_typed) {
                return i == (len_name - 1);
            }
        }

        while (index_typed > 0 && index_typed < len_typed && typed[index_typed] == typed[index_typed - 1]) {
            index_typed += 1;
        }

        return index_typed == len_typed;
    }
};

class Solution {
public:
    int compress(vector<char>& chars) {

        size_t write_index{0};
        size_t read_index{0};
        const size_t len{chars.size()};

        while (read_index < len) {

            int curr_count{1};
            const char curr_char{chars[read_index]};

            while (read_index < len - 1 && chars[read_index + 1] == chars[read_index]) {
                curr_count += 1;
                read_index += 1;
            }

            chars[write_index] = curr_char;
            write_index += 1;

            if (curr_count > 1) {

                int p{1};
                while (p <= curr_count) {
                    p *= 10;
                }

                p /= 10;
                while (p > 0) {
                    chars[write_index] = static_cast<char>((curr_count / p) % 10) +  '0';
                    write_index += 1;
                    p /= 10;
                }
            }

            read_index += 1;
        }

        return static_cast<int>(write_index);
    }
};

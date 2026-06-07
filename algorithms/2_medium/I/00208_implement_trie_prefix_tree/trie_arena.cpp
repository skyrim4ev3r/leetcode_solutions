constexpr size_t children_len = 26;

class Trie {
    struct TrieNode {
        bool is_end_of_word;
        uint16_t children[children_len];

        TrieNode() {
            is_end_of_word = false;
            std::memset(children, 0, sizeof(children));
        }
    };

    vector<TrieNode> arena;
public:
    Trie() {
        arena.push_back(TrieNode());
    }
    
    void insert(const string& word) {
        size_t curr = 0;

        for (const char ch : word) {
            const size_t child_idx = static_cast<size_t>(ch - 'a');
            assert(child_idx < children_len);

            if (arena[curr].children[child_idx] == 0) {
                arena.push_back(TrieNode());
                assert(arena.size() - 1 <= numeric_limits<uint16_t>::max());
                arena[curr].children[child_idx] = static_cast<uint16_t>(arena.size() - 1);
            }

            curr = arena[curr].children[child_idx];
        }

        arena[curr].is_end_of_word = true;
    }
    
    bool search(const string& word) {
        size_t curr = 0;

        for (const char ch : word) {
            const size_t child_idx = static_cast<size_t>(ch - 'a');
            assert(child_idx < children_len);
            curr = arena[curr].children[child_idx];

            if (curr == 0) {
                return false;
            }
        }

        return arena[curr].is_end_of_word;
    }
    
    bool startsWith(const string& prefix) {
        size_t curr = 0;

        for (const char ch : prefix) {
            const size_t child_idx = static_cast<size_t>(ch - 'a');
            assert(child_idx < children_len);
            curr = arena[curr].children[child_idx];

            if (curr == 0) {
                return false;
            }
        }

        return true;
    }
};

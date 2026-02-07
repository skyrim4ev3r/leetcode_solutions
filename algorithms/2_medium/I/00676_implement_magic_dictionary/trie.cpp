struct Trie {
private:
    unordered_map<char, std::unique_ptr<Trie>> next;
    bool is_end;
public:
    Trie() : is_end{ false }, next{} {}

    void insert(const string& key) {
        auto curr{ this };

        for (const auto& ch : key) {
            auto& next_node = curr->next[ch];
            if (!next_node) {
                next_node = std::make_unique<Trie>();
            }
            curr = next_node.get();
        }

        curr->is_end = true;
    }

    bool search_with_exact_diff(const string& prefix, int diff_count) const {
        const size_t CURR_INDEX{ 0 };

        return dfs_search_with_exact_diff(prefix, CURR_INDEX, diff_count);
    }
private:
    bool dfs_search_with_exact_diff(
        const string& prefix,
        const size_t curr_index,
        const int curr_diff_left
    ) const {
        if (curr_index == prefix.size()) {
            return curr_diff_left == 0 && this->is_end;
        }

        const char curr_char{ prefix[curr_index] };

        if (curr_diff_left > 0) {
            for (const auto& [char_key, next_node] : this->next) {
                if (char_key == curr_char) {
                    if (next_node->dfs_search_with_exact_diff(prefix, curr_index + 1, curr_diff_left)) {
                        return true;
                    }
                } else {
                    if (next_node->dfs_search_with_exact_diff(prefix, curr_index + 1, curr_diff_left - 1)) {
                        return true;
                    }
                }
            }
        } else {
            const auto it{ this->next.find(curr_char) };

            if (it == nullptr) {
                return false;
            }

            if (it->second->dfs_search_with_exact_diff(prefix, curr_index + 1, curr_diff_left)) {
                return true;
            }
        }

        return false;
    }
};

class MagicDictionary {
    Trie trie;
public:
    MagicDictionary() : trie{} {}

    void buildDict(const vector<string>& dictionary) {
        for (const auto& d : dictionary) {
            trie.insert(d);
        }
    }

    bool search(const string& searchWord) const {
        return trie.search_with_exact_diff(searchWord, 1);
    }
};

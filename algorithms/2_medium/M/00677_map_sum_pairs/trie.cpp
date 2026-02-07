struct Trie {
    unordered_map<char, std::unique_ptr<Trie>> next;
    int val;

    Trie() : val{ 0 } {}
};

class MapSum {
    Trie trie;
public:
    MapSum() : trie{} {}

    void insert(string key, int val) {
        Trie* curr{ &trie };

        for (const char& ch : key) {
            auto& next_node{ curr->next[ch] };
            if (!next_node) {
                next_node = std::make_unique<Trie>();
            }
            curr = next_node.get();
        }

        curr->val = val;
    }

    int dfs(Trie* curr) {
        int sum{ curr->val };
        for (const auto& p : curr->next) {
            sum += dfs(p.second.get());
        }
        return sum;
    }

    int sum(string prefix) {
        Trie* curr{ &trie };

        for (const char& ch : prefix) {
            const auto it{ curr->next.find(ch) };
            if (it == nullptr) {
                return 0;
            }
            curr = it->second.get();
        }

        return dfs(curr);
    }
};

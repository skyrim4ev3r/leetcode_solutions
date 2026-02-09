class MyLinkedList {
    struct Node {
        int val;
        shared_ptr<Node> next;
        shared_ptr<Node> prev;

        Node(int value) : val{ value }, next{ nullptr }, prev{ nullptr } {}
    };

    size_t len;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

    inline shared_ptr<Node> get_kth_from_begin(const size_t k) const {
        auto curr{ head };
        for (size_t i{ 0 }; i < k; ++i) {
            curr = curr->next;
        }
        return curr;
    }

    inline shared_ptr<Node> get_kth_from_end(const size_t k) const {
        auto curr{ tail };
        for (size_t i{ 0 }; i < k; ++i) {
            curr = curr->prev;
        }
        return curr;
    }
public:
    MyLinkedList() : len{ 0 }, head{ nullptr }, tail{ nullptr } {}

    int get(const int index) const {
        const size_t from_left{ static_cast<size_t>(index) };
        if (from_left >= len) { return -1; }
        const size_t from_right{ len - 1 - from_left };
        const auto curr{ from_left <= from_right ? get_kth_from_begin(from_left) : get_kth_from_end(from_right) };
        return curr->val;
    }

    void addAtHead(int val) {
        auto node = make_shared<Node>(val);

        if (!head) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }

        len += 1;
    }

    void addAtTail(int val) {
        auto node = make_shared<Node>(val);

        if (!tail) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        len += 1;
    }

    void addAtIndex(int index, int val) {
        const size_t from_left{ static_cast<size_t>(index) };
        if (from_left > len) { return; }
        const size_t from_right{ len - 1 - from_left };

        if (from_left == 0) {
            addAtHead(val);
        } else if (from_left == len) {
            addAtTail(val);
        } else {
            auto curr{ from_left <= from_right ? get_kth_from_begin(from_left) : get_kth_from_end(from_right) };
            auto node{ make_shared<Node>(val) };
            node->next = curr;
            node->prev = curr->prev;
            node->prev->next = node;
            curr->prev = node;

            len += 1;
        }
    }

    void deleteAtIndex(const int index) {
        const size_t from_left{ static_cast<size_t>(index) };
        if (from_left >= len) { return; }
        const size_t from_right{ len - 1 - from_left };

        if (len == 1) {
            head = nullptr;
            tail = nullptr;
            len = 0;
        } else if (from_left == 0) {
            head = head->next;
            head->prev = nullptr;
            len -= 1;
        } else if (from_right == 0) {
            tail = tail->prev;
            tail->next = nullptr;
            len -= 1;
        } else {
            auto curr{ from_left <= from_right ? get_kth_from_begin(from_left) : get_kth_from_end(from_right) };
            auto next{ curr->next };
            auto prev{ curr->prev };
            next->prev = prev;
            prev->next = next;
            len -= 1;
        }
    }
};

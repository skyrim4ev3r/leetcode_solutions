class Bank {
    vector<long long> balance;
public:
    Bank(vector<long long>& balance) : balance{move(balance)} {}

    bool transfer(int account1, int account2, long long money) {
        const size_t index1{static_cast<size_t>(account1) - 1};
        const size_t index2{static_cast<size_t>(account2) - 1};
        const size_t len{balance.size()};

        if (index1 >= len || index2 >= len || balance[index1] < money) {
            return false;
        }

        balance[index1] -= money;
        balance[index2] += money;

        return true;
    }

    bool deposit(int account, long long money) {
        const size_t index{static_cast<size_t>(account) - 1};
        const size_t len{balance.size()};

        if (index >= len) {
            return false;
        }

        balance[index] += money;

        return true;
    }

    bool withdraw(int account, long long money) {
        const size_t index{static_cast<size_t>(account) - 1};
        const size_t len{balance.size()};

        if (index >= len || balance[index] < money) {
            return false;
        }

        balance[index] -= money;

        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

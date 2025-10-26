class Bank:

    def __init__(self, balance: List[int]):
        # balance should get copy
        # to avoid any access to it from outside of class
        self.balance = balance.copy()

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        index1 = account1 - 1
        index2 = account2 - 1
        balance_len = len(self.balance)

        if index1 >= balance_len or index2 >= balance_len or self.balance[index1] < money:
            return False

        self.balance[index1] -= money
        self.balance[index2] += money

        return True

    def deposit(self, account: int, money: int) -> bool:
        index = account - 1
        balance_len = len(self.balance)

        if index >= balance_len:
            return False

        self.balance[index] += money

        return True

    def withdraw(self, account: int, money: int) -> bool:
        index = account - 1
        balance_len = len(self.balance)

        if index >= balance_len or self.balance[index] < money:
            return False

        self.balance[index] -= money

        return True

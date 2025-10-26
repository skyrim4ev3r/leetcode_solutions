struct Bank {
    balance: Vec<i64>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Bank {

    fn new(balance: Vec<i64>) -> Self {
        Self {
            balance,
        }
    }
    
    fn transfer(&mut self, account1: i32, account2: i32, money: i64) -> bool {
        let index1 = account1 as usize - 1;
        let index2 = account2 as usize - 1;
        let len = self.balance.len();

        if index1 >= len || index2 >= len || self.balance[index1] < money {
            return false;
        }

        self.balance[index1] -= money;
        self.balance[index2] += money;

        return true;
    }
    
    fn deposit(&mut self, account: i32, money: i64) -> bool {
        let index = account as usize - 1;
        let len = self.balance.len();

        if index >= len {
            return false;
        }

        self.balance[index] += money;

        return true;
    }
    
    fn withdraw(&mut self, account: i32, money: i64) -> bool {
        let index = account as usize - 1;
        let len = self.balance.len();

        if index >= len || self.balance[index] < money {
            return false;
        }

        self.balance[index] -= money;

        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * let obj = Bank::new(balance);
 * let ret_1: bool = obj.transfer(account1, account2, money);
 * let ret_2: bool = obj.deposit(account, money);
 * let ret_3: bool = obj.withdraw(account, money);
 */

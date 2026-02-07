/**
 * @param {string} s
 * @return {boolean}
 */
const checkValidString = (s) => {
    const len = s.length;
    let points = 0;
    let balance = 0;

    for (let i = 0; i < len; i += 1) {
        const curr_char = s[i];

        if (curr_char == ')') {
            balance -= 1;

            if (balance < 0) {
                if (points > 0) {
                    points -= 1;
                    balance += 1;
                } else {
                    return false;
                }
            }
        } else if (curr_char == '(') {
            balance += 1;
        } else {
            points += 1;
        }
    }

    balance = 0;
    points = 0;

    for (let i = len - 1; i >= 0; i -= 1) {
        const curr_char = s[i];

        if (curr_char == '(') {
            balance -= 1;

            if (balance < 0) {
                if (points > 0) {
                    points -= 1;
                    balance += 1;
                } else {
                    return false;
                }
            }
        } else if (curr_char == ')') {
            balance += 1;
        } else {
            points += 1;
        }
    }

    return true;
};

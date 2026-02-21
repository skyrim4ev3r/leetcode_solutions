const is_prime = (num) => {
    if (num === 2) {
        return true;
    }

    if (num <= 1 || num % 2 === 0) {
        return false;
    }

    const sqrt_num = Math.floor(Math.sqrt(num));

    for (let i = 3; i <= sqrt_num; i += 2) {
        if (num % i === 0) {
            return false;
        }
    }

    return true;
}

const check_prefix = (num) => {
    let prefix = num;
    while (prefix > 0) {
        if (!is_prime(prefix)) {
            return false;
        }

        prefix = Math.floor(prefix/ 10);
    }
    return true;
}

const check_suffix = (num) => {
    let suffix = num;
    let p = 1;

    while (Math.floor(suffix / p) >= 10) {
        p *= 10;
    }

    while (suffix > 0) {
        if (!is_prime(suffix)) {
            return false;
        }

        suffix = suffix - Math.floor(suffix / p) * p;
        p = Math.floor(p / 10);
    }

    return true;
}

/**
 * @param {number} num
 * @return {boolean}
 */
const completePrime = (num) => {
   return check_prefix(num) && check_suffix(num);
};

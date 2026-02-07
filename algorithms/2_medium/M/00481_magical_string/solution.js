/**
 * @param {number} n
 * @return {number}
 */
const magicalString = (target_len) => {
    if (target_len <= 3) {
        return 1;
    }

    let res = Array(target_len).fill(0);
    res[0] = 1;
    res[1] = 2;
    res[2] = 2;

    let right = 3
    let left = 2;
    let curr_num = 1;

    while (right < target_len) {
        res[right] = curr_num;
        right += 1;

        if (res[left] === 2 && right < target_len) {
            res[right] = curr_num;
            right += 1;
        }

        curr_num = curr_num === 1 ? 2 : 1;
        left += 1;
    }

    return res.filter(num => num === 1).length;
};

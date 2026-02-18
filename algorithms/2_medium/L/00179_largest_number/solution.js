/**
 * @param {number[]} nums
 * @return {string}
 */
const largestNumber = (nums) => {
    const numsStr = nums.map(num => num.toString());

    numsStr.sort((a, b) => {
        const a_len = a.length;
        const b_len = b.length;
        const total = a_len + b_len;

        for (let i = 0; i < total; ++i) {
            const a_index = i % a_len;
            const b_index = i % b_len;

            if (a[a_index] != b[b_index]) {
                return b[b_index].charCodeAt(0) - a[a_index].charCodeAt(0);
            }
        }

        return 0;
    });

    if (numsStr[0] == "0") {
        return "0";
    }

    return numsStr.join("");
};

/**
 * @param {string} s
 * @return {boolean}
 */
const checkOnesSegment = (s) => {
    const len = s.length;
    let count = 0;

    for (let i = 0; i < len; i += 1) {
        if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) {
            count += 1;

            if (count > 1) {
                return false;
            }
        }
    }

    return true;
};

/**
 * @param {number[]} citations
 * @return {number}
 */
const hIndex = (citations) => {
    const len = citations.length;
    let left = 0;
    let right = len - 1;
    let res = 0;

    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        const least_valid = len - mid;

        if (citations[mid] >= least_valid) {
            res = least_valid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return res;
};

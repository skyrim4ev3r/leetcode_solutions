/**
 * @param {number[]} citations
 * @return {number}
 */
const hIndex = (citations) => {
    citations.sort((a, b) => b - a);

    const len = citations.length;
    let res = 0;

    for (let i = 0; i < len; i += 1) {
        const count = i + 1;

        if (citations[i] >= count) {
            res = count;
        } else {
            break;
        }
    }

    return res;
};

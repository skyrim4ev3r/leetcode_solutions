const countOnes = (n) => {
    let count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count += 1;
    }
    return count;
}

/**
 * @param {number[]} arr
 * @return {number[]}
 */
const sortByBits = (arr) => {
    arr.sort((a, b) => {
        const aCountOnes = countOnes(a);
        const bCountOnes = countOnes(b);

        if (aCountOnes === bCountOnes) {
            return a - b;
        } else {
            return aCountOnes - bCountOnes;
        }
    });

    return arr;
};

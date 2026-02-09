/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
const maximumScore = (a, b, c) => {
    const stones = [a, b, c];
    stones.sort((a, b) => a - b);

    const [min, mid, max] = stones;

    return Math.min(Math.floor((max + min + mid) / 2), min + mid);
};

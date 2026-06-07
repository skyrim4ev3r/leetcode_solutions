int rangeBitwiseAnd(int signed_left, int signed_right)
{
    unsigned int shift = 0;
    unsigned int left = (unsigned int) signed_left;
    unsigned int right = (unsigned int) signed_right;

    while (right != left) {
        shift += 1;
        right = right >> 1u;
        left = left >> 1u;
    }

    return (int) (right << shift);
}

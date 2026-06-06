int titleToNumber(char* col_title)
{
    int count = 0;

    for(size_t i = 0; col_title[i] != '\0'; i += 1) {
        count = count * 26 + (col_title[i] - ('A' - 1));
    }

    return count;
}

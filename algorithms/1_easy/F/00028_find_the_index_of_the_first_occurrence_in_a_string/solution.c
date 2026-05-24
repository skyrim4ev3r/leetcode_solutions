int strStr(char* haystack, char* needle) {
    char* p = strstr(haystack, needle);

    if (p == NULL) {
        return -1;
    }

    return p - haystack;
}

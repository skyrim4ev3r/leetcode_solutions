typedef ptrdiff_t isize;

static int abs_int(const int a)
{
    return a < 0 ? -a : a;
}

int maxDistance(char* moves)
{
    assert(moves != NULL);
    int lr = 0;
    int ud = 0;
    int extra = 0;

    for (isize i = 0; moves[i] != '\0'; i += 1) {
        switch (moves[i]) {
            case 'U':
                ud += 1;
                break;
            case 'D':
                ud -= 1;
                break;
            case 'R':
                lr += 1;
                break;
            case 'L':
                lr -= 1;
                break;
            case '_':
                extra += 1;
                break;
            default:
                fprintf(stderr, "invalid input");
                abort();
                break;
        }
    }

    return abs_int(ud) + abs_int(lr) + extra;
}

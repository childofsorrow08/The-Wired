char *int_to_string(int value) {
    static char buffer[12];
    int i = 0;
    int negative = value < 0;

    unsigned int n = negative ? -(unsigned int)value : (unsigned int)value;

    do {
        buffer[i++] = '0' + n % 10;
        n /= 10;
    } while (n);

    if (negative) { buffer[i++] = '-'; }

    buffer[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return buffer;
}

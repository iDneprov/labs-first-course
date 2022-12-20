int main() {
    int Tc = 0, c;
    int k = 0;
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
        if (!(c > 47 && c < 58)) {
            if (Tc != 0) printf("0%d\n", Tc);
            Tc = 0;
            continue;
        } 
        Tc = Tc * 10 + (c - '0');
    }
}
#include <stdio.h>
#include <math.h>

float f(float x) {
    return sqrt(x) + sin(x) - 10;
}

int main() {
    float a, b, err;
    printf("Nhap (a, b) va sai so cho phep err: ");
    scanf("%f %f %f", &a, &b, &err);

    if (f(a) * f(b) >= 0) {
        printf("Khoang [%.2f, %.2f] khong chua nghiem hoac co nhieu nghiem.\n", a, b);
        return 1;
    }

    float c, delta;
    int count = 0;
    do {
        count++;
        c = (a + b) / 2;
        delta = b - a;

        if (fabs(f(c)) < err) break;

        if (f(a) * f(c) < 0) b = c;
        else a = c;

        printf("%3d | a = %.4f | b = %.4f | c = %.4f | f(c) = %.6f\n", count, a, b, c, f(c));
    } while (delta > err);

    printf("Nghiem gan dung: x = %.6f\n", c);
    printf("So lan lap: %d\n", count);

    return 0;
}


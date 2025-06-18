#include <stdio.h>
#include <math.h>

double h(double x) {
    return pow(3, x) - (5 * x + 8);
}

double secant(double x0, double x1, double eps) {
    double x2;
    int iter = 0;
    do {
        x2 = x1 - h(x1) * (x1 - x0) / (h(x1) - h(x0));
        x0 = x1;
        x1 = x2;
        iter++;
    } while (fabs(h(x2)) > eps);
    printf("So vong lap: %d\n", iter);
    return x2;
}

int main() {
    double root = secant(1, 4, 0.0001);
    printf("Nghiem gan dung la: %.6f\n", root);
    return 0;
}


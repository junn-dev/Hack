#include <stdio.h>
#include <math.h>

// Tính giá tr? da th?c P(x)
float P(float x, float a[], int n) {
	int i;
    float tong = 0;
    for (i = 0; i <= n; i++)
        tong += a[i] * pow(x, n - i);
    return tong;
}

int main() {
    int n, i;
    float a[20], a_val = -3, b_val = 7;
    int m = 10; // s? kho?ng (ch?n)
    float h = (b_val - a_val) / m;
    float S = 0;

    printf("Nhap bac da thuc: "); scanf("%d", &n);
    printf("Nhap %d he so a0 -> a%d:\n", n + 1, n);
    for (i = 0; i <= n; i++) scanf("%f", &a[i]);

    for (i = 0; i <= m; i++) {
        float x = a_val + i * h;
        float w = (i == 0 || i == m) ? 1 : (i % 2 == 0 ? 2 : 4);
        S += w * P(x, a, n);
    }

    S = S * h / 3;
    printf("Tich phan ~ %.6f\n", S);
    return 0;
}


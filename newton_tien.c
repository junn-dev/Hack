#include <stdio.h>

#define MAX 10

// Hàm f(x) = 2x / (x^2 + 1)
float fx(float x) {
    return (2 * x) / (x * x + 1);
}

// Tính hi?u ti?n
void tao_bang_hieu_tien(float f[][MAX], int n) {
	int j, i;
    for (j = 1; j < n; j++)
        for (i = 0; i < n - j; i++)
            f[i][j] = f[i+1][j-1] - f[i][j-1];
}

// Tính giai th?a
int giaithua(int n) {
    int i, gt = 1;
    for (i = 2; i <= n; i++) gt *= i;
    return gt;
}

int main() {
    int n, i;
    float x[MAX], f[MAX][MAX], xp, h, p, kq;

    printf("Nhap so diem: "); scanf("%d", &n);
    printf("Nhap cac moc x (deu cach):\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        f[i][0] = fx(x[i]);
    }

    tao_bang_hieu_tien(f, n);
    printf("Nhap x can noi suy: "); scanf("%f", &xp);

    h = x[1] - x[0];
    p = (xp - x[0]) / h;
    kq = f[0][0];
    float p_nhan = 1;

    for (i = 1; i < n; i++) {
        p_nhan *= (p - (i - 1));
        kq += (p_nhan * f[0][i]) / giaithua(i);
    }

    printf("f(%.2f) ~= %.6f\n", xp, kq);
    return 0;
}


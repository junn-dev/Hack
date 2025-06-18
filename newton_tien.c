#include <stdio.h>
#include <math.h>  // C?n cho pow()

#define MAX 10

// Hàm f(x) = 2^x / (x^2 + 1)
float fx(float x) {
    return pow(2, x) / (x * x + 1);
}

// Tính b?ng sai phân ti?n
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

// N?i suy Newton ti?n
float noisuy_newton(float x[], float f[][MAX], int n, float xp) {
    float h = x[1] - x[0];
    float p = (xp - x[0]) / h;
    float kq = f[0][0];
    float p_nhan = 1;

    int i;
    for (i = 1; i < n; i++) {
        p_nhan *= (p - (i - 1));
        kq += (p_nhan * f[0][i]) / giaithua(i);
    }
    return kq;
}

int main() {
    int n, i;
    float x[MAX], f[MAX][MAX], xp, kq;

    printf("Nhap so diem: "); scanf("%d", &n);
    printf("Nhap cac moc x (deu cach):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        f[i][0] = fx(x[i]);
    }
	
// Nh?p x và y th? công (n?u không dùng hàm fx)
//    for (i = 0; i < n; i++) {
//        printf("x[%d] = ", i); scanf("%f", &x[i]);
//        printf("y[%d] = ", i); scanf("%f", &f[i][0]);
//    }
	
    tao_bang_hieu_tien(f, n);
    printf("Nhap x can noi suy: ");
    scanf("%f", &xp);
    kq = noisuy_newton(x, f, n, xp);
    printf("f(%.2f) ~= %.6f\n", xp, kq);

//    float f1 = noisuy_newton(x, f, n, -1.5);
//    float f2 = noisuy_newton(x, f, n, 0.7);
//    printf("f(-1.5) ~= %.6f\n", f1);
//    printf("f(0.7)  ~= %.6f\n", f2);
//    printf("Tich f(-1.5) * f(0.7) = %.6f\n", f1 * f2);

    return 0;
}

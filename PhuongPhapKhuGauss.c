#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	float *A, *b, *x;
	int n;
	FILE *f = fopen("input.txt", "r");
	if (!f) {
		printf("Khong the mo file!\n");
		exit(1);
	}
	
	// Doc co cua ma tran
	fscanf(f, "%d", &n);
	
	// Cap phat bo nho cho ma tran
	A = (float*)malloc(n * n * sizeof(float));
	b = (float*)malloc(n * sizeof(float));
	x = (float*)malloc(n * sizeof(float));
	if (!A || !b || !x) {
		printf("Khong du bo nho!\n");
		exit(1);
	}
	
	int i, j;
	// Doc ma tran A
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf(f, "%f", &A[i * n + j]);
		}
	}
	
	// Doc ma tran b
	for (i = 0; i < n; i++) fscanf(f, "%f", &b[i]);
	
	fclose(f);
	
	int k;
	// Giai thuan
	for (k = 0; k < n - 1; k++) {
		for (i = k + 1; i < n; i++) {
			if (A[k * n + k] == 0) break;
			float tmp = A[i * n + k] / A[k * n + k];
			for (j = k; j < n; j++) {
				A[i * n + j] -= A[k * n + j] * tmp;
			}
			b[i] -= b[k] * tmp;
		}
	}
	
	// Giai nguoc
	for (i = n - 1; i >= 0; i--) {
		x[i] = b[i];
		for (j = i + 1; j < n; j++) {
			x[i] -= A[i * n + j] * x[j];
		}
		x[i] /= A[i * n + i];
	}
	
	for (i = 0; i < n; i++) printf("x%d = %.4f\n", i + 1, x[i]);
    
    free(A);
    free(b);
    free(x);
    
    return 0;
}

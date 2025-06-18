#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	float *A, *b, *T, *c, *x_old, *x_new;
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
	T = (float*)malloc(n * n * sizeof(float));
	c = (float*)malloc(n * sizeof(float));
	x_old = (float*)malloc(n * sizeof(float));
	x_new = (float*)malloc(n * sizeof(float));
	if (!A || !b || !T || !c || !x_old || !x_new) {
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
	
	// Chuyen doi T, c
	for (i = 0; i < n; i++) {
		c[i] = b[i] / A[i * n + i];
		for (j = 0; j < n; j++) {
			if (i != j) T[i * n + j] = - A[i * n + j] / A[i * n + i];
			else T[i * n + j] = 0;
		}
		x_old[i] = 0;
	}
	
	int count = 0;
	float err;
	// Phuong phap lap don
	do {
		count++;
		
		for (i = 0; i < n; i++) {
			x_new[i] = c[i];
			for (j = 0; j < n; j++) {
			    x_new[i] += T[i * n + j] * x_old[j];
			}
		}
		
		err = fabs(x_new[0] - x_old[0]);
		for (i = 1; i < n; i++) {
			float tmp = fabs(x_new[i] - x_old[i]);
			if (tmp > err)
			err = tmp;
		}
		
		for (i = 0; i < n; i++) x_old[i] = x_new[i];
		
	} while (err > 0.0001);
	
	for (i = 0; i < n; i++) printf("x%d = %.2f\n", i, x_new[i]);
	printf("So lan lap la %d lan\n", count);
	
	free(A);
	free(b);
	free(T);
	free(c);
	free(x_old);
	free(x_new);
	
	return 0;
}

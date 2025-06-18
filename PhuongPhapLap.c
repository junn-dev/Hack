#include <stdio.h>
#include <math.h>

float g(float x) {
	return sqrt(2 * x + 5);
}

int main() {
	float x_old, x_new;
	int k;
	printf("Nhap x0, k: ");
	scanf("%f %d", &x_old, &k);
	
	int count = 0;
	float delta;
	do {
		x_new = g(x_old);
		x_old = x_new;
		count++;
	} while (count < k);
	
    printf("x%d = %.6f\n", k, x_new);
}

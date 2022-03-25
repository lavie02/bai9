#include <stdio.h>
#include <math.h>

void nhapN(int &n) {
	printf("\nNhap so luong phan tu cua mang: ");
	scanf("%d", &n);
}

void nhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

void xuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("\nA[%d] = %d", i, a[i]);
	}
}

int soDaoNguoc(int n) {
	int p = 0, t;
	while (n > 0) {
		t = n % 10;
		p = p * 10 + t;
		n /= 10;
	}
	return p;
}

int checkSNT(int n) {
	if (n < 2) {
		return 0;
	}
	for (int i = 3; i < sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int checkSNTNguoc(int n) { 
	if (checkSNT(n) && checkSNT(soDaoNguoc(n))) {
		return 1;
	}
	return 0;
}

int demSNTNguoc(int a[], int n) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (checkSNTNguoc(a[i])) {
			++dem;
		}
	}
	return dem;
}

int tong(int a[], int n) {
	int s = 0;
	for (int i = 0; i < n ; i++) {
		if (checkSNTNguoc(a[i])) {
			s += a[i];
		}
	}
	return s;
}



int main () {
	int n;
	nhapN(n);
	int a[n];
	nhapMang(a, n);
	xuatMang(a, n);
	int dem = demSNTNguoc(a, n);
	printf("\nCo %d so nguyen to thoa man dieu kien!", dem);
	int s = tong(a, n);
	printf("\nTong cac so nguyen to thoa man: %d", s);
	return 0;
}
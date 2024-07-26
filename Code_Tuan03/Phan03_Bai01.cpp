#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 100

void Tao_Mang2C(int a[MAXSIZE][MAXSIZE], int &n, int &m)
{
	printf("Nhap so dong n:");
	scanf("%d", &n);
	printf("Nhap so cot m:");
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}

void Xuat_Mang2C(int a[MAXSIZE][MAXSIZE], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int Tong_GiaTri(int a[MAXSIZE][MAXSIZE], int n, int m)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tong += a[i][j];
		}
	}
	return tong;
}

void Max_TheoCot(int a[MAXSIZE][MAXSIZE], int n, int m)
{
	for (int j = 0; j < m; j++)
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i][j] >= max)
			{
				max = a[i][j];
			}
		}
		printf("Phan tu lon nhat theo cot %d la: %d\n", j, max);
	}
}

void xuat_Cau4(int a[MAXSIZE][MAXSIZE], int n, int m)
{
	int i;

	// Xuất các phần tử của đường biên trên
	for (i = 0; i < m; i++) {
		printf("%d ", a[0][i]);
	}

	// Xuất các phần tử của đường biên phải
	for (i = 1; i < n; i++) {
		printf("%d ", a[i][m - 1]);
	}

	// Xuất các phần tử của đường biên dưới (nếu có nhiều hơn 1 hàng)
	if (n > 1) {
		for (i = m - 2; i >= 0; i--) {
			printf("%d ", a[n - 1][i]);
		}
	}

	// Xuất các phần tử của đường biên trái (nếu có nhiều hơn 1 cột)
	if (m > 1) {
		for (i = n - 2; i > 0; i--) {
			printf("%d ", a[i][0]);
		}
	}
}

int KiemTra_CucDai(int a[MAXSIZE][MAXSIZE], int n, int m, int i, int j)
{
	int current = a[i][j];

	// Kiểm tra phần tử bên trên
	if (i > 0 && current <= a[i - 1][j]) {
		return 0;
	}

	// Kiểm tra phần tử bên dưới
	if (i < n - 1 && current <= a[i + 1][j]) {
		return 0;
	}

	// Kiểm tra phần tử bên trái
	if (j > 0 && current <= a[i][j - 1]) {
		return 0;
	}

	// Kiểm tra phần tử bên phải
	if (j < m - 1 && current <= a[i][j + 1]) {
		return 0;
	}

	return 1;
}

void XuatPT_CucDai(int a[MAXSIZE][MAXSIZE], int n, int m) {
	int i, j;
	printf("Cac phan tu cuc dai la:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (KiemTra_CucDai(a, n, m, i, j)==1) {
				printf("%d tai vi tri (%d, %d)\n", a[i][j], i, j);
			}
		}
	}
}

int xetDuongCheo (int a[][100], int dong, int cot, int i, int j)
{
	int k, h; //k: dong, h: cot
	for (k=i, h=j; k>=0 && h<cot; k--, h++)
		if (a[k][h] > a[i][j])
			return 0;
	for (k=i+1, h=j-1; k<dong && h>=0; k++, h--)
		if (a[k][h] > a[i][j])
			return 0;
	for (k=i-1, h =j-1; k>=0 && h>=0; k--, h--)
		if (a[k][h] > a[i][j])
			return 0;
	for (k=i+1, h=j+1; k<dong && h<cot; k++, h++)
		if (a[k][h] > a[i][j])
			return 0;
	return 1;
}

int xetCotDong (int a[][100], int dong, int cot, int i, int j)
{
	for (int k=0; k<dong; k++)
		if (a[k][j]>a[i][j])
			return 0;
	for (int k=0; k<cot; k++)
		if (a[i][k]>a[i][j])
			return 0;
	return 1;
} 

int xetTongQuat (int a[][MAXSIZE], int dong, int cot, int i, int j)
{
	if (xetCotDong(a, dong, cot, i, j)==1)
		if (xetDuongCheo(a, dong, cot, i, j)==1)
			return 1;
	return 0;
}

void xetPT_HoangHau(int a[MAXSIZE][MAXSIZE], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (xetTongQuat(a,n,m,i,j)==1)
			{
				printf("%d ", a[i][j]);
			}
		}
	}
}
int ktra_PT_YenNgua(int a[][MAXSIZE], int n, int m, int i, int j)
{
    int k;
    int current = a[i][j];
    
    // Kiểm tra xem nó có phải là nhỏ nhất trong hàng của nó không
    for (k = 0; k < m; k++)
	{
        if (a[i][k] < current)
		{
            return 0;
        }
    }
    
    // Kiểm tra xem nó có phải là lớn nhất trong cột của nó không
    for (k = 0; k < n; k++)
	{
        if (a[k][j] > current)
		{
            return 0;
        }
    }
    
    return 1;
}

void xuatPT_YenNgua(int a[MAXSIZE][MAXSIZE], int n, int m)
{
    int i, j;
	int t=0;
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < m; j++)
		{
			if (ktra_PT_YenNgua(a, n, m, i, j)==1)
			{
                printf("%d tai vi tri (%d, %d)\n", a[i][j], i, j);
				t=1;
            }
        }
    }

	if (t==0)
	{
		printf("Khong co phan tu YEN NGUA nao\n");
	}
}

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n, m;
	Tao_Mang2C(a, n, m);
	Xuat_Mang2C(a, n, m);
	printf("\n--------------------------------\n");
	printf("Tong cac gia tri trong mang: %d", Tong_GiaTri(a, n, m));
	printf("\n--------------------------------\n");
	Max_TheoCot(a, n, m);
	printf("\n--------------------------------\n");
	xuat_Cau4(a, n, m);
	printf("\n--------------------------------\n");
	XuatPT_CucDai(a, n, m);
	printf("\n--------------------------------\n");
	printf("CAC PHAN TU HOANG HAU LA:\n");
	xetPT_HoangHau(a,n,m);
	printf("\n--------------------------------\n");
	printf("CAC DIEM YEN NGUA LA:\n");
	xuatPT_YenNgua(a,n,m);
	getch();
	return 0;
}
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

void xuat_CotCoSoLe(int a[][MAXSIZE], int n, int m)
{
    int isOddColumn;
	int t=0;
    printf("Cac cot chi chua so le la:\n");
    for (int j = 0; j < m; j++)
	{
        isOddColumn = 1; // Giả sử cột này chỉ chứa số lẻ

        for (int i = 0; i < n; i++)
		{
            if (a[i][j]%2 == 0)
			{
                isOddColumn = 0; // Tìm thấy số chẵn trong cột
				t++;
                break;
            }
        }

        if (isOddColumn==1)
		{
            printf("Cot %d: ", j);
            for (int i = 0; i < n; i++)
			{
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
	if (t==m)
	{
		printf("Khong co cot nao chi chua so le!!!\n");
	}
}

int tim_MaxTrenDuongBien(int a[][MAXSIZE], int n, int m) 
{
    int i;
    int max = 0;

    // Duyệt qua hàng đầu tiên và hàng cuối cùng
	for (i = 0; i < m; i++) {
        if (a[0][i] >= max) {
            max = a[0][i];
        }
        if (a[n-1][i] >= max) {
			max = a[n-1][i];
        }
    }

    // Duyệt qua cột đầu tiên và cột cuối cùng (loại trừ các góc đã duyệt)
	for (i = 1; i < n - 1; i++) {
        if (a[i][0] >= max) {
            max = a[i][0];
        }
        if (a[i][m-1] >= max) {
            max = a[i][m-1];
        }
    }

    return max;
}

int ktra_ChuaChuSo2(int num)
{
    while (num != 0)
	{
        if (num % 10 == 2)
		{
            return 1;
        }
        num /= 10;
    }
    return 0;
}

int ktra_PTCucTieu(int a[][MAXSIZE], int n, int m, int i, int j) {
    int current = a[i][j];

    // Kiểm tra phần tử phía trên
    if (i > 0 && a[i - 1][j] <= current) {
        return 0;
    }

    // Kiểm tra phần tử phía dưới
    if (i < n - 1 && a[i + 1][j] <= current) {
        return 0;
    }

    // Kiểm tra phần tử phía trái
    if (j > 0 && a[i][j - 1] <= current) {
        return 0;
    }

    // Kiểm tra phần tử phía phải
    if (j < m - 1 && a[i][j + 1] <= current) {
        return 0;
    }

    return 1;
}

void xuat_PTCucTieu(int a[][MAXSIZE], int n, int m) 
{
    printf("Cac phan tu cuc tieu cua ma tran la:\n");
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			if (ktra_PTCucTieu(a, n, m, i, j)) {
                printf("%d tai vi tri (%d, %d)\n", a[i][j], i, j);
            }
        }
    }
}

int demSoPT_ChuaChuSo2(int a[][MAXSIZE], int n, int m)
{
    int count = 0;

	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < m; j++)
		{
			if (ktra_ChuaChuSo2(a[i][j]))
			{
                count++;
            }
        }
    }

    return count;
}

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n,m;
	Tao_Mang2C(a,n,m);
	Xuat_Mang2C(a,n,m);
	printf("\n------------------------------------\n");
	xuat_CotCoSoLe(a,n,m);
	printf("\n------------------------------------\n");
	printf("Phan tu max tren duong bien la: %d\n", tim_MaxTrenDuongBien(a,n,m));
	printf("\n------------------------------------\n");
	printf("So phan tu trong ma tran co chua chu so 2 la: %d\n", demSoPT_ChuaChuSo2(a,n,m));
	printf("\n------------------------------------\n");
	xuat_PTCucTieu(a,n,m);
	getch();
	return 0;
}
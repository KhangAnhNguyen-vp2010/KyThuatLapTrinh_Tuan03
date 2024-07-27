#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 100

void tao_MangCapN(int a[][MAXSIZE], int &n)
{
	printf("Nhap n:");
	scanf("%d", &n);
	while (n<5)
	{
		printf("n phai >= 5!!!\n");
		printf("Nhap lai n:");
		scanf("%d", &n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j]=rand()%10;
		}
	}
}

void xuat_Mang(int a[][MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp một mảng tăng dần
void sort_Tang(int a[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            if (a[i] > a[j]) 
			{
                swap(&a[i], &a[j]);
            }
        }
    }
}

// Hàm sắp xếp một mảng giảm dần
void sort_Giam(int a[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            if (a[i] < a[j]) 
			{
                swap(&a[i], &a[j]);
            }
        }
    }
}

void sortAntiDiagonal(int a[][MAXSIZE], int n, int ascending) {
    int diag[100]; // Mảng để lưu các phần tử của đường chéo phụ
    int i;

    // Lấy các phần tử của đường chéo phụ
    for (i = 0; i < n; i++) {
        diag[i] = a[i][n - 1 - i];
    }

    // Sắp xếp các phần tử của đường chéo phụ
    if (ascending) {
		sort_Tang(diag, n);
    } else {
		sort_Giam(diag, n);
    }

    // Gán lại các phần tử đã sắp xếp vào đường chéo phụ
    for (i = 0; i < n; i++) {
        a[i][n - 1 - i] = diag[i];
    }
}

void sortMatrix(int a[][MAXSIZE], int n)
{
    int i;
	for (i = 0; i < n; i++)
	{
        if (i % 2 == 0) 
		{
            // Dòng có chỉ số chẵn, sắp xếp giảm dần
			sort_Giam(a[i], n);
        } 
		else 
		{
            // Dòng có chỉ số lẻ, sắp xếp tăng dần
            sort_Tang(a[i], n);
        }
    }
}

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n;
	tao_MangCapN(a,n);
	xuat_Mang(a,n);
	printf("\n---------------------------------------\n");
	printf("Nhap 1 de sap xep tang dan - 0 de sap xep giam dan:");
	int c;
	scanf("%d", &c);
	sortAntiDiagonal(a,n,c);
	xuat_Mang(a,n);
	printf("\n---------------------------------------\n");
	printf("SAP XEP DONG CHI SO LE TANG DAN - DONG CHI SO CHAN GIAM DAN\n");
	sortMatrix(a,n);
	xuat_Mang(a,n);
	getch();
	return 0;
}
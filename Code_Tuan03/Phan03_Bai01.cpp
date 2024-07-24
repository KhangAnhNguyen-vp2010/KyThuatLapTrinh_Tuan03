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
	getch();
	return 0;
}
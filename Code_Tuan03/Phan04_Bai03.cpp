﻿#include<stdio.h>
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

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n,m;
	Tao_Mang2C(a,n,m);
	Xuat_Mang2C(a,n,m);
	printf("\n------------------------------------\n");
	xuat_CotCoSoLe(a,n,m);
	getch();
	return 0;
}
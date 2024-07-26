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

void xuatPT_DuongCheoChinh(int a[][MAXSIZE], int n)
{
    printf("Cac phan tu tren duong cheo chinh la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n;
	tao_MangCapN(a,n);
	xuat_Mang(a,n);
	printf("\n----------------------------------\n");
	xuatPT_DuongCheoChinh(a,n);
	getch();
	return 0;
}
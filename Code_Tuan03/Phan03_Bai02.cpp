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
    for (int i = 0; i < n; i++)
	{
        printf("%d ", a[i][i]);
    }
    printf("\n");
}

void xuatPT_DuongCheoSongSong(int a[][MAXSIZE], int n)
{
    // Các đường chéo song song nằm trên đường chéo chính (bao gồm cả đường chéo chính)
    for (int k = 0; k < n; k++)
	{
        printf("Cac phan tu cua duong cheo bat dau tu (0, %d):\n", k);
        for (int i = 0, j = k; i < n && j < n; i++, j++) 
		{
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Các đường chéo song song nằm dưới đường chéo chính
    for (int k = 1; k < n; k++) {
        printf("Cac phan tu cua duong cheo bat dau tu (%d, 0):\n", k);
        for (int i = k, j = 0; i < n && j < n; i++, j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int tim_MAX_ThuocTamGiac_TrenDC_Chinh(int a[][MAXSIZE], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
	{
        for (int j = i; j < n; j++)
		{
            if (a[i][j] >= max)
			{
                max = a[i][j];
            }
        }
    }

    return max;
}

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n;
	tao_MangCapN(a,n);
	xuat_Mang(a,n);
	printf("\n----------------------------------\n");
	xuatPT_DuongCheoChinh(a,n);
	printf("\n----------------------------------\n");
	xuatPT_DuongCheoSongSong(a,n);
	printf("\n----------------------------------\n");
	printf("Phan tu lon nhat thuoc tam giac tren duong cheo chinh la: %d\n", tim_MAX_ThuocTamGiac_TrenDC_Chinh(a,n));
	getch();
	return 0;
}
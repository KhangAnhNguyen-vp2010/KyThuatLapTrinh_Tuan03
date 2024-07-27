#include<stdio.h>
#include<conio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>
#define MAXSIZE 100

void nhap_Chuoi(char s[])
{
	printf("Nhap chuoi:");
	gets(s);
}

void xuat_Chuoi(char s[])
{
	printf("Chuoi vua nhap la:");
	puts(s);
}

int isAllDigits(char s[])
{
    for (int i = 0; i < strlen(s); i++)
	{
        if (!isdigit(s[i]))
		{
            return 0; // Không phải là ký số
        }
    }
    return 1; // Toàn ký số
}

int main()
{
	char s[MAXSIZE];
	nhap_Chuoi(s);
	xuat_Chuoi(s);
	printf("\n-------------------------------------------------\n");
	if (isAllDigits(s)) {
        printf("Chuoi chua toan ky so.\n");
    } else {
        printf("Chuoi khong chua toan ky so.\n");
    }
	getch();
	return 0;
}
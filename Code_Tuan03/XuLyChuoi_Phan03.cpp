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

void bienDoi_Chuoi(char s[])
{
    int inWord = 0; 

    for (int i = 0; s[i] != '\0'; i++)
	{
        if (isalpha(s[i]))
		{
            if (!inWord)
			{ 
                s[i] = toupper(s[i]);
                inWord = 1;
            } 
			else 
			{
                s[i] = tolower(s[i]);
            }
        } 
		else 
		{
            inWord = 0;
        }
    }
}

void chuanHoa_Chuoi(char str[]) 
{
    int x = 0;
    int spaceFlag = 0;
    for (int i = 0; str[i]; i++) 
	{
        if (!isspace(str[i])) 
		{
            if (spaceFlag && x > 0) 
			{
                str[x++] = ' ';
            }
            str[x++] = str[i];
            spaceFlag = 0;
        } 
		else if (x > 0)
		{
            spaceFlag = 1;
        }
    }
	str[x] = '\0';

    if (isspace(str[0])) 
	{
        for (int i = 0; str[i]; i++)
		{
            str[i] = str[i + 1];
        }
    }
}

void findNameInFullName(char fullName[], char name[]) 
{
    if (strstr(fullName, name) != NULL)
	{
        printf("Chuoi '%s' ton tai trong chuoi: %s\n", name, fullName);
    } 
	else 
	{
        printf("Chuoi '%s' khong ton tai trong chuoi.\n", name);
    }
}


int main()
{
	char s[MAXSIZE];
	nhap_Chuoi(s);
	xuat_Chuoi(s);
	printf("\n-------------------------------------------------\n");
	if (isAllDigits(s)) 
	{
        printf("Chuoi chua toan ky so.\n");
    } else 
	{
        printf("Chuoi khong chua toan ky so.\n");
    }
	printf("\n-------------------------------------------------\n");
	bienDoi_Chuoi(s);
	printf("Chuoi sau khi bien doi:\n");
	xuat_Chuoi(s);
	printf("\n-------------------------------------------------\n");
	printf("Chuoi sau khi chuan hoa:\n");
	chuanHoa_Chuoi(s);
	xuat_Chuoi(s);
	printf("\n-------------------------------------------------\n");
	char str2[MAXSIZE];
	printf("Nhap chuoi con can tim kiem:\n");
	nhap_Chuoi(str2);
	findNameInFullName(s,str2);
	getch();
	return 0;
}
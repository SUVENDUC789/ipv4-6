#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void class_of_IP(int );
void binary_IPv4(int );
void check_IPv4_or_not(char *);

int main()
{
    int n = 25;
   
    char ch[100] = "55.132.042.143";
    printf("\nEnter IPv4 Address : ");
    gets(ch);
   
    check_IPv4_or_not(ch);


    getch();
    return 0;
}
void binary_IPv4(int n)
{
    static int number = 0;
  
    int a[] = { 128, 64, 32, 16, 8, 4, 2, 1}, i;
    int b[] = { 0, 0, 0, 0, 0, 0, 0, 0};
    int size = sizeof(a) / sizeof(int);
    for (i = 0; i < size; i++)
    {
        if (n > a[i] || n == a[i])
        {
            n -= a[i];
            b[i] = 1;
        }
    }
    for (i = 0; i < size; i++)
        printf("%d", b[i]);
    number++;
    if (number == 1)
    {
        printf(".");
    }
    else if (number == 2)
    {
        printf(".");
    }
    else if (number == 3)
    {
        printf(".");
    }
    return;
}

void check_IPv4_or_not(char *ch)
{
    int i, j, sum = 0, number = 0, n;
    for (j = 0; j < strlen(ch); j++)
    {
        for (i = j; ch[i] != '.' && ch[i] != '\0'; i++)
        {
            n = (int)ch[i];
            number = n - 48;
            sum = (sum * 10) + number;
        }
        if (sum > 255 || sum < 0)
        {
            printf("\nThis is not Perfect IPv4 !");
            exit(404);
        }
        j = i;
        sum = 0;
    }
    printf("\nBianry form IPv4 address :>\t");
    for (j = 0; j < strlen(ch); j++)
    {
        for (i = j; ch[i] != '.' && ch[i] != '\0'; i++)
        {
            n = (int)ch[i];
            number = n - 48;
            sum = (sum * 10) + number;
        }
        
        binary_IPv4(sum);
        j = i;
        sum = 0;
    }
    for (j = 0; j < 2; j++)
    {
        for (i = j; ch[i] != '.' && ch[i] != '\0'; i++)
        {
            n = (int)ch[i];
            number = n - 48;
            sum = (sum * 10) + number;
        }
        
//        printf("\nFirst octed : %d",sum);
		class_of_IP(sum);
        j = i;
        sum = 0;
    }
}

void class_of_IP(int number)
{
	if(number>=0 && number<=127)
	{
		printf("\n\n\tThis is Class A IP");
		printf("\n\nDefault Subnet mask :> 255.0.0.0 \t CIDR value is = /8");
	}
	else if(number>=128 && number<=191)
	{
		printf("\n\n\tThis is Class B IP");
		printf("\n\nDefault Subnet mask :> 255.255.0.0 \t CIDR value is = /16");
	}
	else if(number>=192 && number<=223)
	{
		printf("\n\n\tThis is Class C IP");
		printf("\n\nDefault Subnet mask :> 255.255.255.0 \t CIDR value is = /24");
	}
	else if(number>=224 && number<=239)
	{
		printf("\n\n\tThis is Class D IP");
	}
	else if(number>=240 && number<=255)
	{
		printf("\n\n\tThis is Class E IP");
	}
}


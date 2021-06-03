/* Weakness4 code */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int unsafe_foo(int x)
{
    char *str;
    int len=x;
    int size=len*sizeof(char);
    str=(char*)malloc(size);
    memset(str,'A',size);
    str[len-1]='\0';
    int res=(int)str[len/2];
	/* error: do not free the memory space allocated */
    return res;
}

int safe_foo(int x)
{
    char *str;
    int len=x;
    int size=len*sizeof(char);
    str=(char*)malloc(size);
    memset(str,'A',size);
    str[len-1]='\0';
    int res=(int)str[len/2];

    free(str);

    return res;
}

int main()
{
    printf("Begin to test Weakness4 code...\n");
    int a,unsafe_res,safe_res;
    printf("Please enter the value of x: x=");
    scanf_s("%d",&a);

    printf("Invoke unsafe function...\n");
    unsafe_res=unsafe_foo(a);
    printf("return value of unsafe function:%d\n",unsafe_res);

    printf("Invoke safe functtion...\n");
    safe_res=safe_foo(a);
    printf("return value of safe function:%d\n",safe_res);

    if(unsafe_res==safe_res) printf("Successful!\n");
    else printf("Failed!\n");

    return 0;
}
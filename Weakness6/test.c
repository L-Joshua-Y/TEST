/* Weakness6 code */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int unsafe_foo(int x)
{
    int len=10;
    char *str=(char*)malloc(len*sizeof(char));
    memset(str,'A',len*sizeof(char));
    int tmp=(int)str[0];
    free(str);
    int ttmp=(int)str[0]; //<- error CWE-416

    return tmp;
}

int safe_foo(int x)
{
    int len=10;
    char *str=(char*)malloc(len*sizeof(char));
    memset(str,'A',len*sizeof(char));
    int tmp=(int)str[0];
    free(str);
    //int ttmp=(int)str[0];

    return tmp;
}

int main()
{
    printf("Begin to test Weakness6 code...\n");
    printf("Please enter x=");
    int x,unsafe_res,safe_res;
    scanf_s("%d",&x);
    printf("Invoke unsafe function...\n");
    unsafe_res=unsafe_foo(x);
    printf("unsafe_res=%d\n",unsafe_res);
    printf("Invoke safe function...\n");
    safe_res=safe_foo(x);
    printf("safe_res=%d\n",safe_res);

    if(unsafe_res==safe_res) printf("Successful!\n");
    else printf("Failed!\n");

    return 0;
}
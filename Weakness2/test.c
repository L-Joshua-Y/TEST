/* Weakness2 code */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int unsafe_foo(int x)
{
    int len=x;
    char *str1=(char*)malloc(len*sizeof(char));
    char *str2=(char*)malloc(len/2*sizeof(char));
    memset(str1,0,len*sizeof(char));
    memset(str2,0,len/2*sizeof(char));
    strcpy(str1,str2);	//<- error CWE-120

    int res=(int)str1[0];

    free(str1);
    free(str2);
    
    return res;
}

int safe_foo(int x)
{
    int len=x;
    char *str1=(char*)malloc(len*sizeof(char));
    char *str2=(char*)malloc(len/2*sizeof(char));
    memset(str1,0,len*sizeof(char));
    memset(str2,0,len/2*sizeof(char));
    strcpy_s(str1,len/2,str2);

    int res=(int)str1[0];

    free(str1);
    free(str2);
    
    return res;
}

int main()
{
    printf("Begin to test Weakness2 code...\n");
    printf("Please enter x=");
    int x,unsafe_res,safe_res;
    scanf_s("%d",&x);
    printf("Invoke unsafe function...\n");
    unsafe_res=unsafe_foo(x);
    printf("unsafe result: %d\n",unsafe_res);
    printf("Invoke safe function...\n");
    safe_res=safe_foo(x);
    printf("safe result: %d\n",safe_res);

    if(unsafe_res==safe_res) printf("Successful!\n");
    else printf("Failed!\n");

    return 0;
}
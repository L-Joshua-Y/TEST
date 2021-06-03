/* Weakness1 code */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int unsafe_foo(int x)
{
    int buf[10];
    buf[x] = 0;    //<-error CWE-787
    if (x == 1000) {
        x/=2;
        return x;
    }
    else return x*2;
}

int safe_foo(int x)
{
    int buf[10];
    if(x>=0&&x<10) buf[x]=0;
    if (x == 1000) {
        x/=2;
        return x;
    }
    else return x*2;
}

int main()
{
    printf("Begin to test Weakness1 code...\n");
    int x,unsafe_res,safe_res;
    printf("Please enter x=");
    scanf_s("%d",&x);
    printf("Invoke unsafe function...\n");
    unsafe_res=unsafe_foo(x);
    printf("unsafe result=%d\n",unsafe_res);
    printf("Invoke safe function...\n");
    safe_res=safe_foo(x);
    printf("safe result=%d\n",safe_res);

    if (safe_res == unsafe_res) printf("Successful!\n");
    else printf("Failed!\n");

    return 0;
}
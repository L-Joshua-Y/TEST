/* Weakness5 code */
#include <stdio.h>
#include <limits.h>

int unsafe_foo(int x)
{
    int id=INT_MAX-10;
    id+=11; //<- error CWE-190
    id-=2;

    return id;
}

int safe_foo(int x)
{
    int id=INT_MAX-10;
    id+=9;

    return id;
}

int main()
{
    printf("Begin to test Weakness5 code...\n");
    int x,unsafe_res,safe_res;
    printf("Please enter x=");
    scanf_s("%d",&x);
    printf("Invoke unfase function...\n");
    unsafe_res=unsafe_foo(x);
    printf("unsafe result: %d\n",unsafe_res);
    printf("Invoke safe function...\n");
    safe_res=safe_foo(x);
    printf("safe result: %d\n",safe_res);
    
    if(unsafe_res==safe_res) printf("Successful!\n");
    else printf("Failed!\n");
    
    return 0;
}
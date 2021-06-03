/* Weakness3 code */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int unsafe_foo(int x,int a,int b)
{
    struct struct_foo
    {
        int x;
        int y;
    };

    struct struct_foo *pointer=NULL;
    if(x<1000){
        pointer=(struct struct_foo*)malloc(sizeof(struct struct_foo));
        pointer->x=a;
        pointer->y=b;
    }
    
    int tmp=pointer->x+pointer->y;	//<- error CWE-476

    free(pointer);

    return tmp;
}

int safe_foo(int x,int a,int b)
{
    struct struct_foo
    {
        int x;
        int y;
    };

    struct struct_foo *pointer=NULL;
    if(x<1000){
        pointer=(struct struct_foo*)malloc(sizeof(struct struct_foo));
        pointer->x=a;
        pointer->y=b;
    }
    
    int tmp;
    if(pointer==NULL) tmp=0;
    else{
        tmp=pointer->x+pointer->y;
        free(pointer);
    }

    return tmp;
}

int main()
{
    printf("Begin to test Weakness3 code...\n");
    int x,a,b,unsafe_res,safe_res;
    printf("Please enter x=");
    scanf_s("%d",&x);
    printf("Please enter a,b\n");
    scanf_s("%d%d",&a,&b);
    unsafe_res=unsafe_foo(x,a,b);
    printf("Invoke unsafe function...\nres=%d\n", unsafe_res);
    safe_res =safe_foo(x,a,b);
    printf("Invoke safe function...\nres=%d\n", safe_res);

    if (unsafe_res == safe_res) printf("Successful!\n");
    else printf("Failed!\n");

    return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
    typedef struct{
        char name[10];
        char address[10];
        int age;
    }profile;

    profile sinaya;
    strcpy(sinaya.name ,"sinaya");
    strcpy(sinaya.address,"bbsr");
    sinaya.age= 19;

    printf("%s\n",sinaya.name);
      printf("%s\n",sinaya.address);
        printf("%d\n",sinaya.age);
}
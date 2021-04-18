#include <stdio.h>

struct address{
    char name[25];
    char city[10];
    int pincode;
};
int main()
{
    struct address sinaya = {"Sinaya Naik","BBSR",576567};

    struct address* ptr;
    ptr = &sinaya;

    printf("name: %s\n",ptr->name);
    printf("city: %s\n",ptr->city);
    printf("pincode: %d\n",ptr->pincode);

    int *char_ptr = NULL;

    printf("sizeof(char_ptr) = %ld\n",sizeof(char_ptr));

    printf("sizeof(ptr) = %ld\n",sizeof(ptr));

}
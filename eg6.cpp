#include <stdio.h>
int main(void)
{
int i = 10;
int j = 20;
const int *const ptr = &i; /* constant pointer to constant integer */
printf("ptr: %d\n", *ptr);
return 0;
}

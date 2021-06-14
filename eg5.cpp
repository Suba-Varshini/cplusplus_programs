#include <stdio.h>
int main(void)
{
int i = 10;
int j = 20;
const int *ptr = &i; /* ptr is pointer to constant */
printf("ptr: %d\n", *ptr);
ptr = &j;
printf("ptr: %d\n", *ptr);
return 0;
}

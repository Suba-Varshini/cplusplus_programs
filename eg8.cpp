#include <stdio.h>
int main(void)
{
int const i = 10; /* i is stored in read only area*/
int j = 20;
int const *ptr = &i; /* pointer to integer constant. Here i
is of type "const int", and &i is of
type "const int *". And p is of type
"const int", types are matching no issue */
printf("ptr: %d\n", *ptr);
ptr = &j;
printf("ptr: %d\n", *ptr);
return 0;
}

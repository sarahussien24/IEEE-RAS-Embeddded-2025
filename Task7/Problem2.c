#include <stdio.h>

typedef int           Type_Integer;
typedef char          Type_Character;
typedef float         Type_Float;
typedef double        Type_Double;
typedef short         Type_Short;
typedef long          Type_Long;
typedef unsigned int  Type_UnsignedInteger;
typedef _Bool         Type_Boolean;

int main() {
    printf("Size of Type_Integer : %zu bytes\n", sizeof(Type_Integer));
    printf("Size of Type_Character : %zu bytes\n", sizeof(Type_Character));
    printf("Size of Type_Float  : %zu bytes\n", sizeof(Type_Float));
    printf("Size of Type_Double  : %zu bytes\n", sizeof(Type_Double));
    printf("Size of Type_Short  : %zu bytes\n", sizeof(Type_Short));
    printf("Size of Type_Long  : %zu bytes\n", sizeof(Type_Long));
    printf("Size of Type_UnsignedInteger : %zu bytes\n", sizeof(Type_UnsignedInteger));
    printf("Size of Type_Boolean : %zu bytes\n", sizeof(Type_Boolean));

    return 0;
}

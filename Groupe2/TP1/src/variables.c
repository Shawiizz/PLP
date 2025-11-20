#include <stdio.h>

int main() {
    
    signed char c = -100;
    unsigned char uc = 200;

    signed short s = -12345;
    unsigned short us = 54321;

    signed int i = -100000;
    unsigned int ui = 100000;

    signed long int l = -1000000L;
    unsigned long int ul = 1000000UL;

    signed long long int ll = -1000000000LL;
    unsigned long long int ull = 1000000000ULL;

    float f = 3.14f;
    double d = 2.71828;
    long double ld = 1.6180339887L;
    printf("Affichage des variablesde types base : \n \n");

    printf("i. char : ");
    printf("\n  Signed char : %lu", sizeof(c));
    printf("\n  Unsigned char : %lu", sizeof(uc));
    
    printf("\nii. short : ");
    printf("\n  Signed short : %lu", sizeof(s));
    printf("\n  Unsigned short : %lu", sizeof(us));

    printf("\niii. int : ");
    printf("\n  Signed int : %lu", sizeof(i));
    printf("\n  Unsigned int : %lu", sizeof(ui));

    printf("\niv. long int : ");
    printf("\n  Signed long int : %lu", sizeof(l));
    printf("\n  Unsigned long int : %lu", sizeof(ul));

    printf("\nv. long long int : ");;
    printf("\n  Signed long long int : %lu", sizeof(ll));
    printf("\n  Unsigned long long int : %lu", sizeof(ull));


    printf("\nvi. float : ");
    printf("\n  float : %lu", sizeof(f));
    
    printf("\nvii. double : ");
    printf("\n  double : %lu", sizeof(d));
    
    printf("\nviii. long double : ");
    printf("\n  long double : %lu", sizeof(ld));

    printf("\n");
    return 0;
}

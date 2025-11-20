#include <stdio.h>

int main() {
    printf("Taille des types en octets :\n\n");

    printf("i. char : ");
    printf("\n  char : %lu", sizeof(char));
    printf("\n  Signed char : %lu", sizeof(signed char));
    printf("\n  Unsigned char : %lu", sizeof(unsigned char));
    
    printf("\nii. short : ");
    printf("\n  short : %lu", sizeof(short));
    printf("\n  Signed short : %lu", sizeof(signed short));
    printf("\n  Unsigned short : %lu", sizeof(unsigned short));

    printf("\niii. int : ");
    printf("\n  int : %lu", sizeof(int));
    printf("\n  Signed int : %lu", sizeof(signed int));
    printf("\n  Unsigned int : %lu", sizeof(unsigned int));

    printf("\niv. long int : ");
    printf("\n  long int : %lu", sizeof(long int));
    printf("\n  Signed long int : %lu", sizeof(signed long int));
    printf("\n  Unsigned long int : %lu", sizeof(unsigned long int));

    printf("\nv. long long int : ");
    printf("\n  long long int : %lu", sizeof(long long int));


    printf("\nvi. float : ");
    printf("\n  float : %lu", sizeof(float));
    
    printf("\nvii. double : ");
    printf("\n  double : %lu", sizeof(double));
    
    printf("\nviii. long double : ");
    printf("\n  long double : %lu", sizeof(long double));

    return 0;
}

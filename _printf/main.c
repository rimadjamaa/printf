#include "main.h"
#include <stdio.h>
#include <stddef.h>
int main() {
    int ret;

    ret = _printf("What?");
    printf("\n%d\n", ret);

    ret = _printf("What%s", "The?");
    printf("\n%d\n", ret);

    ret = _printf("What%The");
    printf("\n%d\n", ret);

    ret = _printf("What%s", NULL);
    printf("\n%d\n", ret);

    ret = _printf("What%d");
    printf("\n%d\n", ret);

    ret = _printf("What%%");
    printf("\n%d\n", ret);

    ret = _printf("What%c", 'T');
    printf("\n%d\n", ret);

    ret = _printf("What%s", 'T');
    printf("\n%d\n", ret);

    return 0;
}

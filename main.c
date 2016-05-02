#include<stdlib.h>
#include<stdio.h>
#include "a.h"

extern void printf_();
extern void printf_three();

int main()
{
   printf_("hello\n");
   printf_three();
   exit (EXIT_SUCCESS);
}

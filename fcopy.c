#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{

  FILE *in,*out;
  char buf[128];
  in=fopen("file.in", "r");
  out=fopen("file.out", "w");
  while(fread(buf,sizeof(buf),1,in) != 0)
  fwrite(buf,sizeof(buf),1, out);
  

exit(0);
}
  

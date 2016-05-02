#include <stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
   char  c;
   int  begin,file_size,filesize,buf,file;
   int addr;

   begin=open("file.dat",O_RDONLY);
   filesize = lseek(begin, 0, SEEK_END);    
   lseek(begin, 0, SEEK_SET);       
   file_size=filesize/2;       
       
         
       file=open("file.dat.1",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
       for(addr=0;(buf=read(begin,&c,1))>0;addr=addr+buf)
          {
            write(file,&c,buf);
             if(file_size==addr)
               break;
           }
        
        file=open("file.dat.2",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
         while((buf=read(begin,&c,1))>0)
            {
              write(file,&c,buf);
            }
   exit(0);
}

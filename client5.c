#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  int sockfd;
  int len;
  struct sockaddr_in address;
  int result;
  char ch[] = "hello";
  char IPaddr[60];
  int endfiled;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = 9734;
  len = sizeof(address);

  result = connect(sockfd, (struct sockaddr *)&address, len);

  if(result == -1)
     {perror("oops: client2");
      exit(1);
     } 

   write(sockfd,&ch,sizeof(ch));
   endfiled=read(sockfd,IPaddr,sizeof(IPaddr));
   IPaddr[endfiled]='\0';
   printf("char from server =%s\n",IPaddr);
   read(sockfd,&ch,1);
   printf("char from server = %s\n", ch);
   close(sockfd);
   exit(0);
}

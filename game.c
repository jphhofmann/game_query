#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
  int sockfd;
  char* payload = malloc(250 * sizeof(char));
  int length;

  switch(atoi(argv[2])) {
    case 27000 ... 28000: //CSS
      payload="\xFF\xFF\xFF\xFF\x54Source Engine Query";
      length=25;
      break;
    case 30000 ... 32000: //FiveM
      payload="\xFF\xFF\xFF\xFFgetinfo xxx";
      length=15;
      break;
  }

  struct sockaddr_in servaddr;
  ssize_t count;

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[2]));

  int len,n;
  len=sizeof(servaddr);
  sendto(sockfd, (const char *)payload, strlen(payload)+1, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
  char buffer[2048];
  recvfrom(sockfd, buffer, sizeof buffer,  0, ( struct sockaddr *) &servaddr, &len);
  printf("%s\n",buffer);
}


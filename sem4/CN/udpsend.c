# include<stdio.h>
# include<arpa/inet.h>
# include<sys/socket.h>
# include<stdlib.h>
# include<unistd.h>
# include<string.h>

int main(int argc,char *argv[])
{
  if(argc != 4)
  {
    printf("Usage: %s <peer_ip> <peer_port> <message>\n",argv[0]);
    return EXIT_FAILURE;
  }
  //get some info about our peer from our args
  const char * peer_ip = argv[1];
  int peer_port = atoi(argv[2]);
  const char * message = argv[3];

  /*sockaddr_in = socket address*/ //Address Family internet //htons-> host byte order to network byte order
  struct sockaddr_in peer_addr = {.sin_family = AF_INET, .sin_port = htons(peer_port)};
  //printable to network format:
  if(inet_pton(AF_INET,peer_ip, &(peer_addr.sin_addr))<=0)//printable version to binary version
  {
    perror("Something went wrong with ip address!");
    return EXIT_FAILURE;
  }
  
  //Creating a socket:
  int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp_socket < 0)
  {
    perror("Coundn't create socket");
    return EXIT_FAILURE;
  }

  if(sendto(udp_socket,message, strlen(message)+1,0,(struct sockaddr *)&peer_addr, sizeof(peer_addr))<0)
  {
    perror("Coudn't send message\n");
    close(udp_socket);
    return EXIT_FAILURE;
  }

  printf("SENT!! %s to %s:%d\n",message,peer_ip,peer_port);
  close(udp_socket);

  return EXIT_SUCCESS;
}

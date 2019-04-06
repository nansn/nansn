#include<sys/types.h> 
#include<sys/socket.h> 
#include<unistd.h> 
#include<netinet/in.h> 
#include<arpa/inet.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<errno.h> 
#include<netdb.h> 
#include<stdarg.h> 
#include<string.h> 

#define BUFFER_SIZE 1200 

int main(int argc, char *argv[]) 
{

	int len = 0;
	int ret = 0;
	if (argc < 3) {
		printf("less argument\n");
		return 0;
	}

	len = BUFFER_SIZE;



	struct sockaddr_in server_addr; 
	bzero(&server_addr, sizeof(server_addr)); 
	server_addr.sin_family = AF_INET; 
	server_addr.sin_addr.s_addr = inet_addr(argv[1]); 
	server_addr.sin_port = htons(atoi(argv[2])); 

	struct sockaddr_in clientaddr;
	
	int client_socket_fd = socket(AF_INET, SOCK_DGRAM, 0); 
	if(client_socket_fd < 0) 
	{ 
		perror("Create Socket Failed:"); 
		exit(1); 
	}


	/* set client socket */
	bzero(&clientaddr, sizeof(clientaddr));
	clientaddr.sin_family = AF_INET;
//	clientaddr.sin_port = htons(4100);
	clientaddr.sin_port = htons(0);
	clientaddr.sin_addr.s_addr = INADDR_ANY;

	//if server send to client firt ,bind() is not need
#if 0
	ret = bind(client_socket_fd, (struct sockaddr *)&clientaddr, sizeof(struct sockaddr));
	if (ret < 0)
	{
		printf("bind fail with ret = %d\n", ret);
		close(client_socket_fd);
		return -1;
	}
#endif

	char buffer[BUFFER_SIZE];
	memset(buffer, 'a', BUFFER_SIZE);

	while (1) {
		if(sendto(client_socket_fd, buffer, len,0,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0) 
		{ 
			perror("Send File Name Failed:"); 
			exit(1); 
		} 
	}

	close(client_socket_fd); 
	return 0;

} 


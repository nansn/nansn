#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define BUF_MAX		(1024 * 1024)
char buf_recv[BUF_MAX];

long long recvNum = 0;
int     wdIntvl = 60;

static void rate ()
{
	if (recvNum > 0) {
		printf ("%lld Mbps/sec tot %lld\n", (recvNum / 1000 / 1000) * 8 / wdIntvl, recvNum);
		recvNum = 0;
	} else {
		printf ("No bytes read in the last 60 seconds.\n");
	}
	alarm (60);
}

int main(int argc, char **argv)
{
	int sockfd;
	unsigned short serverPort ;
	int ret = -1;
	int val = 1;
	socklen_t len = 0;
	int n;
	int    blen;

	struct sockaddr_in servaddr, cliaddr;
	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	bzero(&servaddr, sizeof(servaddr));
	bzero(buf_recv, sizeof(buf_recv));

	servaddr.sin_family = AF_INET;
	if (argc < 4) {
		printf("params less, ip and port\n");
	} else {
		servaddr.sin_addr.s_addr = inet_addr(argv[1]);
		serverPort = atoi(argv[2]);
		servaddr.sin_port = htons(serverPort);
	}


	blen = atoi (argv [3]);
	blen = blen * 1024 * 1024;

	ret = bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (ret < 0) {
		perror("bind");
		close(sockfd);
		return -1;
	}

	if (setsockopt (sockfd, SOL_SOCKET, SO_RCVBUF, (char *)&blen, sizeof (blen)) < 0) {
		perror ("setsockopt SO_RCVBUF");
		exit (1);
	}

	
	len = sizeof(cliaddr);

	signal (SIGALRM, rate);
	alarm (60); /* Start signal handler after a minute */

	while (1) {
		n = recvfrom(sockfd, buf_recv, BUF_MAX, 0, (struct sockaddr *)&cliaddr, &len);
		if (n < 0) {
			perror ("recvfrom");
			break;
		}
		recvNum += n;

	}

	return 0;
}


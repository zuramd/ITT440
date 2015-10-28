#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER 128
#define DAYTIME_SERVER_PORT 6667

int main(void)
{
	int serverFd, connectionFd;
	struct sockaddr_in servaddr;
	char timebuffer[MAX_BUFFER+1];
	time_t currenTime;

	serverFd = socket(AF_INET, SOCK_STREAM, 0);

	memset( &servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(DAYTIME_SERVER_PORT);

	bind(serverFd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	listen(serverFd, 5);

	while(1) {
		connectionFd = accept(serverFd, (struct sockaddr *) NULL, NULL);

		if(connectionFd >=0) {

			currenTime = time(NULL);
			snprintf(timebuffer, MAX_BUFFER,  "%s\n", ctime(&currenTime));
			write(connectionFd, timebuffer, strlen(timebuffer));
			close(connectionFd);
}
}
}

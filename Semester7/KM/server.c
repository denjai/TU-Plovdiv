#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int sockfd;
	int newsockfd;
	int portno;
	int clilen;
	char buffer[256];
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
	int n;
	if (argc < 2) {
		printf("ERROR, no port provided\n"); // If the port was not provided in the console arguments
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0); // Creating the socket
	if (sockfd < 0)
	{
		printf("ERROR opening socket"); // If sockfd = -1 ERROR
		exit(1);
	}
	bzero((char *)&serv_addr, sizeof(serv_addr)); // Resetting the address
	portno = atoi(argv[1]); // Port Number from console arguments
	serv_addr.sin_family = AF_INET; // Setting the domain family
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno); // Setting the port number
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) // Binding the socket
	{
		printf("ERROR on binding"); // If unsuccessful binding ERROR
		exit(1);
	}
	listen(sockfd, 5); // Start listening
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0)
	{
		error("ERROR on accept");
		exit(1);
	}
	bzero(buffer, 256); // Resetting the buffer
	n = read(newsockfd, buffer, 255); // Reading the buffer
	if (n < 0)
	{
		printf("ERROR reading from socket");
		exit(1);
	}
	printf("Message Recieved: %s\n", buffer);
	n = write(newsockfd, "I got your message", 18);
	if (n < 0)
	{
		printf("ERROR writing to socket");
		exit(1);
	}
	return 0;
}

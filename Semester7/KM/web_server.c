#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
void error(char *msg) {
	perror(msg);
	exit(1);
}
void file_send(FILE *, int);
int main(int argc, char *argv[]) {
	FILE *fd;
	int sockfd, newsockfd, portno, clilen, i, flag_word = 0, k = 0;
	char buffer[256] = "", fname[255] = "", msg404[] = "Content-type:text/html\n\nFile Not Found";
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	if (argc < 2) {
		fprintf(stderr, "ERROR, no port provided\n");
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0)
		error("ERROR opening socket");
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR on binding");
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	while (strcmp(fname, "quit")) {
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
			error("ERROR on accept");
		bzero(buffer, 256);
		bzero(fname, 256);
		k = 0;
		flag_word = 0;
		n = read(newsockfd, buffer, 255);
		if (n < 0) error("ERROR reading from socket");
		printf("Here is the message: %s\n", buffer);

		for (i = 0; i < strlen(buffer); i++) {
			if (flag_word == 1) {
				if (buffer[i] == ' ') { break; }
				fname[k] = buffer[i];
				k++;
			}
			if (flag_word == 0 && buffer[i] == '/') flag_word = 1;
		}

		fname[k] = '\0';
		printf("Filename: %s\n", fname);
		fd = fopen(fname, "r");
		if (!fd) write(newsockfd, msg404, strlen(msg404));
		else { //send the page
			file_send(fd, newsockfd);
			fclose(fd);
		}
		if (n < 0) error("ERROR writing to socket");
		close(newsockfd);
	}
	return 0;
}

void file_send(FILE *fd, int newsockfd) {
	char line[1024] = "";
	int i;
	char header[] = "Content-type:text/html\n\n";
	char ok200[] = "HTTP/1.0 200 OK\n";
	write(newsockfd, ok200, strlen(ok200));
	write(newsockfd, header, strlen(header));
	while (fgets(line, 1024, fd)) {
		printf("--> %s\n", line);
		write(newsockfd, line, strlen(line));
	}
	printf("File send.\n");
}

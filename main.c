/*
 * Student Name : Jing Kun Ting
 * Student Number : 792 886
 * Login ID : ting2
 * Coded first on : 14 - 04 -2018
 * Acknowledgements : Some of the code for creating the server is
 * from Lab 5 given on the LMS. Also, shoutout to Matthew for 
 * introducing Beej's Guide since Week 2.
 * beej.us/guide/bgnet/html/single/bgnet.html 
 */

#include "headers.h"

/*
 * Main function to set up the server, create sockets, and accept connections.
 * Does multithreading by using forks.
 */
int main(int argc, char *argv[]) {

	int sockfd, newsockfd, portno;
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;
	char buffer[2048];
	int n;

	if (argc < 3){
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}

	/* Create TCP socket */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
		perror("ERROR opening socket");
		exit(1);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));

	// Port number
	portno = atoi(argv[1]);

	/* Create address we're going to listen on (given port number) converted to
	network byte order & any IP address for this machine */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	/* Bind the socket to our specified IP and port number */
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		exit(1);
	}

	/* Listen on socket - means that we are ready to accept connections, and
	incoming connections will be queued. Prepares the socket for the next
	accept call. BACKLOG is the number of connections that will be queued
	by the system until the program can accept them. */
	listen(sockfd, BACKLOG);

	while(1){

        	clilen = sizeof(cli_addr);

        	/* Accept a connection - block until a connection is ready to
        	be accepted. Get back a new file descriptor to communicate on. */
        	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

		if(newsockfd == -1){
			perror("accept");
			continue;
		}
		/* Resource from Beej's Guide beej.us/guide/bgnet/html/single/bgnet.html */
		if(!fork()){
			/* Forks this out to a child process and closes the listener as
			the child does not need it */
			close(sockfd);

			/* Respond to the function, argv[2] is the file path */
			respond(newsockfd, argv[2]);

			/* Close the socket once it is finished and exits at the end. */
			close(newsockfd);
			exit(0);
       		}

		/* Parent closes the socket as he is not dealing with this anymore. */
		close(newsockfd);

	}

	close(sockfd);

	return 0;
}

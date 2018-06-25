/*
 * Student Name : Jing Kun Ting
 * Student Number : 792 886
 * Login ID : ting2
 * Coded first on : 14 - 04 -2018
 *
 */

#include "headers.h"

/*
 * This function main purpose is to read the data from the socket, then
 * parse in the appropriate data that is needed in order for the server to
 * respond by calling upon the response function.
 */
void respond(int newsockfd, char *path_from){

    	char buffer[BYTES], path[BYTES];
    	int n = 0;
    	int file_type = 0;

    	if (newsockfd < 0){
        	perror("ERROR on accept");
        	exit(1);
    	}

    	bzero(buffer,2048);

    	/* Read from new socket */
    	n = read(newsockfd, buffer, 2048);

    	/* If didn't read anything, return an error */
    	if (n < 0) {
        	perror("Error reading from socket\n");
        	exit(1);
    	}

    	int i = 0;
    	char *request = strtok(buffer, " ");
    	char *request_parts[256];

    	/* This is for partioning the request */
    	while(request != NULL){
        	request_parts[i++] = request;
        	request = strtok(NULL, " ");
    	}

    	/* Creating the path by concatenating the initial path and the file name */
    	strcpy(path,path_from);
    	strcat(path,request_parts[1]);

    	/* Find the file type then call the response function */
    	file_type = find_file_type(request_parts[1]);

	/* Parse in HTTP/1.0 as the header as stated by Pasan that we do not need
   	to worry about the HTTP version */
    	response_function(newsockfd, file_type, "HTTP/1.0", path);

}

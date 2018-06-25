/*
 * Student Name : Jing Kun Ting
 * Student Number : 792 886
 * Login ID : ting2
 * Coded first on : 14 - 04 -2018
 *
 */

#include "headers.h"

/*
 * This function serves the purpose to write the appropriate response back
 * into the socket. Takes in newsockfd, file_type which indicates the type of
 * file as described in the header file, which was previously computed in the
 * respond function, http version which is HTTP/1.0 and a path which is then
 * path of the file.
 */
void response_function(int newsockfd, int file_type, char *http_ver, char *path){

	char send_data[BYTES];
	char http_header[256];
	char response_data[BYTES];
	char data_to_send[BYTES];
	int bytes_read;

	FILE *read;
	read = fopen(path, "rb");

 	/* If there is no full, return a 404 Not found error. */
	if(read == NULL){
		write(newsockfd, "HTTP/1.0 404 Not Found", sizeof("HTTP/1.0 404 Not Found"));
	}

	/* Copy the http version into the header. */
	strcpy(http_header,http_ver);

	/* By determining the file type, write back the approrpiate headers.*/
	if(file_type == HTML){
		strcat(http_header," 200 OK\r\nContent-type: text/html\r\n\r\n");
		strcpy(send_data,http_header);
	}
	else if(file_type == CSS){
		strcat(http_header," 200 OK\r\nContent-type: text/css\r\n\r\n");
		strcpy(send_data,http_header);
	}
	else if(file_type == JS){
		strcat(http_header," 200 OK\r\nContent-type: text/javascript\r\n\r\n");
		strcpy(send_data,http_header);

	}
	else if(file_type == JPG){
		strcat(http_header," 200 OK\r\nContent-type: image/jpeg\r\n\r\n");
		strcpy(send_data,http_header);
	}

	write(newsockfd,send_data,strlen(send_data));

	int total_bytes_read = 0;

	/* After finding the size of the file, allocate memory as stated in the
	discussion forum by Lecturer Chris Culnane*/
	char buffer[2048];
	while((total_bytes_read = fread(buffer,1,2048,read)) > 0){
		write(newsockfd,buffer,total_bytes_read);
	}

}

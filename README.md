# COMP30023 Assignment 1
Submitted here is a COMP30023 Assignment done by Jing Kun Ting.
Student Number : 792 886

## Files
* **find_file_type.c** This is a helper function to find the type of file, namely HTML, CSS, JS and JPG.
* **respond.c** Helper function to read the data that is sent by the client, and process the request for response function to use.
* **response_function.c** This is a helper function to determine the appropriate header to write back as well as the message body if applicable.
* **main.c** This is the main function, from setting up the server, to allowing forks to respond to multiple requests.

## Running
There is a Makefile provided.
By typing make, it should provided an executable called *server* as specified in the assignment specifications.

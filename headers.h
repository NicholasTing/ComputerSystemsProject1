/*
 * Student Name : Jing Kun Ting
 * Student Number : 792 886
 * Login ID : ting2
 * Coded first on : 14 - 04 -2018
 * headers.h - Header files
 */

#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define HTML 1
#define CSS 2
#define JS 3
#define JPG 4

#define BYTES 1024
#define BACKLOG 5

void response_function(int newsockfd, int file_type, char *http_ver, char *path);
int find_file_type(char *file_name);
void respond(int newsockfd, char *path_from);

#endif

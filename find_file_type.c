/*
 * Student Name : Jing Kun Ting
 * Student Number : 792 886
 * Login ID : ting2
 * Coded first on : 14 - 04 -2018
 *
 */

#include "headers.h"

/**
 * Finds a file type given the file name.
 */
int find_file_type(char *file_name){

	char *JS_FILE = "js";
	char *CSS_FILE = "css";
	char *JPG_FILE = "jpg";
	char *HTML_FILE = "html";

	char *extension = strtok(file_name, ".");
	extension = strtok(NULL, ".");

	if(!strcmp(extension, HTML_FILE)){
		return HTML;
	}
	else if(!strcmp(extension, CSS_FILE)){
		return CSS;
	}
	else if(!strcmp(extension, JPG_FILE)){
		return JPG;
	}
	else if(!strcmp(extension, JS_FILE)){
		return JS;
	}

	return 0;

}

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>


struct dirent *dirEntry;
int stat_status;
struct stat stat_buf;

int temp_no_of_files;


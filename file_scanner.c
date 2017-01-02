#include"file_scanner.h"

///////////////////////////////////////////////////
//
//     	name: file_scanner()
//	para: 2 (char *, int)
//	returns: int  (execution status )
//	
//	purpose: scan direcory using recurssion
//
///////////////////////////////////////////////////

int file_scanner(char *path, int fd)
{
	DIR *dir;
	char filepath[300];
	strcpy(filepath,path);	
		
	printf("%s ",path);	
	dir=opendir(path);
	if(dir==NULL)
	{

		write(2,path,strlen(path));
		perror("  cant open ");
		return 1;
	}

	while((dirEntry = readdir(dir))!= 0 )
	{	
	strcat(filepath,"/");
		if(dirEntry->d_name[0] == '.')
		{
			strcpy(filepath,path);
			continue;
		}

		strcat(filepath,dirEntry->d_name);
		stat_status=lstat(filepath,&stat_buf);
			if(stat_status < 0)
			{
				
				perror("  lstat fails ");
				perror(filepath);
				return 1;
			}
		if(S_ISDIR(stat_buf.st_mode))
		{
		//	printf("\n %d--%s ",fd,filepath);
 	
			write(fd,"--inside dir ",13);
			write(fd,filepath,strlen(filepath));
			write(fd,"\n",2);

			file_scanner(filepath,fd);
			

		}
		else
		{
			printf("\n %d %s ",fd,filepath);
			write(fd,filepath,strlen(filepath));
			write(fd,"\n",2);
			temp_no_of_files++;
		}
		
		strcpy(filepath,path);
	}

		closedir(dir);
return 0;
}

/////////////////////////////////////////////////////////////////////
/*
int main(int argc, char *argv[])
{
int fd,fd1;
 fd = open("file_scanner.log",O_RDWR|O_CREAT,0666);
if(fd<0)
{
	perror("open fails");
}
close(2);
dup(fd);

fd1=open("temp.txt",O_RDWR|O_CREAT,0666);

printf("\n__ %d",file_scanner(argv[1],fd1));

printf("\nno of file scanned %d \n",temp_no_of_files);
return 0;
}
*//////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int copy(char*, char*);

int main(int argc, char *argv[])
{
	char destfile[20];
	
	if(argc!=2)
	{
		printf("invalid paras \n");
		return 0;
	}
	
	strcpy(destfile,"temp/");
	strcat(destfile,argv[1]);
	//printf("%s",destfile);
	printf("%d ",copy(argv[1],destfile));

	return 0;
}

int copy(char *sourceFileName, char *destFileName)
{
	int fdOld, fdNew,stat_status,charsCopied;
	struct stat statBuf;
	char buffer[256];
	
	fdOld=open(sourceFileName,O_RDONLY);
	if(fdOld<0)
	{
		perror("open :");
		return -1;
	}
	
	stat_status=stat(sourceFileName,&statBuf);
	if(stat_status!=0)
	{
		perror("stat fails : ");
		return -1;
	}
	
	fdNew=open(destFileName,O_RDWR | O_TRUNC | O_CREAT, statBuf.st_mode);
	if(fdNew<0)
	{
		perror("newfp open :");
		return -1;
	}
	
	while((charsCopied=read(fdOld,buffer,sizeof(buffer)))>0)
	{
		write(fdNew,buffer,charsCopied);
	}

return 0;
}

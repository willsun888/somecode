#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 200

int main(){
	size_t n;
	char buff[MAXLINE],command[MAXLINE];
	FILE* fp;
	fgets(buff,MAXLINE,stdin);
	n = strlen(buff);
	if(buff[n-1]=='\n')
		n--;
	snprintf(command,sizeof(command),"cat %s",buff);
	fp = popen(command,"r");

	while(fgets(buff,MAXLINE,fp) != NULL){
		fputs(buff,stdout);
	}
	fclose(fp);
	exit(0);
}

#include<unistd.h>
#include<stdio.h>

int main(){
	int fds[2];
	pid_t pid;
	int i,j;
	char buf[256];
	if(pipe(fds)<0){
		fprintf(stderr,"pipe error\n");
		return;
	}
	if((pid=fork()) < 0){
		fprintf(stderr,"fork error\n");
		return;
	}
	/*child*/
	if(pid == 0){
		close(fds[1]);
		memset(buf,0,sizeof(buf));
		j = read(fds[0],buf,sizeof(buf));
		fprintf(stderr,"[child] buf=[%s] len [%d] \n",buf,j);
		return;
	}
	/*parent*/
	close(fds[0]);
	write(fds[1],"hello!",strlen("hello!"));
	write(fds[1],"world!",strlen("world!"));

	return 0;
}

#include <fcntl.h>
#include <stdio.h>
void main(){
	int fd = creat("new_file.txt" ,0700);
	printf("%d",fd);
}


#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
 	int i, status;
 	for(i=1; i<argc; i++) {
 		if(fork() == 0) {
 			if(execlp(argv[i], argv[i], NULL) == -1) {
 				fprintf(stderr, "Failed to execute program \"%s\": %s\n", argv[i], strerror(errno));
		 		exit(0);
 			}
 		}
 		wait(&status);
 		if(WEXITSTATUS(status) != 0) {
 			fprintf(stderr, "Program \"%s\" failed with exit code %d\n", argv[i], WEXITSTATUS(status));
 		}
 	}
 return 0;
}

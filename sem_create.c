#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/stat.h>

static void usageError(char* progName, char* msg) {
	if(msg != NULL){
		fprintf(stderr, "%s", msg);
	}
	
	fprintf(stderr, "Usage: %s -n sems_number [-cx] {-f pathname | -k key | -p} [octal-perms]\n", progName);
	fprintf(stderr, "-n Define semaphores count in set\n");
	fprintf(stderr, "-c Use IPC_CREAT flag\n");
	fprintf(stderr, "-x Use IPC_EXCL flag\n");
	fprintf(stderr, "-f Use pathname to Generate key using ftok()\n");
	fprintf(stderr, "-k Use key as key\n");
	fprintf(stderr, "-p Use IPC_PRIVATE key\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
	int numKeyFlags; /* Counts -f, -k, and -p options */
	int flags, semid, opt;
	unsigned int perms;
	key_t key;
	long lkey;
	int nsems;
	int isNsemsDefined;
	
	/* Parse command-line options and arguments*/
	numKeyFlags = 0;
	flags = 0;
	isNsemsDefined = 0;
	
	while((opt = getopt(argc, argv, "n:cf:k:px")) != -1){
		switch(opt) {
		case 'c':
			flags |= IPC_CREAT;
			break;
		case 'f':
			key = ftok(optarg, 1);
			
			if(key != -1){
				exit(EXIT_FAILURE);
			}
			
			numKeyFlags++;
			break;
		case 'k':
			if(sscanf(optarg, "%li", &lkey) != 1){
				fprintf(stderr, "Command-line usage error: -k option requires a numeric argument\n");
			}
			
			key = lkey;
			numKeyFlags++;
			break;
		case 'p':
			key = IPC_PRIVATE;
			numKeyFlags++;
			break;
		case 'x':
			flags |= IPC_EXCL;
			break;
		case 'n':
			nsems = atoi(optarg);
			isNsemsDefined = 1;
			break;
		default: 
			usageError(argv[0], "Bad option\n");
		}
	}
	
	if(numKeyFlags != 1) {
		usageError(argv[0], "Exactly one of the options -f, -k, -p must be supplied\n");
	}
	
	if(isNsemsDefined != 1){
		usageError(argv[0], "Exactly should be provided count of semaphores\n");
	}
	
	perms = S_IRUSR | S_IWUSR;
	semid = semget(key, nsems, flags | perms);
	
	if(semid == -1) {
		fprintf(stderr, "semid error\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Semaphore ID = %d\n", semid);
	exit(EXIT_SUCCESS);
}

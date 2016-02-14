#include <fcntl.h>
#include <stdio.h> 	//printf
#include <stdlib.h> 	//malloc, free, exit
#include <sys/types.h> 	// open
#include <sys/stat.h> 	// also open
#include <sys/vfs.h>	// statfs
#include <unistd.h> 	//getpass, close, read, write, stat, lstat, 
			//access, getpagesize


/* Uses the example provided in the gnu library to implement the getopt
 *
 *
 *
 *
 *
 *
 *
 */
int main(int argc, char **argv){



//char *infile = argv[1];
struct stat *instat = malloc(sizeof(stat));

if(argc < 3){
	fprintf(stderr, "cipher [-devh] [-p PASSWD] infile outfile\n Type 'cipher -h' for help.\n");
	exit(1);
}
else{


const char *inpath = "/home/work/CSE_376/HW1/input.txt";
int fd;
// if(stat(inpath, instat) == -1){
// 	printf("Not a valid file\n");
// 	exit(2);
// }

if((fd = open(inpath, O_RDONLY))== -1){
	printf("Not a valid file\n");
	exit(2);
}

printf("Success! Your file descriptor number is: %d\n", fd);

int args;


// while (( args = getopt (argc, argv, "hevdp: ")) != -1)
// 	switch(args){
// 		case 'h': /*Print help message, exit w/ EXIT_FAILURE*/
// 			fprintf(stderr, "Type --help to recieve more help\n");
// 			exit(EXIT_FAILURE);

// 		case 'e':
// 			printf("'e' was printed\n");
// 			break;
// 		case 'v':
// 			printf("'v' was printed\n");
// 			break;
// 		case 'd':
// 			printf("'d' was printed\n");
// 			break;
// 		case 'p':
// 			printf("Arguement is %s\n", optarg);

// 			break;

// 		case '?':
// 		printf("Not an option\n");
// 		break;
		
// 		default:
// 		abort();
// }



printf("Argc count: %d\n", argc);
printf("Optid count: %d\n", optind);
/*Check if a file can be opened*/




}


exit(EXIT_SUCCESS);

}

#include <fcntl.h>
#include <stdio.h> 	//printf
#include <stdlib.h> 	//malloc, free, exit
#include <sys/types.h> 	// open
#include <sys/stat.h> 	// also open
#include <sys/vfs.h>	// statfs
#include <unistd.h> 	//getpass, close, read, write, stat, lstat, 
			//access, getpagesize


#define BUFSIZE 512 // Size of the buffer to read data

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

char buf[BUFSIZE];

//char *infile = argv[1];
struct stat *instat = malloc(sizeof(stat));

if(argc < 3){
	fprintf(stderr, "cipher [-devh] [-p PASSWD] infile outfile\n Type 'cipher -h' for help.\n");
	exit(1);
}
else{





/* use stat later for error checking*/
// if(stat(inpath, instat) == -1){
// 	printf("Not a valid file\n");
// 	exit(2);
// }


/* Check to see if both the input and output files exist/can be opened*/
const char *inpath = "/home/work/CSE376/HW1/input.txt";
int fd_in;
if((fd_in = open(inpath, O_RDONLY))== -1){
	printf("Not a valid file\n");
	exit(2);
}
printf("Success! Input file has been opened");

/*Check if output file exists
 * If no, create it
 *
 * If yes, is it writeable?
 * If not, return error
 */

const char *outpath = "/home/work/CSE376/HW1/output.txt";
int fd_out;
if((fd_out = open(outpath, O_WRONLY | O_CREAT, S_IRWXU))== -1){
	printf("Error! Output file cannot be opened\n");
	exit(2);
}




int readsize = BUFSIZE;

int bytes_cpyd;

while((bytes_cpyd = read(fd_in, buf, readsize)) > 0){
	if(write(fd_out, buf, bytes_cpyd) < 0)
		exit(EXIT_FAILURE);	

}

/* Close the input/output files*/

if(close(fd_in) < 0){
	exit(EXIT_FAILURE);
}

if(close(fd_out) < 0){
	exit(EXIT_FAILURE);
}


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

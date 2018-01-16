#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>  
#include "md5/md5c.h"

#define STR_MD5 		   0
#define FILE_MD5           1

static void usage(void)
{
    fprintf(stderr,
            "./mainpro [option] path or str\n"
            "  -f             md5 encrypt for file.\n"
            "  -s             md5 encrypt for string.\n"
            "  -h             This information.\n"
           );
}

int main(int argc, char *argv[])
{
	unsigned char digest[16];
	char md5[36] = {0};
	int opt, i;
	int soul_opt = -1;
	while ((opt = getopt(argc, argv, "sfh")) != -1) {
		switch (opt) {
			case 's': {
				soul_opt = STR_MD5;
				break;
			}
			case 'f': {
				soul_opt = FILE_MD5;
				break;
			}
			case 'h': {
				usage();
				return 1;
			}
			default:
				break;
		}
	}
	if (-1 == soul_opt || 3 != argc || argc == optind) {
		usage();
		return 1;
	}
	/*string encrypt*/
	if (STR_MD5 == soul_opt) {
		MDString(argv[2], digest);
	}
	/*file encrypt*/
	if (FILE_MD5 == soul_opt) {
		if (0 != MD5File(argv[2], digest)) {
			fprintf(stderr,"can`t open file %s\n", argv[2]);
			return 1;
		}
	}
	/*md5 value hex convert to string*/
	for (i = 0 ; i < 16 ; i ++) {
		snprintf(md5 + 2 * i, 3, "%02x", digest[i]);
	}
	/*output md5 value*/
	fprintf(stdout, "md5: %s\n", md5);
	
}

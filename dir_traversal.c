#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include<fcntl.h> 


#define MAXLEVEL  10

static int display_info(const char *fpath, const struct stat *sb,int tflag, struct FTW *ftwbuf)
{
   	int inode;
   	int fd;
   	fd = open(fpath,O_RDONLY);
   
   	if (fd < 0) {  
       		perror("fd");
   	}
   	struct stat file_stat;  
   	int ret;  
   	ret = fstat (fd, &file_stat);  
   	if (ret < 0) {  
       		perror("ret"); 
   	} 
   	inode = file_stat.st_ino;
   
   	// maximum directories defines to 10
   	if (ftwbuf->level > MAXLEVEL) {
       		return 0; 
   	}
	if(tflag == FTW_SL || tflag == FTW_NS || tflag == FTW_SLN){
		return 0;
	}
   	printf("%s %d %s\n", 
       		(tflag == FTW_D) ?   "d"   : (tflag == FTW_DNR) ? "dnr" :
       		(tflag == FTW_DP) ?  "dp"  : (tflag == FTW_F) ?   "f" :       
       		(tflag == FTW_NS) ?  "ns"  : (tflag == FTW_SL) ?  "sl" :
       		(tflag == FTW_SLN) ? "sln" : "???"
		,inode, fpath  /* + ftwbuf->base */ );
   	return  0;
	
	/*
		d = directory
		dnr = directory which can't be read
		dp = directory, and FTW_DEPTH was specified in flags.
			All of the files and subdirectories within fpath have been processed.
		f = file
		ns = The stat(2) call failed on fpath, which is not a symboliclink.
                	The probable cause for this is that the caller had read permission on the parent directory,
                	so that the filename fpath could be seen,
                	but did not have execute permission,
                	so that the file could not be reached for stat(2).
                	The contents of the buffer pointed to by sb are undefined.
		sl = fpath is a symbolic link, and FTW_PHYS was set in flags.
		sln = fpath is a symbolic link pointing to a nonexistent file.
                	(This occurs only if FTW_PHYS is not set.)
                	In this case the sb argument passed to fn()
                	contains information returned by performing lstat(2) on the "dangling" symbolic link.
	*/      
}

int main(int argc, char *argv[])
{
   	int flags = 0;

//   	if (argc > 2 && strchr(argv[2], 'd') != NULL)
//       	flags |= FTW_DEPTH;
//   	if (argc > 2 && strchr(argv[2], 'p') != NULL)
//       	flags |= FTW_PHYS;

   	//current directory
   	if(argc < 2){
       		if(nftw(".",display_info,0,0) < 0){
           		perror("nftw");
	   		exit(EXIT_FAILURE);
       		}
   	} 
   	else if (nftw(argv[1], display_info, 0, 0) < 0) {
       		perror("nftw");
       		exit(EXIT_FAILURE);
   	}
   	exit(EXIT_SUCCESS);
}

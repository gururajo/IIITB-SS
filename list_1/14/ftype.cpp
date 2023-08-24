/*    The following mask values are defined for the file type:

           S_IFMT     0170000   bit mask for the file type bit field

           S_IFSOCK   0140000   socket
           S_IFLNK    0120000   symbolic link
           S_IFREG    0100000   regular file
           S_IFBLK    0060000   block device
           S_IFDIR    0040000   directory
           S_IFCHR    0020000   character device
           S_IFIFO    0010000   FIFO

       Thus, to test for a regular file (for example), one could write:

           stat(pathname, &sb);
           if ((sb.st_mode & S_IFMT) == S_IFREG) {
           }

       Because tests of the above form are common, additional macros are defined by POSIX to allow the test of the file type in st_mode to be written more concisely:

           S_ISREG(m)  is it a regular file?

           S_ISDIR(m)  directory?

           S_ISCHR(m)  character device?

           S_ISBLK(m)  block device?

           S_ISFIFO(m) FIFO (named pipe)?

           S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)

           S_ISSOCK(m) socket?  (Not in POSIX.1-1996.)

       The preceding code snippet could thus be rewritten as:

           stat(pathname, &sb);
           if (S_ISREG(sb.st_mode)) {
           }

*/#include<iostream>
#include<fcntl.h>
#include <sys/stat.h>
#include<unistd.h>
using namespace std;
int main(int argc, char **argv ){
    int r;
    if(argc != 2){
        cout<<"not correct no of argumts ";
        return 0;
    }
    struct stat f_stat;
        cout<<stat(argv[1], &f_stat)<<endl;
    cout<<S_ISREG(f_stat.st_mode)<<"ggg\n";
    cout<<S_ISDIR(f_stat.st_mode)<<"ggg\n";
    cout<< (f_stat.st_mode & S_IFMT) ;
   return 0;
}


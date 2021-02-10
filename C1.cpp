#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>

struct iovec {
       void *iov_base;    /* pointer to start of buffer */
       size_t iov_len;    /* size of buffer in bytes */

};

ssize_t writev (int fd,const struct iovec *iov,int count);
ssize_t readv (int fd,const struct iovec *iov,int count);

int main (  )
{
        struct iovec iov[3];
        ssize_t nr;
        int fd, i;

        char *buf[] = {
                "I am a Boy.\n",
                "This is a Pen.\n",
                "That is a Cat.\n" };

        fd = open ("buccaneer.txt", O_WRONLY | O_CREAT | O_TRUNC);
        if (fd == −1) {
                perror ("open");
                return 1;
        }

        /* fill out three iovec structures */
        for (i = 0; i < 3; i++) {
                iov[i].iov_base = buf[i];
                iov[i].iov_len = strlen(buf[i]) + 1;
        }
        /* with a single call, write them all out */
        nr = writev (fd, iov, 3);
        if (nr == −1) {
                perror ("writev");
                return 1;
        }
        printf ("wrote %d bytes\n", nr);

        if (close (fd)) {
                perror ("close");
                return 1;
        }

        return 0;
}
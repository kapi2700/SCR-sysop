#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  FILE *plik;
  char str[256];
  int pipefds[2];
  int n,i;
  pipe(pipefds);
  int pid=fork();
  int filedesc,kopia;

  i=0;

  if(pid>0)
    {
      close(pipefds[0]);
      filedesc=open(argv[1],O_RDONLY);
      while((n=read(filedesc,&str,256))>0)
        {
          write(pipefds[1],&str,n);
        }
      sleep(1);
    }
  else if(pid==0)
    {
      close(pipefds[1]);
      close(0);
      dup(pipefds[0]);
      close(pipefds[0]);

      execlp("display","display","-",NULL);
    }
  else
    {
      return 1;
    }
  return 0;
}

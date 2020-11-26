#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  FILE *plik;
  char str[100];
  int pipefds[2];
  int n,i;
  pipe(pipefds);
  int pid=fork();
  i=0;

  if(pid>0)
    {
      close(pipefds[0]);
      plik=fopen(argv[1],"r");
      printf("Plik zostal otwarty\n\n");
      while(fscanf(plik,"%s",str)>0)
        {
          n=0;
          while(str[n]!=0)
            n++;
          write(pipefds[1],&n,1);
          write(pipefds[1],&str,n);
          printf("%s\n",str);
        }
        fclose(plik);
        printf("\nPlik zostal zamniety\n");
        sleep(2);
    }
  else if(pid==0)
    {
      sleep(1);
      close(pipefds[1]);
      while(read(pipefds[0],&i,1))
        {
          read(pipefds[0],&str,i);
          write(STDOUT_FILENO,"#",1);
          write(STDOUT_FILENO,&str,i);
          write(STDOUT_FILENO,"#\n",2);
        }
    }
  else
    {
      return 1;
    }
  return 0;
}

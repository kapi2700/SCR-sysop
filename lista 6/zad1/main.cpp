#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
  int desRd;
  int desRdWr;
  char nazwaPliku[128];
  bool wyjscie=false;
  struct stat filestat;
  void *wsk=NULL;
  int pid;


    while(!wyjscie)
      {
        printf("Podaj nazwe pliku lub wpisz w, aby wyjsc\n");
        scanf("%s", nazwaPliku);
         if(nazwaPliku[0]=='w')
    return 0;

         desRd=open(nazwaPliku,O_RDONLY,0);
		 stat(nazwaPliku,&filestat);
		 desRdWr=open("plik_wsp",O_RDWR);
         truncate("plik_wsp",filestat.st_size);
         wsk=mmap(0,filestat.st_size,PROT_WRITE|PROT_READ,MAP_SHARED,desRdWr,0);
         read(desRd,wsk,filestat.st_size);
         msync(wsk,filestat.st_size,MS_SYNC);
         close(desRd);
         close(desRdWr);
       }

  munmap(wsk,filestat.st_size);
  return 0;
}
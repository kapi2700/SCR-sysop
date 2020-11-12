#include <iostream>
#include <csignal>

using namespace std;

int i=0;

void term(int signum)
{
  cout<< "Zakonczono dzialanie" << endl;
  exit (0);
}

void alrm(int signum)
{
  cout<<"Kontynuacja dzialania" << endl;
}

void usr1(int signum)
{
  i=0;
  signal(SIGUSR1,SIG_IGN);
}

int main()
{
  signal(SIGTERM,term);
  signal(SIGALRM,alrm);
  signal(SIGUSR1,usr1);
  signal(SIGUSR2,SIG_IGN);

  while(1)
    {
      i++;
      if(i==100)
        signal(SIGUSR1,usr1);
    }
  return 0;
}
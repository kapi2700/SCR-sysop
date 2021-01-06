#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *wyswietl_wiadomosc(void *id)
{
  int tid = (int)id;
  printf("Hello SCR. Written by thread %d\n\n",tid);

  pthread_exit(0);
}


int main()
{
  pthread_t thread1, thread2, thread3;


  int tid1=0, tid2=1, tid3=2;

  pthread_create(&thread1, NULL, wyswietl_wiadomosc, (void*) tid1);
  pthread_create(&thread2, NULL, wyswietl_wiadomosc, (void*) tid2);
  pthread_create(&thread3, NULL, wyswietl_wiadomosc, (void*) tid3);

  pthread_exit(0);
}

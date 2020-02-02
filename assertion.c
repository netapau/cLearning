#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <sys/types.h>

void bye(void){
  printf("Bye ! a+");
}

int main(void){

  // On va tester les sorties des process.
  // Il y a aussi on_exit mais pas conforme a C89.
  // on_exit execute les fonctions en ordre inverse !
  if (atexit(bye) == -1) {
    perror("atexit :");
  }

  pid_t pid_fils;
  pid_t* pid_f = &pid_fils;

  do
  {
    pid_fils = fork();
  } while (pid_fils == -1 && (errno == EAGAIN));
  
  assert(pid_fils != -1); // 
  // if ((int)*pid_f != NULL) {
  //   exit(EXIT_FAILURE);
  // }

  if (pid_fils)
  {
    printf("\n Je suis le fils !\n");
  }else {
    printf("\n Je suis le père !\n");
  }
  

  return EXIT_SUCCESS;
}
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>

const char* quisuisje = "Le pere";

int main(void) {
  pid_t pid;
  quisuisje = "Le pere";
  pid = fork(); //pid = 1000
  if (pid == 0)
  {
    quisuisje = "Le fils";
    printf("Je suis %s\n", quisuisje);
  }else
  {
    printf("Je suis %s\n", quisuisje);
    wait(NULL);
  }
  return 0;
}
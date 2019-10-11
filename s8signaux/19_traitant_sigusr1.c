#include "0_libs_de_ses_morts.h"

int usr1blocked = 0;
int mask_applied = 0;

// page 70.1
// page 71.1

void traitantusr(int i){
  char* str = "bien recu\n";
  write(STDOUT_FILENO, str, strlen(str));

  if(!usr1blocked){
    usr1blocked = 1;
  }

}

int main(int argc, char const *argv[]) {

  pid_t pid = getpid();
  printf("%i\n", pid);

  int sigint = SIGUSR1;
  struct sigaction sa;
  memset(&sa, '\0', sizeof(sa));

  sa.sa_handler = &traitantusr;
  // int sigint = SIGUSR1;

  sigaction(SIGUSR1, &sa, NULL);

  // raise(10);


  // pause();
  while(1){
    if(usr1blocked & !mask_applied){
      sigset_t set;
      sigemptyset(&set);
      sigaddset(&set, SIGUSR1);
      sigprocmask(SIG_SETMASK, &set, NULL);
      mask_applied = 1;
    }
  }

  return 0;
}

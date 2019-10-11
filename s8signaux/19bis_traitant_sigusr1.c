#include "0_libs_de_ses_morts.h"

// page 71.1

void traitantusr(int i){
  char* str = "bien recu\n";
  write(STDOUT_FILENO, str, strlen(str));
}

int main(int argc, char const *argv[]) {

  pid_t pid = atoi(argv[1]);

  kill(pid, SIGUSR1);

  return 0;
}

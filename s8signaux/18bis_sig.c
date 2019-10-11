#include "0_libs_de_ses_morts.h"

// page 67.2

int main(int argc, char const *argv[]) {

  pid_t pid = atoi(argv[1]);

  kill(pid, SIGKILL);

  return 0;
}

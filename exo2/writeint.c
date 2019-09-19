# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

int main(int argc, char const *argv[]) {

  int index = open( "fichierpourentier", O_RDONLY | O_CREAT, S_IRWXU);
  int entier = argc(1);
  ssize_t write(index, entier,sizeof(entier));

  int filevalue = ssize_t read(index, entier,sizeof(entier));

  return 0;
}

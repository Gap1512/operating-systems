#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>






int main() {
int rc1, rc2, pipefd[2];
char buffer[2];

if(pipe(pipefd) == -1) {
  fprintf(stderr, "pipe failed\n");
  exit(1);
 }

rc1 = fork();

if (rc1 < 0) {
  fprintf(stderr, "fork 1 failed\n");
  exit(1);
 } else if (rc1 == 0) {
  close(pipefd[0]);
  write(pipefd[1], "42", 2);
 } else {
  wait(NULL);

  rc2 = fork();

  if (rc2 < 0) {
    fprintf(stderr, "fork 2 failed\n");
    exit(1);
  } else if (rc2 == 0) {
    close(pipefd[1]);
    read(pipefd[0], buffer, 2);
    close(pipefd[0]);
    printf("Hey %d, what is the answer to life the universe and everything?\n%s", (int) getpid(), buffer);    
  } else {
    wait(NULL);
  }
 }
return 0;
}

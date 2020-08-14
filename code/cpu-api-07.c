#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>






int main() {
int rc = fork();

if (rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
  close(STDOUT_FILENO);
  open();
  printf("Wow, how this even worked?");
 } else {
  int pid = wait(NULL);
  printf("Wait: %d\n", pid);
 }
return 0;
}

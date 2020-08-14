#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>






int main() {
int rc = fork();
int fpid = -1;

if (rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
  fpid = wait(NULL);
  printf("This first. By the way, wait (in child) returned this: %d\n", fpid);
 } else {
  //fpid = wait(NULL);
  printf("Then this. In parent, wait returned this: %d\n", fpid);
 }
return 0;
}

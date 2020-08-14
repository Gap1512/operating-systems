#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>






int main() {
int rc = fork();

if (rc < 0) {
  fprintf(stderr, "fork failed\n");
  exit(1);
 } else if (rc == 0) {
  //execl("/bin/ls", "ls", NULL);
  //execle("/bin/ls", "ls", NULL, NULL);
  //execlp("/bin/ls", "ls", NULL);

  char *args[] = {"ls", NULL};
  //execv("/bin/ls", args);
  //execvp("/bin/ls", args);
  execvpe("/bin/ls", args, NULL);
 } else {
  wait(NULL);
 }
return 0;
}

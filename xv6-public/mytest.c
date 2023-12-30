#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{
    int i, volume = 2, inputPid = -1, isFork = 0, childPid, setResult;
    if (argc == 2) {
        volume = atoi(argv[1]);
      //   printf(1, "2 ARGVS!\n");
    } else if (argc == 3) {
        volume = atoi(argv[1]);
        inputPid = atoi(argv[2]);
      //   printf(1, "3 ARGVS!\n");
    } else {
      //   printf(1, "NO ARGVS!\n");
    }

    for (i = 1; i <= volume; i++) {
        printf(1, "<---- %d ---->\n", i);
        isFork = fork();
        if(isFork < 0) {
            // printf(1, "fail to fork() in %dth\n", i);
            exit();
        } else if (isFork == 0) {
            childPid = getpid();
            // nice = getnice(childPid);
            // printf(1, "%d child's nice value: %d\n", childPid, nice);
            // ps(childPid);
            setResult = setnice(childPid, 5);
            if (setResult == -1) {
               //  printf(1, "setnice() is failed\n");
            } else {
               //  printf(1, "setnice() is succeed\n");
            }
            // ps(childPid);
            exit();
        } else {
            wait();
        }

        if (inputPid >= 0) {
            // ps(inputPid);
        }
    }

    printf(1, "============= ps(0) =============\n");
    isFork = fork();
    if (isFork < 0) exit();
    else if (isFork == 0) {
      printf(1, "fork() is succeed!\n");
      childPid = getpid();
      setResult = setnice(childPid, 5);
      if (setResult == -1) {
            printf(1, "setnice() is failed\n");
      } else {
            printf(1, "setnice() is succeed\n");
      }
    }
    else exit();

    ps(0);
    exit();
}

// int main(void) {
//    int isFork = 0;
//    isFork = fork();
//    if (isFork < 0) {
//         exit();
//    } else if (isFork == 0) {
//       printf(1, "fork() is succeed!\n");
//    } else {
//       exit();
//    }
   
//    ps(0);
//    exit();
// }
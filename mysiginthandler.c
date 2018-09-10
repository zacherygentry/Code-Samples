#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void handle_signal(int sig)
{
    if (sig == 2)
    {
        int count = 0;
        do
        {
            printf("Count is %d\n", count);
            count += 1;
        } while (count < 100);
    }

    else if (sig == 3){
        int count = 100;
        do
        {
            printf("Count is %d\n", count);
            count -= 1;
        } while (count > 0);
    }
}

int main(int argc, char *argv[])
{
    struct sigaction act;

    memset(&act, '\0', sizeof(act));

    act.sa_handler = &handle_signal;

    if (sigaction(SIGINT, &act, NULL) < 0 || sigaction(SIGQUIT, &act, NULL) < 0)
    {
        perror("sigaction: ");
        return 1;
    }

    while (1)
    {
        sleep(1);
    }

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <stdlib.h>

int main(int argc,char* argv)
{
    int rcvid;
    int chid;
    char message[30];
    printf("Prog server \n");
    printf("Server start working/n");
    chid = ChannelCreate(0);
    printf("Chanel id : %d \n", chid);
    printf("Pid: %d \n", getpid());

    while (1)
    {
        rcvid = MsgReceive(chid, message, sizeof(message), NULL);
        printf("Polychili soobshenie, rcid %X \n", rcvid);
        printf("Soobshenie takoe : \"%s\".\n", message);
        if (!strcmp(message, "Kalmykov Vladimir I993"))
            sprintf(message,"Soobwenie soderjit FIO");
        else
            sprintf(message,"Owibka! Neponyatnie dannie!");
        MsgReply(rcvid, EOK, message, sizeof(message));
        printf("\"%s\". \n", message);
    }
    sleep(5);
    return (1);
}

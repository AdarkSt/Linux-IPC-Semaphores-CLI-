#ifndef SEM_H
#define SEM_H /* Prevent accidental double inclusion */
#include <sys/sem.h>

union semun { /* Used in calls to semctl() */
    int val;
    struct semid_ds * buf;
    unsigned short * array;
#if defined(__linux__)
    struct seminfo * __buf;
#endif
};

int getInt(const char* arg);

#endif

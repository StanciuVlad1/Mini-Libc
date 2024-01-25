#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    /*
    Pentru functia nanosleep, am apelat syscall-ul potrivit, iar apoi am tratat
    cazul de eroare in care modificam valoarea variabilei errno si returnam
    -1.In caz afirmativ returnam rezultatul syscall-ului.
    */
    int ret = syscall(__NR_nanosleep, req, rem);

    if (ret < 0)
    {
        errno = -ret;
        return -1;
    }

    return ret;
}
unsigned int sleep(unsigned int seconds)
{
    /*
    Pentru functia sleep, am declarat variabila "req" de tip structura timespec
    si apoi am i-am setat valorile corecte pentru a apela functia nanosleep.
    */
    struct timespec req;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    nanosleep(&req, NULL);
    return 1;
}

// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/*
	Pentru functia fstat, am apelat syscall-ul potrivit, iar apoi am tratat
	cazul de eroare in care modificam valoarea variabilei errno si returnam
	-1.In caz afirmativ returnam rezultatul syscall-ului.
	*/
	int ret = syscall(__NR_fstat, fd, st);

	if (ret < 0)
	{
		errno = -ret;
		return -1;
	}

	return ret;
}

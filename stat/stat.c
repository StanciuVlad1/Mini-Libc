// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/*
	Pentru functia stat, am apelat syscall-ul potrivit, iar apoi am tratat
	cazul de eroare in care modificam valoarea variabilei errno si returnam
	-1.In caz afirmativ returnam rezultatul syscall-ului.
	*/
	int ret = syscall(__NR_stat, path, buf);

	if (ret < 0)
	{
		errno = -ret;
		return -1;
	}

	return ret;
}

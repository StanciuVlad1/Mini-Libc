// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/*
	Pentru functia mmap, am apelat syscall-ul potrivit, iar apoi am tratat
	cazul de eroare in care modificam valoarea variabilei errno si returnam
	"MAP_FAILED".In caz afirmativ returnam rezultatul syscall-ului de tip
	(void *).
	*/
	long int result = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (result < 0)
	{
		errno = -result;
		return MAP_FAILED;
	}
	return (void *)result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/*
	Pentru functia mremap, am apelat syscall-ul potrivit, iar apoi am tratat
	cazul de eroare in care modificam valoarea variabilei errno si returnam
	"MAP_FAILED".In caz afirmativ returnam rezultatul syscall-ului de tip
	(void *).
	*/
	long int result = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (result < 0)
	{
		errno = -result;
		return MAP_FAILED;
	}
	return (void *)result;
}

int munmap(void *addr, size_t length)
{
	/*Pentru functia munmap, am apelat syscall-ul potrivit, iar apoi am tratat
	cazul de eroare in care modificam valoarea variabilei errno si returnam
	-1.In caz afirmativ returnam 0.
	*/
	long int result = syscall(__NR_munmap, addr, length);
	if (result < 0)
	{
		errno = -result;
		return -1;
	}
	return 0;
}

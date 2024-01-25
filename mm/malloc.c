// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/*
	Pentru functia malloc, prima oara apelam mmap pentru maparea memoriei,
	dupa care adaugam in lista rezultatul cu "size-ul" dorit, in caz favorabil.
	In caz nefavorabil returnam NULL.
	*/
	void *result = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	int x = mem_list_add(result, size);
	if (x == 0)
		return result;
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/*
	Pentru functia calloc, aplicam acelasi principiu ca la malloc, cu
	precizarea ca valorile din memoria alocata sunt 0.
	*/
	void *result = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (result == MAP_FAILED)
		return NULL;
	char *res = (char *)result;
	for (size_t i = 0; i < strlen(res); i++)
		res[i] = 0;
	int x = mem_list_add(result, size * nmemb);
	if (x == 0)
		return result;
	return NULL;
}

void free(void *ptr)
{
	/*
	Pentru functia free, cautam in lista pointerul de start al memoriei pe care
	vrem sa o dezalocam.Daca gasim pointerul, folosim munamp pentru dezalocare,
	iar in final stergem pointerul din lista.
	*/

	struct mem_list *item = mem_list_find(ptr);

	if (item != NULL)
	{
		munmap(ptr, item->len);
		mem_list_del(ptr);
	}
}

void *realloc(void *ptr, size_t size)
{
	/*
	Pentru functia realloc, alocam memorie de dimensiunea precizata ca
	parametru, dupa care cautam pointerul de inceput al memoriei pe care vrem
	sa o realocam.Copiem blocul de memorie folosind memcpy in noua locatie de
	dimensiune prestabilita, urmand ca in final sa dam free la vechea locatie
	a memoriei.
	*/
	void *new_ptr = malloc(size);
	struct mem_list *item = mem_list_find(ptr);
	if (item == NULL)
		return NULL;
	memcpy(new_ptr, ptr, item->len);
	free(ptr);
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/*
	Aplicam acelasi principiu ca la functia realloc.
	 */
	void *new_ptr = malloc(nmemb * size);
	struct mem_list *item = mem_list_find(ptr);
	if (item == NULL)
		return NULL;
	memcpy(new_ptr, ptr, item->len);
	free(ptr);
	return new_ptr;
}

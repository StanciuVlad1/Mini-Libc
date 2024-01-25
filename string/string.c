// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/*
	Pentru functia strcpy am facut un for care itereaza prin sursa si copiaza
	caracter cu caracter in destinatie, la final adaugand terminatorul specific
	*/
	size_t i;
	for (i = 0; i < strlen(source); i++)
		destination[i] = source[i];
	destination[strlen(source)] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/*
	Pentru functia strncpy am facut un for care itereaza prin sursa si copiaza
	caracter cu caracter in destinatie, primele "len" caractere, la final
	adaugand terminatorul specific
	*/
	size_t i;
	for (i = 0; i < len; i++)
		destination[i] = source[i];
	destination[strlen(source)] = '\0';
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/*
	Pentru functia strcat, am iterat cu un for prin sursa si am adaugat fiecare
	caracter la sfarsitul destinatiei, incluzand terminatorul de final.
	*/
	size_t i;
	int len = strlen(destination);
	for (i = 0; i <= strlen(source); i++)
		destination[len + i] = source[i];
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/*
	Pentru functia strncat, am iterat cu un for prin sursa si am adaugat
	primele "len" caractere la sfarsitul destinatiei, la final adaugand
	terminatorul de final.
	*/
	size_t i;
	int len_dest = strlen(destination);
	for (i = 0; i < len; i++)
		destination[len_dest + i] = source[i];
	destination[len_dest + len] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/*
	Pentru functia strcmp am verificat care dintre siruri este mai scurt.Am
	iterat prin el si am verificat fiecare caracter.Daca toate caracterele erau
	identice, verificam care dintre ele este mai scurt.Daca sirurile au si
	aceeasi dimensiune, atunci ele sunt egale si returnam 0.
	*/
	int len = (strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2));
	int i;
	for (i = 0; i < len; i++)
	{
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
	}
	if (strlen(str1) < strlen(str2))
		return -1;
	if (strlen(str1) > strlen(str2))
		return 1;

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/*
	Pentru functia strncmp, am iterat pana la "len" prin cele doua siruri si am
	verificat caracter cu caracter.Daca toate caracterele erau identice
	returnam 0.
	*/
	size_t i;
	for (i = 0; i < len; i++)
	{
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/*
	Pentru functia strchr, am iterat prin "str" caracter cu caracter si am
	verificat daca unul din ele este cel cautat.In caz afirmativ returnam un
	un pointer la prima pozitie a caracterului cautat.
	*/
	size_t i;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
		{
			char *poz = (char *)(str + i);
			return poz;
		}
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/*
	Pentru functia strrchr, am iterat prin "str" caracter cu caracter de la
	final si am verificat daca unul din ele este cel cautat.In caz afirmativ
	returnam un un pointer la ultima pozitie a caracterului cautat.
	 */
	int i;
	int len = (int)strlen(str);
	for (i = len; i >= 0; i--)
	{
		if (str[i] == c)
		{
			char *result = (char *)(str + i);
			return result;
		}
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/*
	Pentru functia strstr, am parcurs fiecare caracter din "haystack" si l-am
	considerat un inceput pentru "needle".Daca toate caracterele consecutive se
	potriveau, inseamna ca "needle" se afla in "haystack" si returnam un
	pointer la aparitia primei litere din "needle" in "haystack".
	*/
	size_t i, j;
	for (i = 0; i < strlen(haystack); i++)
	{
		for (j = 0; j < strlen(needle); j++)
		{
			if (haystack[j + i] != needle[j])
				break;
		}
		if (j == strlen(needle))
		{
			char *poz_final = (char *)(haystack + i);
			return poz_final;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/*
	Pentru functia strrstr, am parcurs fiecare caracter din "haystack" si l-am
	considerat un inceput pentru "needle".Daca toate caracterele consecutive se
	potriveau, inseamna ca "needle" se afla in "haystack" si salvam aparitia
	primei litere intr-o variabila "last".La final returnam un pointer la
	ultima aparitie a primei litere din "needle".
	*/
	int i, j;
	int last = -1;
	int lenH = (int)strlen(haystack);
	int lenN = (int)strlen(needle);
	for (i = 0; i < lenH; i++)
	{
		for (j = 0; j < lenN; j++)
		{
			if (haystack[j + i] != needle[j])
				break;
		}
		if (j == lenN)
			last = i;
	}
	if (last != -1)
	{
		char *result = (char *)(haystack + last);
		return result;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/*
	Pentru functia memcpy am castat cei doi pointeri la (char *), iar apoi am
	iterat prin sursa si am copiat tot in destinatie.
	*/
	char *dest = (char *)destination;
	char *src = (char *)source;
	size_t i;
	for (i = 0; i < num; i++)
		dest[i] = src[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/*
	Pentru functia memove am facut acelasi cast ca la memcpy si am verificat
	daca memcpy poate fi efectuat in siguranta.In cazul in care cele doua zone
	de memorie s-ar fi suprapus, am modificat locatia pointerului "dest",
	astfel incat la apelul functiei memcpy, zonele de memorie sa nu se
	suprapuna.
	*/
	char *dest = (char *)destination;
	char *src = (char *)source;
	long int len = (long int)num;
	if (dest - src >= len)
	{
		memcpy(destination, source, num);
		return destination;
	}

	dest = dest + (num - (dest - src));
	memcpy(destination, source, num);
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/*
	Pentru functia memcmp, am facut cast celor doi void pointeri la (char *),
	iar apoi am aplicat acelasi principiu ca la strcmp.
	*/
	size_t i;
	const char *first = (char *)ptr1;
	const char *second = (char *)ptr2;

	for (i = 0; i < num; i++)
	{
		if (first[i] < second[i])
			return -1;
		if (first[i] > second[i])
			return 1;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/*
	Pentru functia memset am facut cast, dupa care am iterat prin sursa setand
	de fiecare data valoarea "value".
	*/
	char *src = (char *)source;
	size_t i;
	for (i = 0; i < num; i++)
		src[i] = value;
	return source;
}

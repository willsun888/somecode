#include <stdio.h>
#include <sds.h>

unsigned int getFree(sds s) 
{
	struct sdshdr *sh = (struct sdshdr *) (s-(sizeof(struct sdshdr)));
    return sh->free;
}

// struct sdshdr *sh = (void*) (s-(sizeof(struct sdshdr)));
//     int reallen = strlen(s);
//     sh->free += (sh->len-reallen);
//     sh->len = reallen;

int main(int argc, char const *argv[])
{
	sds str = sdsnewlen("aaaaa", 8);
	size_t len = sdslen(str);
	printf("len:%zu\n", len);
	printf("str:%s\n", str);
	printf("free:%u\n", getFree(str));

	str[2] = '\0';
	sdsupdatelen(str);
	printf("len:%zu\n", len);
	printf("str:%s\n", str);
	printf("free:%u\n", getFree(str));
	return 0;
}


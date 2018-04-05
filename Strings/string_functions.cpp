#include <stdio.h>
#include <stdlib.h>

void str_cpy(char *dest,char *src){
	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

int str_len(char *src){
	int len = 0;
	while(*src != '\0'){
		src++;
		len++;
	}
	return len;
}
void str_cat(char *dest,char *src){
	int index = str_len(dest);
	dest = (dest+index);
	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
int main(void) {
	char *t = (char *)malloc(11*sizeof(char));
	char *tv = "abcbdbab";
	str_cpy(t,tv);
	printf("%s\n",t);
	printf("%d\n",strlen(t));
	str_cat(t,"sg");
	printf("%s\n",t);
	printf("%d\n",strlen(t));
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHARS_NAME 64
#define CHARS_PNUMBER 24

typedef struct {
    char name[CHARS_NAME];
    char phone_n[CHARS_PNUMBER];
    const char *filename;
} DATA;

void draw(void){
	for(int i = 0; i < 40; ++i){
		printf("-");
	}
	printf("\n");
}

char* find(const char* filename, const char* name) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror(filename);
        return NULL;
    }

    char line[CHARS_NAME + CHARS_PNUMBER + 2];
    char *result = NULL;
    
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            result = malloc(strlen(line) + 1);
            if (result) {
                strcpy(result, line);
                result[strcspn(result, "\n")] = '\0'; 
            }
            break;
        }
    }
    
    fclose(file);
    return result;
}

int outf(const char *__FileName, const char *nickname, const char *phone_n) {
    FILE *write = fopen(__FileName, "a");
    if (write == NULL) {
        perror(__FileName);
        return 1;
    }
    fprintf(write, "%s %s\n", nickname, phone_n);
    fclose(write);
    return 0;
}

int strgetf(const char *__FileName) {
    FILE *read = fopen(__FileName, "r");
    if (read == NULL) {
        perror(__FileName);
        return 1;
    }
    		draw();
    int c;
    while ((c = fgetc(read)) != EOF) {
        putchar(c);
    }
    		draw();
    fclose(read);
    return 0;
}

int cinput(void){
	int num;
	if(scanf("%d", &num) != 1){
		while (getchar() != '\n');
		return -1;
	}
	while (getchar() != '\n');
	return num;
}
void shell(int type_res, const char* nameFile){
	DATA obj;
	obj.filename = nameFile;
	switch(type_res){
		case 1:
			printf("Input name contact >> ");
			fgets(obj.name, CHARS_NAME, stdin);
			obj.name[strcspn(obj.name, "\n")] = '\0';
			
			printf("input phone number >> ");
			fgets(obj.phone_n, CHARS_PNUMBER, stdin);
			obj.phone_n[strcspn(obj.phone_n, "\n")] = '\0';

			outf(obj.filename, obj.name, obj.phone_n);
			break;
		case 2:
			strgetf(obj.filename);
			break;
		case 3:
			printf("Input name >> ");
		    char mes[CHARS_NAME];
		    fgets(mes, CHARS_NAME, stdin);
		    mes[strcspn(mes, "\n")] = '\0';
		    
		    //temporary buffer
		    char *found = find(obj.filename, mes);
		    if (found) {
		        printf("%s\n", found);
		        free(found);
		    } else {
		        printf("Contact not found\n");
		    }
		    break;
		case 0:
			exit(0);
			break;
		default:
			break;
	}
}

int main(void) {

    DATA data;
    data.filename = "contact.txt";
    printf("Select action:\n1 - Addition contact\n2 - Show all\n3 - Find by name\n0 - Exit\n");
	while(1){
		printf(">> ");
		shell(cinput(), data.filename);
	}
    return 0;
}
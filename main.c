#include <stdio.h>
#include <assert.h>
#include <string.h>

int main() {
    char buffer[0x1000];
    long physical, logical;
    FILE* fp;

    physical = 0;
    logical = 0;

    snprintf(buffer, sizeof(buffer), 
             "<!DOCTYPE html>\n"
             "<html lang=\"pt-BR\">\n"
             "\t<head>\n"
             "\t\t<meta charset=\"UTF-8\">\n"
             "\t\t<title>contador de processadores</title>\n"
             "\t</head>\n"
             "\t<body>\n"
             "\t\t<p>processadores físicos: %lu</p>\n"
             "\t\t<p>processadores lógicos: %lu</p>\n"
             "\t</body>\n"
             "</html>", 
             physical,
             logical);


    fp = fopen("index.html", "w");
    assert(fp);

    fwrite(buffer, strlen(buffer), 1, fp);
    fclose(fp);


    return 0;
}

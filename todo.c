#include "stdio.h"
#include "stdlib.h"

void printTodos() {

}

void addTodo() {

}

void removeTodo() {

}

int main(void) {
    FILE * file;
    char ** todos;
    char buf;
    size_t count = 0;

    file = fopen("tasks.txt", "r");
    while ((buf = getc(file)) != EOF) {
        if (buf == '\n') {
            count++;
        }
    }
    fclose(file);

    todos = malloc((count+1) * sizeof* todos);
    int i = 0;
    while (i < count) {
        todos[i] = malloc(count * sizeof* todos[i]);
        i++;
    }

    count = 0;
    int select = 0;
    file = fopen("tasks.txt", "r");
    while ((buf = getc(file)) != EOF) {
        if (buf == '\n') {
            todos[count][select] = '\0';
            count++;
            select = 0;
        } else {
            todos[count][select] = buf;
            select++;
        }
    }
    fclose(file);

    i = 0;
    while (i < count) {
        printf("%s\n", todos[i]);
        i++;
    }   

    i = 0; 
    while (i < count) { 
        free(todos[i]); 
        i++;
    } 
    free(todos);

    return 0;
}
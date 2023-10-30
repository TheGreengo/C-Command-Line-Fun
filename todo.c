#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Save todos to text file
void writeOutTodos(char ** todos, int count) {
    FILE * file;
    file = fopen("tasks.txt", "w");
    int i = 0;
    while (i < count) {
        fprintf(file, "%s", todos[i]);
        i++;
    }
    fclose(file);
}

// Outputs todos to terminal
void printTodos(char ** todos, int count) {
    printf("\n");
    int i = 0;
    while (i < count) {
        printf("%d: %s", i+1, todos[i]);
        i++;
    }
    printf("\n");
}

// Add a new todo to the todolist
void addTodo(char *** todos, char * todo, size_t * count) {
    (* count)++;
    int i = 0;
    char ** temp;
    temp = malloc((*count) * sizeof* temp);
    while (i < (* count)) {
        temp[i] = malloc(200 * sizeof* temp[i]);
        if (i < (* count) - 1 ) {
            strcpy(temp[i],(* todos)[i]);
        } else {
            strcpy(temp[i], todo);
        }
        i++;
    }

    i = 0;
    while (i < (* count) - 1) {
        free((* todos)[i]);
        i++;
    }
    free((* todos));

    (*todos) = temp;

    temp = NULL;
}

void removeTodo(char *** todos, size_t num, size_t * count) {
    size_t i = 0;
    char ** temp;
    temp = malloc(((*count)- 1) * sizeof* temp);

    int offset = 0;
    while (i < (* count)) {
        if (i != (num - 1) ) {
            temp[i + offset] = malloc(200 * sizeof* temp[i + offset]);
            strcpy(temp[i + offset],(* todos)[i]);
        } else {
            offset = -1;
        }
        i++;
    }

    i = 0;
    while (i < (* count) - 1) {
        free((* todos)[i]);
        i++;
    }
    free((* todos));

    (*todos) = temp;

    temp = NULL;
    (* count)--;
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
            todos[count][select] = buf;
            todos[count][select + 1] = '\0';
            count++;
            select = 0;
        } else {
            todos[count][select] = buf;
            select++;
        }
    }
    fclose(file);

    
    char * buffer;
    size_t res;
    size_t thing = 100;

    while (1) {
        printTodos(todos, count);
        res = getline(&buffer, &thing, stdin);
        
        if (buffer[0] == 'a') { addTodo(&todos, &buffer[2], &count); }
        if (buffer[0] == 'd') { removeTodo(&todos, (((size_t) buffer[2]) - ((size_t) '0')), & count); }
        if (buffer[0] == 'q') { break; }
    }

    writeOutTodos(todos, count);

    i = 0; 
    while (i < count) { 
        free(todos[i]); 
        i++;
    } 
    free(todos);

    return 0;
}
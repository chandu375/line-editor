#include <stdio.h>
#include <string.h>

void displayLines(char lines[100][200], int count) {
    printf("\nDocument:\n");

    if (count == 0) {
        printf("Document is empty.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, lines[i]);
    }
}

void insertLine(char lines[100][200], int *count, int position) {
    char text[200];

    if (position < 1 || position > *count + 1) {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, 200, stdin);

    for (int i = *count; i >= position; i--) {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);
    (*count)++;

    printf("Line inserted successfully.\n");
}

void deleteLine(char lines[100][200], int *count, int position) {
    if (position < 1 || position > *count) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position - 1; i < *count - 1; i++) {
        strcpy(lines[i], lines[i + 1]);
    }

    (*count)--;

    printf("Line deleted successfully.\n");
}

void replaceLine(char lines[100][200], int count, int position) {
    char text[200];

    if (position < 1 || position > count) {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter new text: ");
    fgets(text, 200, stdin);

    strcpy(lines[position - 1], text);

    printf("Line replaced successfully.\n");
}

void saveFile(char lines[100][200], int count) {
    FILE *file = fopen("document.txt", "w");

    if (file == NULL) {
        printf("Unable to save file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fputs(lines[i], file);
    }

    fclose(file);

    printf("Document saved successfully.\n");
}

void loadFile(char lines[100][200], int *count) {
    FILE *file = fopen("document.txt", "r");

    if (file == NULL) {
        printf("No saved file found.\n");
        return;
    }

    *count = 0;

    while (*count < 100 && fgets(lines[*count], 200, file) != NULL) {
        (*count)++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
}

void showHelp() {
    printf("\nCommands:\n");
    printf("insert   - Insert a new line\n");
    printf("delete   - Delete a line\n");
    printf("replace  - Replace a line\n");
    printf("display  - Display the document\n");
    printf("save     - Save document\n");
    printf("load     - Load document\n");
    printf("help     - Show commands\n");
    printf("exit     - Exit editor\n");
}

int main() {
    char lines[100][200];
    char command[20];
    int count = 0;
    int position;

    printf("===== LINE EDITOR =====\n");

    showHelp();

    while (1) {
        printf("\nEnter command: ");
        scanf("%19s", command);
        getchar();

        if (strcmp(command, "insert") == 0) {
            printf("Enter position: ");
            scanf("%d", &position);
            getchar();

            insertLine(lines, &count, position);
        }
        else if (strcmp(command, "delete") == 0) {
            printf("Enter position: ");
            scanf("%d", &position);
            getchar();

            deleteLine(lines, &count, position);
        }
        else if (strcmp(command, "replace") == 0) {
            printf("Enter position: ");
            scanf("%d", &position);
            getchar();

            replaceLine(lines, count, position);
        }
        else if (strcmp(command, "display") == 0) {
            displayLines(lines, count);
        }
        else if (strcmp(command, "save") == 0) {
            saveFile(lines, count);
        }
        else if (strcmp(command, "load") == 0) {
            loadFile(lines, &count);
        }
        else if (strcmp(command, "help") == 0) {
            showHelp();
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting Line Editor...\n");
            break;
        }
        else {
            printf("Unknown command. Type 'help' to see available commands.\n");
        }
    }

    return 0;
}
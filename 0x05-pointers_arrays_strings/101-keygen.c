#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

char *generate_random_password()
{
    char *password = malloc((PASSWORD_LENGTH + 1) * sizeof(char));
    if (password == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int random_char = rand() % 94 + 32;
        password[i] = (char) random_char;
    }

    password[PASSWORD_LENGTH] = '\0';

    return password;
}

int main()
{
    char *password = generate_random_password();
    printf("Generated Password: %s\n", password);
    free(password);

    return 0;
}


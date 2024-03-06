#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    // Initialize readline


    while (1) {
        input = readline("Prompt: ");

        if (input == NULL)
            break; // Ctrl+D veya EOF ile çıkış yap

        // İşlemleriniz burada

    }

    return 0;
}

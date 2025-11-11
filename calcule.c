#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define NBR_QUESTIONS 5

int main() {
    int score = 0;
    int answer;
    int a, b;
    char op;
    clock_t start, end;
    double time_taken;

    printf("=== Jeu de calcul ===\n");
    printf("Tu as %d questions. Réponds vite !\n\n", NBR_QUESTIONS);
    
    srand(time(NULL)); 

    start = clock();

    for (int i = 1; i <= NBR_QUESTIONS; i++) {
        a = rand() % 10 + 1; 
        b = rand() % 10 + 1;
        int op_type = rand() % 3;
        switch(op_type) {
            case 0: op = '+'; break;
            case 1: op = '-'; break;
            case 2: op = '*'; break;
        }

        printf("+----------------+\n");
        printf("| Question %d      |\n", i);
        printf("| %d %c %d = ?    |\n", a, op, b);
        printf("+----------------+\n");
        printf("Réponse : ");
        scanf("%d", &answer);

        int correct;
        switch(op) {
            case '+': correct = (a + b); break;
            case '-': correct = (a - b); break;
            case '*': correct = (a * b); break;
        }

        if (answer == correct) {
            printf("✅ Correct !\n\n");
            score++;
        } else {
            printf("❌ Faux ! La bonne réponse était %d\n\n", correct);
        }
    }

    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("=== Résultat ===\n");
    printf("Score : %d/%d\n", score, NBR_QUESTIONS);
    printf("Temps total : %.2f secondes\n", time_taken);

    return 0;
}

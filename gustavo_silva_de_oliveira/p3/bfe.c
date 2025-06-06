#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 30000
#define BUFFER_SIZE 30000
#define MAX_NESTED_LOOPS 100

// Interpretador de Brainfuck
int brainfuck(const char* cod) {
    unsigned char memoria[MEMORY_SIZE] = {0};
    int ptr = 0;
    int cod_pos = 0;
    int loop_stack[MAX_NESTED_LOOPS];
    int loop_index = 0;
    int profundidade;
    
    while (cod[cod_pos] != '\0') {
        switch (cod[cod_pos]) {
            case '>':
                ptr++;
                if (ptr >= MEMORY_SIZE) {
                    printf("Erro: Ponteiro fora dos limites de memória (para frente)\n");
                    return 1;
                }
                break;
                
            case '<':
                ptr--;
                if (ptr < 0) {
                    printf("Erro: Ponteiro fora dos limites de memória (para trás)\n");
                    return 1;
                }
                break;
                
            case '+':
                memoria[ptr]++;
                break;
                
            case '-':
                memoria[ptr]--;
                break;
                
            case '.':
                putchar(memoria[ptr]);
                break;
                
            case ',':
                memoria[ptr] = getchar();
                break;
                
            case '[':
                if (memoria[ptr] == 0) {
                    // Pula para o correspondente ]
                    profundidade = 1;
                    while (profundidade > 0) {
                        cod_pos++;
                        if (cod[cod_pos] == '[') {
                            profundidade++;
                        } else if (cod[cod_pos] == ']') {
                            profundidade--;
                        }
                        
                        if (cod[cod_pos] == '\0') {
                            printf("Erro: Loop não fechado\n");
                            return 1;
                        }
                    }
                } else {
                    if (loop_index >= MAX_NESTED_LOOPS) {
                        printf("Erro: Loops aninhados demais\n");
                        return 1;
                    }
                    loop_stack[loop_index] = cod_pos;
                    loop_index++;
                }
                break;
                
            case ']':
                if (loop_index <= 0) {
                    printf("Erro: ']' sem correspondente '['\n");
                    return 1;
                }
                
                if (memoria[ptr] != 0) {
                    cod_pos = loop_stack[loop_index - 1];
                } else {
                    loop_index--;
                }
                break;
        }
        
        cod_pos++;
    }

    // Imprime o valor final.
    int result = memoria[0];
    printf("%d\n", result);
    
    return 0;
}

int main() {
    char cod[BUFFER_SIZE];
    char c;
    int pos = 0;
    
    while ((c = getchar()) != EOF && pos < BUFFER_SIZE - 1) {
        // Apenas caracteres válidos do Brainfuck são armazenados.
        if (c == '>' || c == '<' || c == '+' || c == '-' || 
            c == '.' || c == ',' || c == '[' || c == ']') {
            cod[pos] = c;
            pos++;
        }
    }
    cod[pos] = '\0';
    
    brainfuck(cod);
    
    return 0;
}
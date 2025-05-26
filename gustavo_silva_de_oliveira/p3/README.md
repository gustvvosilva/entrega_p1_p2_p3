# Entrega P3: Brainf__c

**Nome:** Gustavo Silva de Oliveira

## Como executar

- Compilação
  - Para compilar os códigos, escrevi um Makefile para facilitar o processo. Então basta apenas digitar **make** para compilar, já com todas flags que podem gerar erros ou warnings.
- Execução
  - Para executar, digite **make run**. Isso vai compilar e executar o programa, onde o bfc recebe a entrada que deixei pronta e transforma em brainfuck, esse brainfuck vai pro bfe, onde ele é calculado, e então o bfe retorna como saída o nome da variável e o calculo feito.

## Observações

Caso deseje ver a saída do bfc, em brainfuck, você pode usar **make bf**, onde apenas o bfc será executado.

- Limitações
  - Só aceita números inteiros positivos.
  - Não funciona com divisão
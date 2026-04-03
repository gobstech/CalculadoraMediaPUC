# Sistema de Cálculo de Médias - PUC-Campinas

![Institution](https://img.shields.io/badge/Institution-PUC--Campinas-purple)

---

## 📝 Resumo
Este é um software desenvolvido em linguagem **C** projetado para automatizar o cálculo das médias finais de diversas disciplinas da **PUC-Campinas**. O programa considera os pesos específicos de provas, testes e atividades práticas de cada matéria do 3º semestre do curso de Engenharia de Computação, fornecendo o resultado de aprovação ou reprovação de forma imediata e precisa.

---

## 🚀 Sobre o Projeto
O projeto nasceu da necessidade de simplificar a conferência de notas acadêmicas, que variam de acordo com critérios complexos de cada docente e disciplina.

### Principais Funcionalidades:
* **Modularização:** Cada disciplina possui sua própria lógica de cálculo isolada em funções específicas.
* **Robustez de Entrada:** Implementação de um sistema de validação que impede o travamento do programa (*loop infinito*) caso o usuário digite letras ou notas fora do intervalo de 0 a 10.
* **Compatibilidade Multiplataforma:** Função personalizada para limpeza de tela (`clearScreen`) que detecta o sistema operacional e executa o comando adequado (`cls` ou `clear`).
* **Disciplinas Abrangidas:**
    1.  PI: Projetos de Sistemas Digitais
    2.  Mecânica dos Sólidos
    3.  Cálculo II
    4.  Física do Movimento
    5.  Ética e Antropologia Teológica

---

## 🛠 Tecnologias Usadas
* **Linguagem C**: Base do desenvolvimento.
* **Biblioteca `stdio.h`**: Manipulação de entrada e saída padrão.
* **Biblioteca `stdlib.h`**: Comandos de sistema e utilitários.
* **Biblioteca `math.h`**: Operações matemáticas avançadas como `sqrt()` (raiz quadrada) e `cbrt()` (raiz cúbica).

---

## 💻 Como Instalar e Executar

O projeto é 100% open-source, disponibilizado para que outros estudantes possam personalizar melhor sua experiência de cálculos de médias das disciplinas universitárias de acordo com seu semestre e com o docente que a minstra. 

Para executar este projeto em sua máquina local, siga os passos abaixo:

1.  **Pré-requisitos:** Certifique-se de ter um compilador de C instalado (como o **GCC**).
2.  **Clonar/Copiar:** Salve o código fonte em um arquivo chamado `main.c`.
3.  **Compilar:** Abra o seu terminal e execute o comando:
    ```bash
    gcc main.c -o sistema_medias -lm
    ```
    > *Nota: O parâmetro `-lm` é essencial em sistemas Linux para vincular a biblioteca matemática.*
4.  **Executar:** * No **Windows**:
    ```bash
    ./sistema_medias.exe
    ```
    * No **Linux/macOS**:
        ```bash
        ./sistema_medias
        ```

---

## 🙏 Agradecimentos
Agradeço aos professores da **PUC-Campinas** pelos ensinamentos que basearam as fórmulas deste sistema, e ao suporte técnico durante o desenvolvimento da lógica de tratamento de *buffers* e ponteiros, garantindo um código mais limpo e eficiente.

---
*Desenvolvido como projeto de estudo para Engenharia.*
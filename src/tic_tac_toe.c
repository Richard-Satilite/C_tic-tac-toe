#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/tic_tac_toe_recursos.c"

Ttic_tac_toe classe_jogo;

void help()
{
    printf("\n\nO jogo da velha é composto por uma tabela contento 9 espaços, onde");
    printf(" o jogador poderá apenas jogar X ou O para marcar uma casa.");
    printf("\nO tipo de jogada (X ou O) é escolhido pelo jogador antes de iniciar uma");
    printf(" partida. A posição onde será realizada a jogada é dado\npela informação da linha e coluna");
    printf(" em que o jogador deseja realizar. O jogo irá perguntar qual a");
    printf(" linha (1 a 3) e coluna (1 a 3).\n\nA tabela terá esse formato:");
    printf("\n\n\t1\t\t2\t\t3");
    printf("\n1\t_\t|\t_\t|\t_");
    printf("\n2\t_\t|\t_\t|\t_");
    printf("\n3\t_\t|\t_\t|\t_");

    printf("\n\nA partida é terminada quando um jogador consegue inserir três jogadas em uma mesma\n");
    printf("linha, coluna ou diagonal. Caso ao final nenhum dos jogadores atinja essa situação e\n");
    printf("não há mais espaços para nenhuma jogada, então é considerado empate e o jogo também\n");
    printf("é encerrado.");
}

void emitir_tabela()
{
    printf("\n\n\t1\t\t2\t\t3");
    for (int i = 0; i < 3; i++)
    {
        putchar('\n');
        printf("%d", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("\t%d\t|", classe_jogo.tabela[i][j]);
        }
    }
}


int valida_pos(int row, int column)
{
    if ((row > 0 && row < 4) && (column > 0 && column < 4) && (classe_jogo.tabela[row - 1][column - 1] == 0))
    {
        return 1;
    }
    return 0;
}

void zerar_tabela()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            classe_jogo.tabela[i][j] = 0;
        }
    }
}

void atualizar_tabela(int row, int column, int tipo_jogada)
{
    classe_jogo.tabela[row - 1][column - 1] = tipo_jogada == 1 ? 1 : 2;
}

void pos(int tipo_jogada)
{
    int row, column, ver = 0;
    do
    {
        if (ver > 0)
        {
            printf("\n\nA LINHA OU COLUNA É INVÁLIDA OU O ESPAÇO JÁ FOI JOGADO!");
        }
        
        printf("\n\nDigite a linha e a coluna em que deseja jogar:");
        printf("\nLinha: ");
        scanf("%d", &row);
        printf("Coluna: ");
        scanf("%d", &column);
        ver++;
    } while (!(valida_pos(row, column)));
    atualizar_tabela(row, column, tipo_jogada);
}

int fim_partida()
{
    int jogada_atual, match, empate;
    for (int i = 0; i < 9; i++)
    {
        match = 0;
        empate = 0;
        switch (i)
        {
            case 0:
                jogada_atual = classe_jogo.tabela[0][0];
                if (jogada_atual != 0)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (classe_jogo.tabela[j][k] == jogada_atual && conf1[j][k] == 1)
                            {
                                match++;
                            }
                        }
                    }
                }
                break;
            case 1:
                jogada_atual = classe_jogo.tabela[0][0];
                if (jogada_atual != 0)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (classe_jogo.tabela[j][k] == jogada_atual && conf2[j][k] == 1)
                            {
                                match++;
                            }
                        }
                    }
                }
                break;
            case 2:
                jogada_atual = classe_jogo.tabela[0][0];
                if (jogada_atual != 0)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (classe_jogo.tabela[j][k] == jogada_atual && conf3[j][k] == 1)
                            {
                                match++;
                            }
                        }
                    }
                }
                break;
            case 3:
                jogada_atual = classe_jogo.tabela[1][0];
                if (jogada_atual != 0)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (classe_jogo.tabela[j][k] == jogada_atual && conf4[j][k] == 1)
                            {
                                match++;
                            }
                        }
                    }
                }
                break;
            case 4:
                jogada_atual = classe_jogo.tabela[2][0];
                if (jogada_atual != 0)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (classe_jogo.tabela[j][k] == jogada_atual && conf5[j][k] == 1)
                            {
                                match++;
                            }
                        }
                    }
                }
                break;
            case 5:
                jogada_atual = classe_jogo.tabela[0][2];
                if (jogada_atual != 0)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (classe_jogo.tabela[j][k] == jogada_atual && conf6[j][k] == 1)
                            {
                                match++;
                            }
                        }
                    }
                }
                break;
            case 6:
                jogada_atual = classe_jogo.tabela[0][1];
                if (jogada_atual != 0)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (classe_jogo.tabela[j][k] == jogada_atual && conf7[j][k] == 1)
                            {
                                match++;
                            }
                        }
                    }
                }
                break;
            case 7:
                jogada_atual = classe_jogo.tabela[0][2];
                if (jogada_atual != 0)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (classe_jogo.tabela[j][k] == jogada_atual && conf8[j][k] == 1)
                            {
                                match++;
                            }
                        }
                    }
                }
                break;
            default:
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        if (classe_jogo.tabela[j][k] != 0)
                        {
                            empate++;
                        }
                    }
                }
                break;
        }
        if (match == 3)
        {
            return jogada_atual;
        } else if (empate == 9)
        {
            return 3;
        }
    }
    return 0;
}

void multijogador()
{
    int ver=0, linha_m, coluna_m, resultado;
    zerar_tabela();
    do
    {
        if (ver > 0)
        {
            printf("\n\nOPÇÃO DE TIPO DE JOGADA INVÁLIDA. DIGITE 1 PARA JOGAR COM X OU 2 PARA JOGAR COM O");
        }
        
        printf("\nDigite o tipo de jogada do jogador 1:");
        printf("\n[1] - X");
        printf("\n[2] - O");
        printf("\nOpção: ");
        scanf("%d", &classe_jogo.tipo_jg1);
        ver++;
    } while ((classe_jogo.tipo_jg1 != 1 && classe_jogo.tipo_jg1 != 2));

    classe_jogo.tipo_jg2 = classe_jogo.tipo_jg1 == 1 ? 2 : 1;
        
    printf("\n\n\nINICIANDO JOGO MULTIJOGADOR");
    
    printf("\n\nJOGO INICIAL:");
    emitir_tabela();
    do
    {
        printf("\n\nVEZ DO JOGADOR 1");
        pos(classe_jogo.tipo_jg1);
        printf("\n\nJOGO:");
        emitir_tabela();

        if (fim_partida() == 0)
        {
            printf("\n\nVEZ DO JOGADOR 2");
            pos(classe_jogo.tipo_jg2);
            printf("\n\nJOGO:");
            emitir_tabela();
        }
        resultado = fim_partida();
    } while (resultado == 0);

    printf("\n\nJOGO ENCERRADO!");
    printf("\nRESULTADO: ");
    if (resultado == 1 || resultado == 2)
    {
        printf("JOGADOR COM A JOGADA %d (%c) GANHOU!", resultado, resultado == 1 ? 'X' : 'O');
    } else
    {
        printf("\nVELHA!");
    }
}

void maquina()
{
    srand(time(NULL));
    int ver=0, linha_m, coluna_m, resultado;
    zerar_tabela();
    do
    {
        if (ver > 0)
        {
            printf("\n\nOPÇÃO DE TIPO DE JOGADA INVÁLIDA. DIGITE 1 PARA JOGAR COM X OU 2 PARA JOGAR COM O");
        }
        
        printf("\nDigite o tipo de jogada que deseja:");
        printf("\n[1] - X");
        printf("\n[2] - O");
        printf("\nOpção: ");
        scanf("%d", &classe_jogo.tipo_jg1);
        ver++;
    } while ((classe_jogo.tipo_jg1 != 1 && classe_jogo.tipo_jg1 != 2));
        
    printf("\n\n\nINICIANDO JOGO CONTRA A MÁQUINA");
    do
    {
        printf("\n\nJOGO:");
        emitir_tabela();
        pos(classe_jogo.tipo_jg1);

        if (fim_partida() == 0)
        {
            printf("\nVEZ DA MÁQUINA!");
            do
            {
                linha_m = 1 + rand() % 3;
                coluna_m = 1 + rand() % 3;
            } while (!(valida_pos(linha_m, coluna_m)));
            atualizar_tabela(linha_m, coluna_m, classe_jogo.tipo_jg1 == 1 ? 2 : 1);
            printf("\n\nPOSIÇÃO DA MÁQUINA\n\nLinha: %d\nCOLUNA: %d\n", linha_m, coluna_m);
        }
        resultado = fim_partida();
    } while (resultado == 0);

    printf("\n\nJOGO ENCERRADO!");
    printf("\nRESULTADO: ");
    if (resultado == 1 || resultado == 2)
    {
        printf("JOGADOR COM A JOGADA %d (%c) GANHOU!", resultado, resultado == 1 ? 'X' : 'O');
    } else
    {
        printf("\nVELHA!");
    }
}

int menu()
{
    int ver = 0, opcao;
    printf("\n\nBem-vindo ao jogo da velha. Digite uma das opções abaixo:\n");
    printf("\n[1] - Jogar contra a máquina");
    printf("\n[2] - Partida multijogador");
    printf("\n[3] - Como jogar?");
    printf("\n[0] - Sair");

    do
    {
        if (ver > 0)
        {
            printf("\n\nOPÇÃO INVÁLIDA, DIGITE UMA DAS OPÇÕES (0, 1, 2 OU 3)");
        }

        printf("\nOpção: ");
        scanf("%d", &opcao);
        ver++;
    } while (opcao < 0 || opcao > 3);

    return opcao;
}

int main()
{
    int op, ver = 0;
    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            maquina();
            break;
        case 2:
            multijogador();
            break;
        case 3:
            help();
            break;
        default:
            printf("\nOBRIGADO POR JOGAR!\n");
            break;
        }
    } while (op != 0);
}
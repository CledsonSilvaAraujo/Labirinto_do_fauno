#include "Player.h"
#include <stdlib.h>
#include <stdio.h>
#define LINHAS 21
#define COLUNAS 21

Player * criaPlayer(Maze* maze)
{
    Player * jogador;
    int i, j;
    jogador=(Player*)malloc(sizeof(Player));
    jogador->simbolo_exibido='X';
    jogador->status=1;

    for(i=0; i<LINHAS; i++)
    {
        for(j=0; j <COLUNAS; j++)
        {
            if(maze->matriz[i][j].dado==jogador->simbolo_exibido)
            {

                jogador->posicao_inicial_player.x=i;
                jogador->posicao_inicial_player.y=j;
                jogador->posicao_atual_player.x=i;
                jogador->posicao_atual_player.y=j;
            }
        }
    }

    return jogador;
}
void andar(Player* player,Maze* maze,char key)
{
    printf("anterior - x: %d, y: %d\n", player->posicao_atual_player.x, player->posicao_atual_player.y);

    if(key=='a'||key=='A')
    {
        if(maze->matriz[player->posicao_atual_player.x][player->posicao_atual_player.y-1].dado!='#')
        {
            maze->matriz[player->posicao_atual_player.x][player->posicao_atual_player.y].dado='.';
            maze->matriz[player->posicao_atual_player.x][player->posicao_atual_player.y-1].dado= 'X';
            player->posicao_inicial_player.y=player->posicao_atual_player.y;
            player->posicao_inicial_player.x=player->posicao_atual_player.x;
            player->posicao_atual_player.y-=1;

        }
    }
    if(key=='d'||key=='D')
    {
        if(maze->matriz[player->posicao_atual_player.x][player->posicao_atual_player.y+1].dado!='#')
        {
            maze->matriz[player->posicao_atual_player.x][player->posicao_atual_player.y].dado='.';
            maze->matriz[player->posicao_atual_player.x][player->posicao_atual_player.y+1].dado= 'X';
            player->posicao_inicial_player.y=player->posicao_atual_player.y;
            player->posicao_inicial_player.x=player->posicao_atual_player.x;
            player->posicao_atual_player.y+=1;


        }
    }
    if(key=='w'||key=='W')
    {
        if(maze->matriz[player->posicao_atual_player.x-1][player->posicao_atual_player.y].dado!='#')
        {
            maze->matriz[player->posicao_atual_player.x][player->posicao_atual_player.y].dado='.';
            maze->matriz[player->posicao_atual_player.x-1][player->posicao_atual_player.y].dado= 'X';
            player->posicao_inicial_player.y=player->posicao_atual_player.y;
            player->posicao_inicial_player.x=player->posicao_atual_player.x;
            player->posicao_atual_player.x-=1;
        }
    }
    if(key=='s'||key=='S')
    {
        if(maze->matriz[player->posicao_atual_player.x+1][player->posicao_atual_player.y].dado !='#')
        {
            maze->matriz[player->posicao_atual_player.x][player->posicao_atual_player.y].dado='.';
            maze->matriz[player->posicao_atual_player.x+1][player->posicao_atual_player.y].dado= 'X';
            player->posicao_inicial_player.y = player->posicao_atual_player.y;
            player->posicao_inicial_player.x = player->posicao_atual_player.x;
            player->posicao_atual_player.x += 1;
        }
    }
}
void destroiPlayer(Player* player)
{
    free(player);
}
//funcao verifica_espaco_livre retorna 1 se o proximo movimento e possivel



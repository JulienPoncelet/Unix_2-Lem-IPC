#include <lemipc.h>

void							move(t_player *player, int dir)
{
	lock(player->semid);
	if (dir == UP)
	{
		player->board->map[player->cury][player->curx] = 0;
		player->cury--;
		if (!(player->board->map[player->cury][player->curx]))
			player->board->map[player->cury][player->curx] = player->team;
	}
	if (dir == DOWN)
	{
		player->board->map[player->cury][player->curx] = 0;
		player->cury++;
		if (!(player->board->map[player->cury][player->curx]))
			player->board->map[player->cury][player->curx] = player->team;
	}
	move2(player, dir);
}

void							move2(t_player *player, int dir)
{
	if (dir == RIGHT)
	{
		player->board->map[player->cury][player->curx] = 0;
		player->curx++;
		if (!(player->board->map[player->cury][player->curx]))
			player->board->map[player->cury][player->curx] = player->team;
	}
	if (dir == LEFT)
	{
		player->board->map[player->cury][player->curx] = 0;
		player->curx--;
		if (!(player->board->map[player->cury][player->curx]))
			player->board->map[player->cury][player->curx] = player->team;
	}
	unlock(player->semid);
}

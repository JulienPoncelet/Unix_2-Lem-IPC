#include <lemipc.h>

void							move(t_player *player, int dir)
{
	if (dir == UP)
	{
		player->board->map[player->cury][player->curx] = 0;
		player->cury--;
		if (!(is_valid(player->curx, player->cury)))
			move(player, RIGHT);
		if (!(player->board->map[player->cury][player->curx]))
			player->board->map[player->cury][player->curx] = player->team;
	}
	if (dir == DOWN)
	{
		player->board->map[player->cury][player->curx] = 0;
		player->cury++;
		if (!(is_valid(player->curx, player->cury)))
			move(player, LEFT);
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
		if (!(is_valid(player->curx, player->cury)))
			move(player, DOWN);
		if (!(player->board->map[player->cury][player->curx]))
			player->board->map[player->cury][player->curx] = player->team;
	}
	if (dir == LEFT)
	{
		player->board->map[player->cury][player->curx] = 0;
		player->curx--;
		if (!(is_valid(player->curx, player->cury)))
			move(player, UP);
		if (!(player->board->map[player->cury][player->curx]))
			player->board->map[player->cury][player->curx] = player->team;
	}
}

int								is_valid(int x, int y)
{
	if (x < 0 || x >= X || y < 0 || y >= Y)
		return (0);
	return (1);
}

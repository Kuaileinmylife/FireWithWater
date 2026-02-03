#include "collision.h"
#include "../common.h"

bool collision_check(Player* player,Level* level) {
	if (level->currentMap == 0) {
		// 循环地图各个关键的坐标如果碰到了或者触发了需要进行对应的处理
		// 地图边界的碰撞检测
		for (int i = 0;i < 4;i++) {
			if (player->position.x + player->position.width >= level->mapboundary_level1[i].x && player->position.x <= level->mapboundary_level1[i].x + level->mapboundary_level1[i].width
				&& player->position.y <= level->mapboundary_level1[i].y + level->mapboundary_level1[i].height && player->position.y + player->position.height >= level->mapboundary_level1[i].y) {
				return true;
			}
		}

		// 陷阱的检测
		for (int i = 0;i < level->trapCount;i++) {
			if (player->position.x + player->position.width >= level->trapstation1[i].x && player->position.x <= level->trapstation1[i].x + level->trapstation1[i].width
				&& player->position.y <= level->trapstation1[i].y + level->trapstation1[i].height && player->position.y + player->position.height >= level->trapstation1[i].y) {
				
				switch (level->trapstation1[i].type) {
				case 0:// 火池
					if (player->type = PLAYER_WATER) {
						player->isAlive = false;
					}
					break;
				case 1:// 水池
					if (player->type == PLAYER_FIRE) {
						player->isAlive = false;
					}
					break;
				case 2:// 毒池
					player->isAlive = false;
					break;
				case 3:// 火出口
					player->iswin = true;
					break;
				case 4:// 水出口
					player->iswin = true;
					break;
				}
			}
		}

		// 空气墙的检测
		for (int i = 0;i < level->platfromCount;i++) {
			if (player->position.x + player->position.width >= level->platfrom_level1[i].x && player->position.x <= level->platfrom_level1[i].x + level->platfrom_level1[i].width
				&& player->position.y <= level->platfrom_level1[i].y + level->platfrom_level1[i].height && player->position.y + player->position.height >= level->platfrom_level1[i].y) {
				return true;
			}
		}
	}
	return false;       
}
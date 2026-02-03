#include "collision.h"
#include "../common.h"

bool collision_check(Player* player,Level* level) {
	if (level->currentMap == 0) {
		// 循环地图各个关键的坐标如果碰到了或者触发了需要进行对应的处理
		for (int i = 0;i < 4;i++) {
			level->mapboundary_level1[i].x;
		}

		for (int i = 0;i < level->trapCount;i++) {

		}

		for (int i = 0;i < level->platfromCount;i++) {

		}
	}
	return false;
}
#include "collision.h"
#include "../common.h"

bool collision_check(Player* player,Level* level) {
	if (level->currentMap == 0) {
		// 空气墙的检测
		for (int i = 0;i < level->platfromCount;i++) {
			if (player->position.x + player->position.width >= level->platfrom_level1[i].x && player->position.x <= level->platfrom_level1[i].x + level->platfrom_level1[i].width
				&& player->position.y <= level->platfrom_level1[i].y + level->platfrom_level1[i].height && player->position.y + player->position.height >= level->platfrom_level1[i].y) {
				float playerLeft = player->position.x;
				float playerRight = player->position.x + player->position.width;
				float playerTop = player->position.y;
				float playerBottom = player->position.y + player->position.height;

				float platLeft = level->platfrom_level1[i].x;
				float platRight = level->platfrom_level1[i].x + level->platfrom_level1[i].width;
				float platTop = level->platfrom_level1[i].y;
				float platBottom = level->platfrom_level1[i].y + level->platfrom_level1[i].height;

				// 计算从各边穿透的深度
				float overlapLeft = playerRight - platLeft;    // 从左边撞入的深度
				float overlapRight = platRight - playerLeft;   // 从右边撞入的深度
				float overlapTop = playerBottom - platTop;     // 从上面撞入的深度
				float overlapBottom = platBottom - playerTop;  // 从下面撞入的深度

				// 找出最小的穿透深度（从哪边撞入最少）
				float minOverlap = overlapLeft;
				int direction = 0; // 0:从左撞 1:从右撞 2:从上撞 3:从下撞

				if (overlapRight < minOverlap) {
					minOverlap = overlapRight;
					direction = 1;
				}
				if (overlapTop < minOverlap) {
					minOverlap = overlapTop;
					direction = 2;
				}
				if (overlapBottom < minOverlap) {
					minOverlap = overlapBottom;
					direction = 3;
				}

				// 根据碰撞方向处理
				if (direction == 2) { // 从上往下撞（站在平台上）
					player->position.y = platTop - player->position.height; // 调整到平台上面
					player->velocity.y = 0;  // 停止下落
					player->isOnGround = true;
					player->isJumping = false;
				}
				if (direction == 3) { // 从下往上撞（头顶撞到空气墙）
					player->position.y = platBottom; // 调整到平台下面
					player->velocity.y = 0;  // 停止上升
				}
				if (direction == 0) { // 从左边撞到
					player->position.x = platLeft - player->position.width; // 调整到平台左边
					player->velocity.x = 0;  // 停止向右移动
				}
				if (direction == 1) { // 从右边撞到
					player->position.x = platRight; // 调整到平台右边
					player->velocity.x = 0;  // 停止向左移动
				}
				//return true;
			}
		}
		// 循环地图各个关键的坐标如果碰到了或者触发了需要进行对应的处理
		// 地图边界的碰撞检测
		/*for (int i = 0;i < 4;i++) {
			if (player->position.x + player->position.width >= level->mapboundary_level1[i].x && player->position.x <= level->mapboundary_level1[i].x + level->mapboundary_level1[i].width
				&& player->position.y <= level->mapboundary_level1[i].y + level->mapboundary_level1[i].height && player->position.y + player->position.height >= level->mapboundary_level1[i].y) {
				level->info.shouldStopX = true;
				level->info.shouldStopY = true;
				return true;
			}
		}*/

		// 陷阱的检测
		for (int i = 0;i < level->trapCount;i++) {
			if (player->position.x + player->position.width >= level->trapstation1[i].x && player->position.x <= level->trapstation1[i].x + level->trapstation1[i].width
				&& player->position.y <= level->trapstation1[i].y + level->trapstation1[i].height && player->position.y + player->position.height >= level->trapstation1[i].y) {
				
				switch (level->trapstation1[i].type) {
				case 0:// 火池
					if (player->type == PLAYER_WATER) {
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
					if (player->type == PLAYER_FIRE) {
						player->iswin = true;
					}
					break;
				case 4:// 水出口
					if (player->type == PLAYER_WATER) {
						player->iswin = true;
					}
					break;
				}
			}
		}
	}

	// 第二关碰撞检测
	if (level->currentMap == 1) {
		// 空气墙的检测
		for (int i = 0;i < level->platfromCount;i++) {
			if (player->position.x + player->position.width >= level->platfrom_level2[i].x && player->position.x <= level->platfrom_level2[i].x + level->platfrom_level2[i].width
				&& player->position.y <= level->platfrom_level2[i].y + level->platfrom_level2[i].height && player->position.y + player->position.height >= level->platfrom_level2[i].y) {
				float playerLeft = player->position.x;
				float playerRight = player->position.x + player->position.width;
				float playerTop = player->position.y;
				float playerBottom = player->position.y + player->position.height;

				float platLeft = level->platfrom_level2[i].x;
				float platRight = level->platfrom_level2[i].x + level->platfrom_level2[i].width;
				float platTop = level->platfrom_level2[i].y;
				float platBottom = level->platfrom_level2[i].y + level->platfrom_level2[i].height;

				// 计算从各边穿透的深度
				float overlapLeft = playerRight - platLeft;    // 从左边撞入的深度
				float overlapRight = platRight - playerLeft;   // 从右边撞入的深度
				float overlapTop = playerBottom - platTop;     // 从上面撞入的深度
				float overlapBottom = platBottom - playerTop;  // 从下面撞入的深度

				// 找出最小的穿透深度（从哪边撞入最少）
				float minOverlap = overlapLeft;
				int direction = 0; // 0:从左撞 1:从右撞 2:从上撞 3:从下撞

				if (overlapRight < minOverlap) {
					minOverlap = overlapRight;
					direction = 1;
				}
				if (overlapTop < minOverlap) {
					minOverlap = overlapTop;
					direction = 2;
				}
				if (overlapBottom < minOverlap) {
					minOverlap = overlapBottom;
					direction = 3;
				}

				// 根据碰撞方向处理
				if (direction == 2) { // 从上往下撞（站在平台上）
					player->position.y = platTop - player->position.height; // 调整到平台上面
					player->velocity.y = 0;  // 停止下落
					player->isOnGround = true;
					player->isJumping = false;
				}
				if (direction == 3) { // 从下往上撞（头顶撞到空气墙）
					player->position.y = platBottom; // 调整到平台下面
					player->velocity.y = 0;  // 停止上升
				}
				if (direction == 0) { // 从左边撞到
					player->position.x = platLeft - player->position.width; // 调整到平台左边
					player->velocity.x = 0;  // 停止向右移动
				}
				if (direction == 1) { // 从右边撞到
					player->position.x = platRight; // 调整到平台右边
					player->velocity.x = 0;  // 停止向左移动
				}
				//return true;
			}
		}
		

		// 陷阱的检测
		for (int i = 0;i < level->trapCount;i++) {
			if (player->position.x + player->position.width >= level->trapstation2[i].x && player->position.x <= level->trapstation2[i].x + level->trapstation2[i].width
				&& player->position.y <= level->trapstation2[i].y + level->trapstation2[i].height && player->position.y + player->position.height >= level->trapstation2[i].y) {

				switch (level->trapstation2[i].type) {
				case 0:// 火池
					if (player->type == PLAYER_WATER) {
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
					if (player->type == PLAYER_FIRE) {
						player->iswin = true;
					}
					break;
				case 4:// 水出口
					if (player->type == PLAYER_WATER) {
						player->iswin = true;
					}
					break;
				}
			}
		}
	}

	// 第三关碰撞检测
	if (level->currentMap == 2) {
		// 空气墙的检测
		for (int i = 0;i < level->platfromCount;i++) {
			if (player->position.x + player->position.width >= level->platfrom_level3[i].x && player->position.x <= level->platfrom_level3[i].x + level->platfrom_level3[i].width
				&& player->position.y <= level->platfrom_level3[i].y + level->platfrom_level3[i].height && player->position.y + player->position.height >= level->platfrom_level3[i].y) {
				float playerLeft = player->position.x;
				float playerRight = player->position.x + player->position.width;
				float playerTop = player->position.y;
				float playerBottom = player->position.y + player->position.height;

				float platLeft = level->platfrom_level3[i].x;
				float platRight = level->platfrom_level3[i].x + level->platfrom_level3[i].width;
				float platTop = level->platfrom_level3[i].y;
				float platBottom = level->platfrom_level3[i].y + level->platfrom_level3[i].height;

				// 计算从各边穿透的深度
				float overlapLeft = playerRight - platLeft;    // 从左边撞入的深度
				float overlapRight = platRight - playerLeft;   // 从右边撞入的深度
				float overlapTop = playerBottom - platTop;     // 从上面撞入的深度
				float overlapBottom = platBottom - playerTop;  // 从下面撞入的深度

				// 找出最小的穿透深度（从哪边撞入最少）
				float minOverlap = overlapLeft;
				int direction = 0; // 0:从左撞 1:从右撞 2:从上撞 3:从下撞

				if (overlapRight < minOverlap) {
					minOverlap = overlapRight;
					direction = 1;
				}
				if (overlapTop < minOverlap) {
					minOverlap = overlapTop;
					direction = 2;
				}
				if (overlapBottom < minOverlap) {
					minOverlap = overlapBottom;
					direction = 3;
				}

				// 根据碰撞方向处理
				if (direction == 2) { // 从上往下撞（站在平台上）
					player->position.y = platTop - player->position.height; // 调整到平台上面
					player->velocity.y = 0;  // 停止下落
					player->isOnGround = true;
					player->isJumping = false;
				}
				if (direction == 3) { // 从下往上撞（头顶撞到空气墙）
					player->position.y = platBottom; // 调整到平台下面
					player->velocity.y = 0;  // 停止上升
				}
				if (direction == 0) { // 从左边撞到
					player->position.x = platLeft - player->position.width; // 调整到平台左边
					player->velocity.x = 0;  // 停止向右移动
				}
				if (direction == 1) { // 从右边撞到
					player->position.x = platRight; // 调整到平台右边
					player->velocity.x = 0;  // 停止向左移动
				}
				//return true;
			}
		}


		// 陷阱的检测
		for (int i = 0;i < level->trapCount;i++) {
			if (player->position.x + player->position.width >= level->trapstation3[i].x && player->position.x <= level->trapstation3[i].x + level->trapstation3[i].width
				&& player->position.y <= level->trapstation3[i].y + level->trapstation3[i].height && player->position.y + player->position.height >= level->trapstation3[i].y) {

				switch (level->trapstation3[i].type) {
				case 0:// 火池
					if (player->type == PLAYER_WATER) {
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
					if (player->type == PLAYER_FIRE) {
						player->iswin = true;
					}
					break;
				case 4:// 水出口
					if (player->type == PLAYER_WATER) {
						player->iswin = true;
					}
					break;
				}
			}
		}
	}
	return false;       
}
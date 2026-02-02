#pragma once
#include "../common.h"

// 碰撞函数声明
 
//// 基础碰撞检测
//// 负责人；小黄3
//// 功能：判断两个函数是否重叠
//// 1；进行x，y两个方向检测
//// 2；如果两个方向都重叠就是碰撞了
//bool collision_check(Rect a, Rect b);
//
//// 玩家与矩形的碰撞检测
//// 负责人；金闪闪2
//// 功能：
//// 1. 调用player_get_bounds获取玩家边框
//// 2, 返回collision_check使用基本碰撞检测来判断
//bool collision_player_rect(const Player* player, Rect rect);
//
//// 获取玩家边框
//// 负责人；star3
//// 功能：根据玩家的尺寸返回当前玩家的边框
//// 1.一定要返回边框
//Rect player_get_bounds(const Player* player);
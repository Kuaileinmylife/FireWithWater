// game/player.h
#pragma once
#include "../common.h"

// 玩家函数声明

// 玩家初始化
// 负责人；阿超2
// 功能；设置玩家初始位置和状态
// 1；设置玩家类型火人还是冰人
// 2；设置初始位置
// 3；初始化玩家的速度
// 4；设置玩家的碰撞框
// 5；设置玩家的初始状态(空中，还是地面等)
void player_init(Player* p, PlayerType type, float x, float y);

// 更新玩家状态
// 负责人；小黄2
// 功能；
// 1；运用重力，设置玩家竖直方向上的速度，让玩家下降
// 2；设置最大下落速度
// 3；根据运动更新玩家位置，以及碰撞框
// 4；做出地面检测和撞墙检测
void player_update(Player* p);

// 负责人；阿超3
// 功能；控制玩家左右移动
// 1；设置水平速度
// 2；记录朝向(用于绘图)
    // dx = -1：向左移动
    // dx = 0：停止移动  
    // dx = 1：向右移动
void player_move(Player* p, float dx);

// 负责人；奶黄包2
// 功能；
// 1；只有在地面的时候才能跳
void player_jump(Player* p);

// 负责人；奶黄包2
// 功能；把玩家画在窗口上
// 1；根据玩家的类型选颜色(定义int color，仔细看定义)
// 2；调用render_rect绘制玩家矩形
void player_draw(const Player* p);

// 负责人；奶黄包3
// 功能；根据玩家的类型判断是否会受伤(仔细看定义)
// 1；注意好返回值
bool player_check_trap(const Player* p, TrapType trap);
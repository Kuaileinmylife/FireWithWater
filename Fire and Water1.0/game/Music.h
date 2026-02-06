#pragma once
#include <windows.h>
#include "../common.h"


// -------------------------- 1. 菜单/暂停音乐控制 --------------------------
/** 播放菜单/暂停音乐（循环） */
void music_menu_pause_play();

/** 暂停菜单/暂停音乐 */
void music_menu_pause_pause();

/** 继续播放菜单/暂停音乐 */
void music_menu_pause_resume();

/** 播放游戏过程音乐（循环） */
void music_game_play_play();

/** 暂停游戏过程音乐 */
void music_game_play_pause();

// -------------------------- 3. 胜利场景音乐 --------------------------
/** 播放胜利音乐（单次） */
void music_win_play();

// -------------------------- 4. 失败场景音乐 --------------------------
/** 播放失败音乐（单次） */
void music_fail_play();

// -------------------------- 全局音乐资源释放 --------------------------
/** 关闭所有音乐（游戏退出时调用） */
void music_all_close();
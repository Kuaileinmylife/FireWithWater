#include "../common.h"
#include "../game/Music.h"

// -------------------------- 通用工具函数（内部使用） --------------------------
/**
 * 检查指定别名音乐的状态
 */
MusicState _check_music_state(const TCHAR* alias) {
    char status_buf[256] = { 0 };
    TCHAR cmd[256];
    wsprintf(cmd, _T("status %s mode"), alias);
    mciSendString(cmd, status_buf, sizeof(status_buf), NULL);

    if (strstr(status_buf, "playing") != NULL) return MUSIC_PLAYING;
    if (strstr(status_buf, "paused") != NULL) return MUSIC_PAUSED;
    return MUSIC_STOP;
}

/**
 * 初始化指定别名的音乐（仅首次打开）
 */
bool _init_music(const TCHAR* path, const TCHAR* alias) {
    if (_check_music_state(alias) != MUSIC_STOP) return true;

    TCHAR open_cmd[256];
    wsprintf(open_cmd, _T("open \"%s\" alias %s"), path, alias);
    return (mciSendString(open_cmd, NULL, 0, NULL) == 0);
}


// -------------------------- 1. 菜单/暂停音乐控制 --------------------------
/** 播放菜单/暂停音乐（循环） */
void music_menu_pause_play() {
    if (_init_music(MENU_PAUSE_MUSIC, MENU_PAUSE_ALIAS)) {
        mciSendString(_T("play ") MENU_PAUSE_ALIAS _T(" repeat"), NULL, 0, NULL);
        // 应用当前音量
        extern int g_volumeLevel;
        TCHAR cmd[256];
        wsprintf(cmd, _T("setaudio ") MENU_PAUSE_ALIAS _T(" volume to %d"), g_volumeLevel * 10);
        mciSendString(cmd, NULL, 0, NULL);
    }
}

/** 暂停菜单/暂停音乐 */
void music_menu_pause_pause() {
    if (_check_music_state(MENU_PAUSE_ALIAS) == MUSIC_PLAYING) {
        mciSendString(_T("pause ") MENU_PAUSE_ALIAS, NULL, 0, NULL);
        // 应用当前音量
        extern int g_volumeLevel;
        TCHAR cmd[256];
        wsprintf(cmd, _T("setaudio ") MENU_PAUSE_ALIAS _T(" volume to %d"), g_volumeLevel * 10);
        mciSendString(cmd, NULL, 0, NULL);
    }
}

/** 继续播放菜单/暂停音乐 */
void music_menu_pause_resume() {
    if (_check_music_state(MENU_PAUSE_ALIAS) == MUSIC_PAUSED) {
        mciSendString(_T("resume ") MENU_PAUSE_ALIAS, NULL, 0, NULL);
        // 应用当前音量
        extern int g_volumeLevel;
        TCHAR cmd[256];
        wsprintf(cmd, _T("setaudio ") MENU_PAUSE_ALIAS _T(" volume to %d"), g_volumeLevel * 10);
        mciSendString(cmd, NULL, 0, NULL);
    }
}


// -------------------------- 2. 游戏过程音乐控制 --------------------------
/** 播放游戏过程音乐（循环） */
void music_game_play_play() {
    if (_init_music(GAME_PLAY_MUSIC, GAME_PLAY_ALIAS)) {
        mciSendString(_T("play ") GAME_PLAY_ALIAS _T(" repeat"), NULL, 0, NULL);
        // 应用当前音量
        extern int g_volumeLevel;
        TCHAR cmd[256];
        wsprintf(cmd, _T("setaudio ") MENU_PAUSE_ALIAS _T(" volume to %d"), g_volumeLevel * 10);
        mciSendString(cmd, NULL, 0, NULL);
    }
}

/** 暂停游戏过程音乐 */
void music_game_play_pause() {
    if (_check_music_state(GAME_PLAY_ALIAS) == MUSIC_PLAYING) {
        mciSendString(_T("pause ") GAME_PLAY_ALIAS, NULL, 0, NULL);
        // 应用当前音量
        extern int g_volumeLevel;
        TCHAR cmd[256];
        wsprintf(cmd, _T("setaudio ") MENU_PAUSE_ALIAS _T(" volume to %d"), g_volumeLevel * 10);
        mciSendString(cmd, NULL, 0, NULL);
    }
}

// -------------------------- 3. 胜利场景音乐 --------------------------
/** 播放胜利音乐（单次） */
void music_win_play() {
    // 先关闭已播放的胜利音乐（避免重复叠加）
    mciSendString(_T("stop ") WIN_ALIAS, NULL, 0, NULL);
    mciSendString(_T("close ") WIN_ALIAS, NULL, 0, NULL);

    if (_init_music(WIN_MUSIC, WIN_ALIAS)) {
        mciSendString(_T("play ") WIN_ALIAS, NULL, 0, NULL);
        // 应用当前音量
        extern int g_volumeLevel;
        TCHAR cmd[256];
        wsprintf(cmd, _T("setaudio ") MENU_PAUSE_ALIAS _T(" volume to %d"), g_volumeLevel * 10);
        mciSendString(cmd, NULL, 0, NULL);
    }
}


// -------------------------- 4. 失败场景音乐 --------------------------
/** 播放失败音乐（单次） */
void music_fail_play() {
    // 先关闭已播放的失败音乐
    mciSendString(_T("stop ") FAIL_ALIAS, NULL, 0, NULL);
    mciSendString(_T("close ") FAIL_ALIAS, NULL, 0, NULL);

    if (_init_music(FAIL_MUSIC, FAIL_ALIAS)) {
        mciSendString(_T("play ") FAIL_ALIAS, NULL, 0, NULL);
        // 应用当前音量
        extern int g_volumeLevel;
        TCHAR cmd[256];
        wsprintf(cmd, _T("setaudio ") MENU_PAUSE_ALIAS _T(" volume to %d"), g_volumeLevel * 10);
        mciSendString(cmd, NULL, 0, NULL);
    }
}


// -------------------------- 全局音乐资源释放 --------------------------
/** 关闭所有音乐（游戏退出时调用） */
void music_all_close() {
    mciSendString(_T("stop ") MENU_PAUSE_ALIAS _T(" close ") MENU_PAUSE_ALIAS, NULL, 0, NULL);
    mciSendString(_T("stop ") GAME_PLAY_ALIAS _T(" close ") GAME_PLAY_ALIAS, NULL, 0, NULL);
    mciSendString(_T("stop ") WIN_ALIAS _T(" close ") WIN_ALIAS, NULL, 0, NULL);
    mciSendString(_T("stop ") FAIL_ALIAS _T(" close ") FAIL_ALIAS, NULL, 0, NULL);
}
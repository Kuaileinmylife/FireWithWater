# 森林冰火人 🔥💧

> Fire and Water 1.0 — 一款基于 C++ 和 EasyX 的双人合作闯关游戏

</div>

## 项目简介

**森林冰火人**是一款 Windows 平台的 2D 双人合作平台跳跃游戏，灵感来源于经典游戏 *Fireboy and Watergirl*。游戏中，火娃和冰娃需要携手穿越森林中的重重关卡，避开致命陷阱，收集宝石，最终同时到达各自的出口才能通关。

游戏包含 **3 个精心设计的关卡**、**7 种游戏状态**（主菜单、游戏中、暂停、胜利、失败、团队介绍、设置），以及完整的背景音乐和音效系统。

## 操作方式

| 角色 | 移动 | 跳跃 |
|------|------|------|
| 🔥 火娃 | `A` / `D` | `W` |
| 💧 冰娃 | `←` / `→` | `↑` |

| 系统按键 | 功能 |
|----------|------|
| `Esc` | 暂停 / 返回菜单 |
| `Enter` | 确认选择 |

## 游戏规则

- **火娃**碰到水陷阱会死亡，**冰娃**碰到火陷阱会死亡，尖刺陷阱对两者都致命
- 红宝石只能由火娃收集，蓝宝石只能由冰娃收集
- 火娃必须到达火出口，冰娃必须到达水出口 — **两人都到达各自出口才算通关**
- 第二关引入了**机关门**和**按钮**机制，需要配合才能通过

## 技术栈

| 类别 | 技术 |
|------|------|
| 语言 | C / C++ |
| 图形库 | [EasyX](https://easyx.cn/)（基于 Windows GDI） |
| 音频 | Windows MCI（winmm.lib） |
| 构建 | Visual Studio 2022（v143 工具链） |
| 平台 | Windows x64 / x86 |

## 项目结构

```
Fire and Water1.0/
├── main.cpp                 # 程序入口
├── common.h                 # 公共定义（结构体、枚举、常量、宏）
├── game/
│   ├── Game.h / Game.cpp    # 游戏状态机 & 主循环
│   ├── Player.h / Player.cpp # 玩家实体（物理、移动、渲染）
│   ├── Level.h / Level.cpp  # 关卡数据（平台、陷阱、宝石、出口）
│   └── Music.h / Music.cpp  # 背景音乐 / 音效（MCI 控制）
├── graphics/
│   ├── Render.h / Render.cpp # 底层绘图封装
│   ├── Texture.h / Texture.cpp # 纹理管理
│   └── UI.h / UI.cpp         # 界面（菜单、暂停、设置、胜负、团队）
├── input/
│   └── Input.h / Input.cpp   # 键盘输入轮询
├── physic/
│   └── Collision.h / Collision.cpp # AABB 碰撞检测 & 响应
└── *.png / *.jpg / *.mp3     # 图片和音频资源
```

## 构建与运行

### 环境要求

- Windows 操作系统
- [Visual Studio 2022](https://visualstudio.microsoft.com/)（含 C++ 桌面开发工作负载）
- [EasyX](https://easyx.cn/) 图形库

### 构建步骤

1. 克隆仓库
   ```bash
   git clone (https://github.com/Kuaileinmylife/FireWithWater)
   ```

2. 安装 [EasyX](https://easyx.cn/)（如未安装）

3. 用 Visual Studio 2022 打开 `Fire and Water1.0.sln`

4. 选择 `Debug x64` 配置，按 `F5` 编译运行

### 直接运行

编译好的可执行文件位于 `x64/Debug/Fire and Water1.0.exe`。

## 团队成员

| 角色 | 成员 |
|------|------|
| 组长 | 柯然 |
| 技术官 | V07 |
| 技术官 | 小黄 |
| 信息官 | 阿超 |
| 产品经理 | 金闪闪 |
| 产品经理 | Star |
| 产品经理 | 小李 |
| 记录官 | 奶黄包 |
| 监督官 | 意识 |
| 副组长 | 立体纸片 |

## License

本项目仅供学习交流使用。

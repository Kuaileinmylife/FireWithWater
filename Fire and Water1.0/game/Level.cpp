#include "level.h"
#include "../common.h"
#include "../graphics/Render.h"
#include "../graphics/Texture.h"

// 初始化关卡
int level_init(Level* level, int levelNum) {
    if (!level->isinit) {
        level->currentMap = 2;
    }

    level->info.isOnGround = false;
    level->info.shouldStopX = false;
    level->info.shouldStopY = false;

    // 初始化所有格子为空地
    for (int y = 0; y < level->height; y++) {
        for (int x = 0; x < level->width; x++) {
            level->tiles[y][x] = TILE_EMPTY;
        }
    }

    // 创建地图 第一关
    if (level->currentMap == 0) {

        // level->info.groundY=多少       这个根据地图来定
         
        // 地图一的边界
        level->mapboundary_level1[0] = MapBoundary{ 18,9,19,580 };
        level->mapboundary_level1[1] = MapBoundary{ 10,572,780,10 };
        level->mapboundary_level1[2] = MapBoundary{ 770,31,23,537 };
        level->mapboundary_level1[3] = MapBoundary{ 18,9,768,20 };

        // 地图一的空气墙们
        level->platfrom_level1[0] = Platfrom{ 35.91,573.16,342.64,15 };
        level->platfrom_level1[1] = Platfrom{ 474.31,569.68,55.86,15 };
        level->platfrom_level1[2] = Platfrom{ 639.4,572.16,69.33,7 };
        level->platfrom_level1[3] = Platfrom{ 711.72,524.41,10.49,38.77 };
        level->platfrom_level1[4] = Platfrom{ 720,510.52,200.50,12.43 };
        level->platfrom_level1[5] = Platfrom{ 677.30,445.9,8.48,33.80 };
        level->platfrom_level1[6] = Platfrom{ 595.01,449.38,78.8,5 };
        level->platfrom_level1[7] = Platfrom{ 536.16,469.76,143.14,6 };
        level->platfrom_level1[8] = Platfrom{ 0,0,0,0.0 };
        level->platfrom_level1[9] = Platfrom{ 481.29,472.74,32.87,16.90 };
        level->platfrom_level1[10] = Platfrom{ 392.02,446.89,99.25,10 };
        level->platfrom_level1[11] = Platfrom{ 349.13,466.28,126.18,10 };
        level->platfrom_level1[12] = Platfrom{ 328.18,424.52,51.37,41.26 };
        level->platfrom_level1[13] = Platfrom{ 0,429,276.81,5 };
        level->platfrom_level1[14] = Platfrom{ 0,409,319.2,5 };
        level->platfrom_level1[15] = Platfrom{ 37.91,485.67,236.91,9.94 };
        level->platfrom_level1[16] = Platfrom{ 43.89,505.05,229.92,10 };
        level->platfrom_level1[17] = Platfrom{ 266.83,487.16,5.49,23.36 };
        level->platfrom_level1[18] = Platfrom{ 107.24,307.21,7.98,28.79 };
        level->platfrom_level1[19] = Platfrom{ 110.72,305.22,299.75,10 };
        level->platfrom_level1[20] = Platfrom{ 115.21,322.06,266.33,5.45 };
        level->platfrom_level1[21] = Platfrom{ 400.98,319.14,24.45,17.4 };
        level->platfrom_level1[22] = Platfrom{ 395.01,351.95,253.37,10 };
        level->platfrom_level1[23] = Platfrom{ 403.91,325.6,334.16,10 };
        level->platfrom_level1[24] = Platfrom{ 666.33,344.49,44.89,27.84 };
        level->platfrom_level1[25] = Platfrom{ 719.7,353.44,78.8,57.17 };
        level->platfrom_level1[26] = Platfrom{ 595.01,267.44,95.26,5.97 };
        level->platfrom_level1[27] = Platfrom{ 572.57,226.68,122.69,10 };
        level->platfrom_level1[28] = Platfrom{ 534.66,204.81,25.94,32.31 };
        level->platfrom_level1[29] = Platfrom{ 390.02,187.90,140.15,10 };
        level->platfrom_level1[30] = Platfrom{ 388,198.84,7.98,24.36 };
        level->platfrom_level1[31] = Platfrom{ 133.17,225.68,260.85,10 };
        level->platfrom_level1[32] = Platfrom{ 34.41,245.57,537.65,8.95 };
        level->platfrom_level1[33] = Platfrom{ 128.18,163.55,10,60.65 };
        level->platfrom_level1[34] = Platfrom{ 34.41,148.63,96.26,11.93 };
        level->platfrom_level1[35] = Platfrom{ 199,90.47,26.43,22.87 };
        level->platfrom_level1[36] = Platfrom{ 228.43,91.96,31.42,30.82 };
        level->platfrom_level1[37] = Platfrom{ 262.34,109.86,42.39,23.36 };
        level->platfrom_level1[38] = Platfrom{ 231.42,138.19,103.24,53.69 };
        level->platfrom_level1[39] = Platfrom{ 314.21,126.26,212.97,10 };
        level->platfrom_level1[40] = Platfrom{ 344.64,148.63,418.45,3.98 };
        level->platfrom_level1[41] = Platfrom{ 534.16,113.84,14.46,25.85 };
        level->platfrom_level1[42] = Platfrom{ 552.12,113.84,51.37,5 };
        level->platfrom_level1[43] = Platfrom{ 607.98,112.84,12.97,29.33 };
        level->platfrom_level1[44] = Platfrom{ 629.42,128.75,46.88,8.45 };
        level->platfrom_level1[45] = Platfrom{ 625,128,148,8 };
        level->platfrom_level1[46] = Platfrom{ 732,286,40,8 };
        level->platfrom_level1[47] = Platfrom{ 132,187,40,8 };
        level->platfrom_level1[48] = Platfrom{ 74,367,10,48 };
        level->platfrom_level1[49] = Platfrom{ 732,286,10,48 };
        level->platfrom_level1[50] = Platfrom{ 163,187,10,48 };

        level->platfrom_level1[51] = Platfrom{ 18,9,19,580 };
        level->platfrom_level1[52] = Platfrom{ 10,572,780,10 };
        level->platfrom_level1[53] = Platfrom{ 770,31,23,537 };
        level->platfrom_level1[54] = Platfrom{ 18,9,768,20 };
        level->platfrom_level1[55] = Platfrom{ 580,240,25,20 };
        level->platfrom_level1[56] = Platfrom{ 33,367,49,10 };

        
        // 设置空气墙的数量
        level->platfromCount = 57;
        

        // 地图一的各种陷阱和出口
        level->trapstation1[0] = Trapstation{ 378,565,77,9,0,false };
        level->trapstation1[1] = Trapstation{ 540.65,560,83,6.5,1,false };
        level->trapstation1[2] = Trapstation{ 504,454,67,6,2,false };
        level->trapstation1[3] = Trapstation{ 638.9,71.5,41,51.7,3,false };
        level->trapstation1[4] = Trapstation{ 698.25,76.55,46.88,46.23,4,false };
            
        // 设置陷阱和出口一共的数量
        level->trapCount = 5;

        // 设置起点
        level->fireStart.x = 92;
        level->fireStart.y = 518;
        level->waterStart.x = 92;
        level->waterStart.y = 437;
    }

    // 创建地图 第二关
    if (level->currentMap == 1) {
        level->mapboundary_level2[0] = MapBoundary{ 13,9,19,560 };
        level->mapboundary_level2[1] = MapBoundary{ 10,582,780,7 };
        level->mapboundary_level2[2] = MapBoundary{ 770,31,23,537 };
        level->mapboundary_level2[3] = MapBoundary{ 34,9,733,20 };

        level->platfrom_level2[0] = Platfrom{ 22.0, 108.0, 319.0, 22.0 };
        level->platfrom_level2[1] = Platfrom{ 450.0, 107.0, 207.0, 22.0 };
        level->platfrom_level2[2] = Platfrom{ 598.0, 131.0, 78.0, 17.0 };
        level->platfrom_level2[3] = Platfrom{ 618.0, 150.0, 82.0, 18.0 };
        level->platfrom_level2[4] = Platfrom{ 720.0, 211.0, 60.0, 7.0 };
        level->platfrom_level2[5] = Platfrom{ 721.0, 220.0, 3.0, 51.0 };
        level->platfrom_level2[6] = Platfrom{ 678.0, 273.0, 42.0, 7.0 };
        level->platfrom_level2[7] = Platfrom{ 678.0, 281.0, 11.0, 50.0 };
        level->platfrom_level2[8] = Platfrom{ 617.0, 332.0, 58.0, 13.0 };
        level->platfrom_level2[9] = Platfrom{ 507.0, 275.0, 78.0, 15.0 };
        level->platfrom_level2[10] = Platfrom{ 348.0, 313.0, 107.0, 20.0 };
        level->platfrom_level2[11] = Platfrom{ 219.0, 274.0, 80.0, 17.0 };
        level->platfrom_level2[12] = Platfrom{ 124.0, 332.0, 43.0, 23.0 };
        level->platfrom_level2[13] = Platfrom{ 169.0, 346.0, 613.0, 8.0 };
        level->platfrom_level2[14] = Platfrom{ 24.0, 374.0, 59.0, 10.0 };
        level->platfrom_level2[15] = Platfrom{ 73.0, 386.0, 11.0, 48.0 };
        level->platfrom_level2[16] = Platfrom{ 84.0, 437.0, 633.0, 18.0 };
        level->platfrom_level2[17] = Platfrom{ 761.0, 498.0, 18.0, 9.0 };
        level->platfrom_level2[18] = Platfrom{ 743.0, 503.0, 16.0, 11.0 };
        level->platfrom_level2[19] = Platfrom{ 725.0, 517.0, 22.0, 15.0 };
        level->platfrom_level2[20] = Platfrom{ 721.0, 535.0, 11.0, 53.0 };
        level->platfrom_level2[21] = Platfrom{ 616.0, 580.0, 102.0, 8.0 };
        level->platfrom_level2[22] = Platfrom{ 452.0, 530.0, 163.0, 10.0 };
        level->platfrom_level2[23] = Platfrom{ 123.0, 529.0, 187.0, 11.0 };
        level->platfrom_level2[24] = Platfrom{ 308.0, 579.0, 148.0, 11.0 };
        level->platfrom_level2[25] = Platfrom{ 22.0, 579.0, 104.0, 15.0 };

        level->platfrom_level2[26] = Platfrom{ 0, 0 ,24 ,590 };
        level->platfrom_level2[27] = Platfrom{ 0, 587,781 ,15 };
        level->platfrom_level2[28] = Platfrom{ 780, 29, 20, 556 };
        level->platfrom_level2[29] = Platfrom{ 22,0 , 758, 20 };

        level->platfrom_level2[30] = Platfrom{ 125, 585, 182,10 };
        level->platfrom_level2[31] = Platfrom{ 459, 585, 152, 10};

        // 设置空气墙的数量
        level->platfromCount = 32;

        // 地图一的各种陷阱和出口
        level->trapstation2[0] = Trapstation{ 458.0, 331.0, 157.0, 12.0,2,false };
        level->trapstation2[1] = Trapstation{ 169.0, 331.0, 177.0, 13.0,2,false };
        level->trapstation2[2] = Trapstation{ 460.0, 516.0, 161.0, 13.0,0,false };
        level->trapstation2[3] = Trapstation{ 128.0, 578.0, 178.0, 11.0,0,false };
        level->trapstation2[4] = Trapstation{ 124.0, 515.0, 185.0, 13.0,1,false };
        level->trapstation2[5] = Trapstation{ 459.0, 578.0, 154.0, 11.0,1,false };
        level->trapstation2[6] = Trapstation{ 25.0,49.0, 52.0, 54,3,false };
        level->trapstation2[7] = Trapstation{ 91, 49.0, 49, 54,4,false };

        // 设置陷阱和出口一共的数量
        level->trapCount = 8;

        // 设置玩家的出生位置
        level->fireStart.x = 36;
        level->fireStart.y = 530;
        level->waterStart.x = 79;
        level->waterStart.y = 530;
    }

    // 创建地图 第三关
    if (level->currentMap == 2) {
        //地图三的边界
        level->mapboundary_level3[0] = MapBoundary{ 18.58,12.87,760.39,9.9 };
        level->mapboundary_level3[1] = MapBoundary{ 12.7,12.8,5.86,570.3 };
        level->mapboundary_level3[2] = MapBoundary{ 19, 583.2, 761.4, 6.4 };
        level->mapboundary_level3[3] = MapBoundary{ 777.5,22.7,38.8,557.4 };
        //地图三的空气墙们
        level->platfrom_level3[0] = Platfrom{ 81.6,23,10,19 };
        level->platfrom_level3[1] = Platfrom{ 100,43,21,3 };
        level->platfrom_level3[2] = Platfrom{ 124,23,19,39 };
        level->platfrom_level3[3] = Platfrom{ 142 ,64,20,2 };
        level->platfrom_level3[4] = Platfrom{ 165 ,26,21,58 };
        level->platfrom_level3[5] = Platfrom{ 189,24,43,42 };
        level->platfrom_level3[6] = Platfrom{ 335 ,24,131,37 };
        level->platfrom_level3[7] = Platfrom{ 386 ,63,25,44 };
        level->platfrom_level3[8] = Platfrom{ 544,22,46,44 };
        level->platfrom_level3[9] = Platfrom{ 592 ,22,19,67 };
        level->platfrom_level3[10] = Platfrom{ 613 ,65,26,3 };
        level->platfrom_level3[11] = Platfrom{ 633 ,23,22,39 };
        level->platfrom_level3[12] = Platfrom{ 656,43,21,2 };
        level->platfrom_level3[13] = Platfrom{ 673,24,23,16 };
        level->platfrom_level3[14] = Platfrom{ 21 ,92,18,65 };
        level->platfrom_level3[15] = Platfrom{ 42 ,105,40,3 };
        level->platfrom_level3[16] = Platfrom{ 41,147,40,3 };
        level->platfrom_level3[17] = Platfrom{ 82,114,14,46 };
        level->platfrom_level3[18] = Platfrom{ 96 ,130,14,43 };
        level->platfrom_level3[19] = Platfrom{ 110,138,13,48 };
        level->platfrom_level3[20] = Platfrom{ 123 ,153,12,47 };
        level->platfrom_level3[21] = Platfrom{ 136 ,167,12,42 };
        level->platfrom_level3[22] = Platfrom{ 150 ,179,11,30 };
        level->platfrom_level3[23] = Platfrom{ 165 ,190,61,3 };
        level->platfrom_level3[24] = Platfrom{ 227 ,177,16,31 };
        level->platfrom_level3[25] = Platfrom{ 244,162,15,42 };
        level->platfrom_level3[26] = Platfrom{ 259 ,151,7,41 };
        level->platfrom_level3[27] = Platfrom{ 267 ,147,39,4 };
        level->platfrom_level3[28] = Platfrom{ 269 ,172,36,14 };
        level->platfrom_level3[29] = Platfrom{ 308 ,153,13,48 };
        level->platfrom_level3[30] = Platfrom{ 321 ,164,14,49 };
        level->platfrom_level3[31] = Platfrom{ 333 ,183,34,30 };
        level->platfrom_level3[32] = Platfrom{ 346.6 ,198,11.4,15 };
        level->platfrom_level3[33] = Platfrom{ 359 ,206,10,7 };
        level->platfrom_level3[34] = Platfrom{ 427 ,211,46, 3 };
        level->platfrom_level3[35] = Platfrom{ 434 ,195,12,15 };
        level->platfrom_level3[36] = Platfrom{ 446 ,184,13,27 };
        level->platfrom_level3[37] = Platfrom{ 459 ,170,16,39 };
        level->platfrom_level3[38] = Platfrom{ 476 ,154,13,53 };
        level->platfrom_level3[39] = Platfrom{ 488,149,46,3 };
        level->platfrom_level3[40] = Platfrom{ 491,170,43,18 };
        level->platfrom_level3[41] = Platfrom{ 535,158,16,52 };
        level->platfrom_level3[42] = Platfrom{ 550 ,174,19,36 };
        level->platfrom_level3[43] = Platfrom{ 571,188,63,5 };
        level->platfrom_level3[44] = Platfrom{ 552,210,102,3 };
        level->platfrom_level3[45] = Platfrom{ 636 ,176,19,34 };
        level->platfrom_level3[46] = Platfrom{ 655,156,22,47 };
        level->platfrom_level3[47] = Platfrom{ 676 ,136,24,46 };
        level->platfrom_level3[48] = Platfrom{ 700 ,115,15,40 };
        level->platfrom_level3[49] = Platfrom{ 715 ,104,42,5 };
        level->platfrom_level3[50] = Platfrom{ 757 ,94,21,54 };
        level->platfrom_level3[51] = Platfrom{ 715 ,148,44,4 };
        level->platfrom_level3[52] = Platfrom{ 81 ,246,5,45 };
        level->platfrom_level3[53] = Platfrom{ 86 ,260,15,48 };
        level->platfrom_level3[54] = Platfrom{ 101 ,278,20,34 };
        level->platfrom_level3[55] = Platfrom{ 123,292,59,4 };
        level->platfrom_level3[56] = Platfrom{ 102 ,313,61,4 };
        level->platfrom_level3[57] = Platfrom{ 166 ,296,26,31 };
        level->platfrom_level3[58] = Platfrom{ 192,307,16,35 };
        level->platfrom_level3[59] = Platfrom{ 208,322,15,20 };
        level->platfrom_level3[60] = Platfrom{ 288 ,323,22,45 };
        level->platfrom_level3[61] = Platfrom{ 311 ,298,23,49 };
        level->platfrom_level3[62] = Platfrom{ 333 ,275,13,46 };
        level->platfrom_level3[63] = Platfrom{ 348 ,270,103,62 };
        level->platfrom_level3[64] = Platfrom{ 452 ,274,18,51 };
        level->platfrom_level3[65] = Platfrom{ 471 ,299,28,48 };
        level->platfrom_level3[66] = Platfrom{ 491 ,318,21,49 };
        level->platfrom_level3[67] = Platfrom{ 574 ,318,22,23 };
        level->platfrom_level3[68] = Platfrom{ 597,300,25,39 };
        level->platfrom_level3[69] = Platfrom{ 613 ,290,63,4 };
        level->platfrom_level3[70] = Platfrom{ 677 ,283,19,28 };
        level->platfrom_level3[71] = Platfrom{ 696,267,19,33 };
        level->platfrom_level3[72] = Platfrom{ 716 ,249,3,44 };
        level->platfrom_level3[73] = Platfrom{ 635 ,311,62,4 };
        level->platfrom_level3[74] = Platfrom{ 203,342,84,48 };
        level->platfrom_level3[75] = Platfrom{ 202,391,40,53 };
        level->platfrom_level3[76] = Platfrom{ 514 ,343,81,54 };
        level->platfrom_level3[77] = Platfrom{ 553 ,387,39,42 };
        level->platfrom_level3[78] = Platfrom{ 21 ,359,17,78 };
        level->platfrom_level3[79] = Platfrom{ 39,378,16,31 };
        level->platfrom_level3[80] = Platfrom{ 55,394,13,15 };
        level->platfrom_level3[81] = Platfrom{ 38 ,409,41,5 };
        level->platfrom_level3[82] = Platfrom{ 764 ,353,14,83 };
        level->platfrom_level3[83] = Platfrom{ 745 ,373,19,38 };
        level->platfrom_level3[84] = Platfrom{ 728 ,393,15,22 };
        level->platfrom_level3[85] = Platfrom{ 715,415,47,6 };
        level->platfrom_level3[86] = Platfrom{ 89 ,505,10,9 };
        level->platfrom_level3[87] = Platfrom{ 99 ,498,44,4 };
        level->platfrom_level3[88] = Platfrom{ 84 ,515,59,4 };
        level->platfrom_level3[89] = Platfrom{ 146,494,13,20 };
        level->platfrom_level3[90] = Platfrom{ 160,457,14,39 };
        level->platfrom_level3[91] = Platfrom{ 176,463,15,19 };
        level->platfrom_level3[92] = Platfrom{ 192,446,16,18 };
        level->platfrom_level3[93] = Platfrom{ 223 ,539,43,40 };
        level->platfrom_level3[94] = Platfrom{ 266,498,40,82 };
        level->platfrom_level3[95] = Platfrom{ 288 ,462,60,10 };
        level->platfrom_level3[96] = Platfrom{ 370 ,420,61,11 };
        level->platfrom_level3[97] = Platfrom{ 453 ,460,57,13 };
        level->platfrom_level3[98] = Platfrom{ 308 ,570,182,9 };
        level->platfrom_level3[99] = Platfrom{ 491 ,499,41,81 };
        level->platfrom_level3[100] = Platfrom{ 533 ,539,40,41 };
        level->platfrom_level3[101] = Platfrom{ 591 ,441,16,24 };
        level->platfrom_level3[102] = Platfrom{ 607,457,18,29 };
        level->platfrom_level3[103] = Platfrom{ 626,480,21,27 };
        level->platfrom_level3[104] = Platfrom{ 649,498,47,4 };
        level->platfrom_level3[105] = Platfrom{ 696 ,503,14,16 };
        level->platfrom_level3[106] = Platfrom{ 648,520,71,4 };

        level->platfrom_level3[107] = Platfrom{ 0,0,20,590 };
        level->platfrom_level3[108] = Platfrom{ 19,580,770, 10};
        level->platfrom_level3[109] = Platfrom{ 778,5,10,585 };
        level->platfrom_level3[110] = Platfrom{ 19,3,790,10 };

        //设计空气墙数量
        level->platfromCount = 111;

        // 地图三的各种陷阱和出口
        // 0:火池，1：水池，2：毒池，3：火出口，4：水出口
        level->trapstation3[0] = Trapstation{ 225 ,331,62,11 ,0,false };
        level->trapstation3[1] = Trapstation{ 514,331,60,12 ,1,false };
        level->trapstation3[2] = Trapstation{ 308 ,556,179,12,2,false };
        level->trapstation3[3] = Trapstation{ 52.8,528.2,36.6,50.5,3,false };
        level->trapstation3[4] = Trapstation{ 708.1,528.7,37.1,48.5,4,false };

        // 设置陷阱和出口一共的数量
        level->trapCount = 5;

        // 设置起点
        level->fireStart.x = 46;
        level->fireStart.y = 48;
        level->waterStart.x = 719;
        level->waterStart.y = 47;
    }

    return level->currentMap;
}

// 绘制关卡
void level_draw(const Level* level, TextureManager* tm) {
    if (!level) return;
    IMAGE p;
    switch (level->currentMap) {
    case 0:
        loadimage(&p, "map1.png", WINDOW_WIDTH, WINDOW_HEIGHT);
        putimage(0, 0, &p);
        break;
    case 1:
        loadimage(&p, "map2.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
        putimage(0, 0, &p);
        break;
    case 2:
        loadimage(&p, "map3.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
        putimage(0, 0, &p);
        break;
    }
}
# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <stdbool.h>

int D[20][20];									//存放各景点间的距离
int P[20][20];									//记录路径数组

void list( )										//主菜单
{
    //system("cls");
    printf("\n\n");
    printf("\t\t          欢迎使用杭州电子科技大学导游系统       \n");
    printf("\t\t --------------------------------------------\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|        1.显示校园平面图.                      |\n");
    printf("\t\t|        2.查询任意场所的相关信息.                |\n");
    printf("\t\t|        3.校门口到各个场所的最短路径.             |\n");
    printf("\t\t|        4.任意场所的问路查询.                   |\n");
    printf("\t\t|        5.退出                               |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t --------------------------------------------\n");
    printf("\n\t\t       请输入您要进行的操作的序号          \n");
}

void view( )							      //浏览校园地图
{
    //system("cls");
    printf("\t                                     杭州电子科技大学                       \n");
    printf("\t -------------------------------------------------------------------------------------------------\n");
    printf("\t                                                                                                   \n");
    printf("\t ========== 北二门 ======================================= 北一门 ==================================\n");
    printf("\t|                 | 4 八教 |                    |10 综合楼 |      | 14 学生活动 |    |       |        |\n");
    printf("\t|                                                               |     中心   |    | 18 东  |       |\n");
    printf("\t| 2 体育馆 |                     | 8 图书馆 |                                      |    操  |        |\n");
    printf("\t|                                                               | 15 五四广场 |    |    场  |       |\n");
    printf("\t| --------        | 5 六教 |                    | 11 七教 |                        |--------|       |\n");
    printf("\t|         |                                                                                       |\n");
    printf("\t|         |                                                     | 16 十二教 |     | 19 十一教 |      |\n");
    printf("\t|  3 西   |       | 6 四教 |    | 9 三鼎问天 |    | 12 三教 |                                         |\n");
    printf("\t|    操   |                                                                                       |\n");
    printf("\t|    场   |                                                      | 17 十教  |     | 20 九教  |      |\n");
    printf("\t|---------|       | 7 二教 |                    | 13 一教 |                                         |\n");
    printf("\t|                                                                                                 |\n");
    printf("\t|                              --------------                                                     |\n");
    printf("\t|                             |              |                                                    |\n");
    printf("\t|                             |    1 校门     |                                                    |\n");
    printf("\t -------------------------------------------------------------------------------------------------\n");
    printf("\t                                                                                                    \n");
    printf("\n\t                                  按任意键返回主菜单.                                               \n");
    getch();
}

void judge(int key)	//判断景点序号
{
    switch(key)
    {
        case  1  :printf("校门 ");return;
        case  2  :printf("体育馆 ");return;
        case  3  :printf("西操场 ");return;
        case  4  :printf("八教 ");return;
        case  5  :printf("六教");return;
        case  6  :printf("四教 ");return;
        case  7  :printf("二教 ");return;
        case  8  :printf("图书馆 ");return;
        case  9  :printf("三鼎问天 ");return;
        case  10  :printf("综合楼 ");return;
        case  11  :printf("七教 ");return;
        case  12  :printf("三教 ");return;
        case  13  :printf("一教 ");return;
        case  14  :printf("学生活动中心 ");return;
        case  15  :printf("五四广场 ");return;
        case  16  :printf("十二教 ");return;
        case  17  :printf("十教 ");return;
        case  18  :printf("东操场 ");return;
        case  19  :printf("十一教 ");return;
        default  :printf("九教 ");return;
    }
}

void message( )         //查看学校中各景点信息
{
    //system("cls");
    int x;
    printf("请输入要查询场所的序号1 - 20 (0 键结束):");
    while(scanf("%d",&x) == 1)
    {
        if(x == 0)break;
        switch(x)
        {
            case  1  :printf("%d",x); judge(x); printf("亚洲第二大校门.\n");break;
            case  2  :printf("%d",x); judge(x); printf("室内体育馆，用于举办新生入学典礼，CUBA等重大活动.\n");break;
            case  3  :printf("%d",x); judge(x); printf("内含足球场、篮球场、网球场、排球场等场地.\n");break;
            case  4  :printf("%d",x); judge(x); printf("内有车间等供同学金工实习用.\n");break;
            case  5  :printf("%d",x); judge(x); printf("信诚楼：理学院、材料与工程学院所在教学楼\n");break;
            case  6  :printf("%d",x); judge(x); printf("新建教学楼，用于实验研究.\n");break;
            case  7  :printf("%d",x); judge(x); printf("信义楼：自动化学院、电子信息学院、机械工程学院所在教学楼.\n");break;
            case  8  :printf("%d",x); judge(x); printf("供同学借阅图书自习等场所.\n");break;
            case  9  :printf("%d",x); judge(x); printf("杭电一大景点，别名“三柱香”.\n");break;
            case  10  :printf("%d",x); judge(x); printf("校医院、保卫处、收发室等所在地.\n");break;
            case  11  :printf("%d",x); judge(x); printf("信博楼：公共课教室.\n");break;
            case  12  :printf("%d",x); judge(x); printf("信理楼：外国语学院所在教学楼.\n");break;
            case  13  :printf("%d",x); judge(x); printf("信仁楼：计算机学院、通信工程学院、网络安全学院所在教学楼.\n");break;
            case  14  :printf("%d",x); judge(x); printf("学生活动中心，经常有同学练琴练舞.\n");break;
            case  15  :printf("%d",x); judge(x); printf("别名'升旗广场'，每天清晨由国旗护卫队同学承担升旗任务.\n");break;
            case  16  :printf("%d",x); judge(x); printf("公共课教室”.\n");break;
            case  17  :printf("%d",x); judge(x); printf("卓越学院等学院所在教学楼.\n");break;
            case  18  :printf("%d",x); judge(x); printf("经常有同学夜跑.\n");break;
            case  19  :printf("%d",x); judge(x); printf("公共课教室.\n");break;
            case  20  :printf("%d",x); judge(x); printf("管理学院等所在教学楼.\n");break;
            default :printf("输入有误，请重新输入.\n");
        }
        printf("\n请输入要查询场所的序号1 - 20 (0 键结束):");
    }
    printf("按任意键返回主菜单.\n");
    getch();
}

void Initiate( )        //初始化D[]和P[]，存放D[]的距离
{
    int i,j;
    for(i = 1;i <= 20;i ++)
    {
        for(j = 1;j <= 20;j ++)
        {
            P[i][j] = j;
            if(i ==j)
                D[i][j] = 0;
            else
                D[i][j] = -1;
        }
    }
    D[1][3] = D[3][1] = 200;
    D[2][3] = D[3][2] = 50;
    D[2][4] = D[4][2] = 100;
    D[2][5] = D[5][2] = 80;
    D[3][6] = D[6][3] = 60;
    D[3][7] = D[7][3] = 60;
    D[4][5] = D[5][4] = 150;
    D[5][6] = D[6][5] = 100;
    D[6][7] = D[7][6] = 100;
    D[7][1] = D[1][7] = 100;
    D[4][10] = D[10][4] = 300;
    D[4][8] = D[8][4] = 70;
    D[5][8] = D[8][5] = 80;
    D[7][1] = D[1][7] = 100;
    D[8][10] = D[10][8] =70;
    D[8][11] = D[11][8] = 80;
    D[11][12] = D[12][11] =100;
    D[12][13] = D[13][12] =100;
    D[1][13] = D[13][1] =100;
    D[10][14] = D[14][10] = 80;
    D[10][15] = D[15][10] = 120;
    D[11][15] = D[15][11] =80;
    D[11][16] = D[16][11] = 90;
    D[12][16] = D[16][12] = 100;
    D[12][17] = D[17][12] =95;
    D[13][17] = D[17][13] =100;
    D[14][15] = D[15][14] =50;
    D[15][16] = D[16][15] =60;
    D[16][17] = D[17][16] =70;
    D[15][18] = D[18][15] =30;
    D[15][19] = D[19][15] =70;
    D[16][19] = D[19][16] =35;
    D[16][20] = D[20][16] =50;
    D[17][20] = D[20][17] =40;
    D[18][19] = D[19][18] =50;
    D[19][20] = D[20][19] =60;
}

void floyd( )								//弗洛伊德算法求最短路
{
    int i,j,k;
    for(k = 1;k <= 20;k++)
    {
        for(i = 1;i <= 20;i++)
        {
            if( i == k || D[i][k] == -1 ) continue;
            for(j = 1;j <= 20;j ++)
            {
                if( i == j || k == j || D[k][j] == -1 ) continue;
                int tmp = D[i][k] + D[k][j];
                if(D[i][j] == -1 || D[i][j] > tmp)
                {
                    D[i][j] = tmp;
                    P[i][j] = P[i][k];
                }
                else
                    if(D[i][j] == tmp && P[i][k] < P[i][j])
                {
                    P[i][j]=P[i][k];
                }
            }
        }
    }
}


void path(int x,int y)							//输出起点到终点的路径
{
    int all=0;
    int m,n;
    printf("最短Path: ");
    judge(x);
    while(P[x][y] != y)
    {
        printf("--> ");
        judge(P[x][y]);
        m=x;
        n=P[x][y];
        all=all+D[m][n];
        x = P[x][y];
    }
    all=all+D[x][y];
    printf("--> ");
    judge(y);
    printf("\t\t\t路径总长：%d m\n",all);
}



void search( )									//进行查找起点到终点操作
{
    //system("cls");
    int strat,end;
    printf("请选择起点的景点(1-20): ");
    scanf("%d",&strat);
    printf("\n");
    printf("请选择终点的景点(1-20): ");
    scanf("%d",&end);
    printf("\n");
    if(strat != end)
    {
        path(strat,end);
        printf("\n");
    }
    else
    {
        printf("起点与终点相同.\n");
    }
    printf("按任意键返回.\n");
    getch();
}

void door( )
{
    //system("cls");
    int i;
    printf("校门口到各景点的最短路径.\n\n");
    for(i = 2;i <= 20;i ++)
    {
        path(1,i);
        printf("\n");
    }
    printf("按任意键返回.\n");
    getch();
}

int main( )
{
    bool flag = false;
    while( !flag )
    {
        list();
        char s[5];
        scanf("%s",s);
        Initiate();
        floyd();
        switch(s[0])
        {
            case '1' :  view();break;
            case '2' :  message();break;
            case '3' :  door();break;
            case '4' : search();break;
            case '5' :  flag = true;break;
            default  :  list();break;
        }
    }
    return 0;
}
# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <stdbool.h>

int D[20][20];									//��Ÿ������ľ���
int P[20][20];									//��¼·������

void list( )										//���˵�
{
    //system("cls");
    printf("\n\n");
    printf("\t\t          ��ӭʹ�ú��ݵ��ӿƼ���ѧ����ϵͳ       \n");
    printf("\t\t --------------------------------------------\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|        1.��ʾУ԰ƽ��ͼ.                      |\n");
    printf("\t\t|        2.��ѯ���ⳡ���������Ϣ.                |\n");
    printf("\t\t|        3.У�ſڵ��������������·��.             |\n");
    printf("\t\t|        4.���ⳡ������·��ѯ.                   |\n");
    printf("\t\t|        5.�˳�                               |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t|                                            |\n");
    printf("\t\t --------------------------------------------\n");
    printf("\n\t\t       ��������Ҫ���еĲ��������          \n");
}

void view( )							      //���У԰��ͼ
{
    //system("cls");
    printf("\t                                     ���ݵ��ӿƼ���ѧ                       \n");
    printf("\t -------------------------------------------------------------------------------------------------\n");
    printf("\t                                                                                                   \n");
    printf("\t ========== ������ ======================================= ��һ�� ==================================\n");
    printf("\t|                 | 4 �˽� |                    |10 �ۺ�¥ |      | 14 ѧ��� |    |       |        |\n");
    printf("\t|                                                               |     ����   |    | 18 ��  |       |\n");
    printf("\t| 2 ������ |                     | 8 ͼ��� |                                      |    ��  |        |\n");
    printf("\t|                                                               | 15 ���Ĺ㳡 |    |    ��  |       |\n");
    printf("\t| --------        | 5 ���� |                    | 11 �߽� |                        |--------|       |\n");
    printf("\t|         |                                                                                       |\n");
    printf("\t|         |                                                     | 16 ʮ���� |     | 19 ʮһ�� |      |\n");
    printf("\t|  3 ��   |       | 6 �Ľ� |    | 9 �������� |    | 12 ���� |                                         |\n");
    printf("\t|    ��   |                                                                                       |\n");
    printf("\t|    ��   |                                                      | 17 ʮ��  |     | 20 �Ž�  |      |\n");
    printf("\t|---------|       | 7 ���� |                    | 13 һ�� |                                         |\n");
    printf("\t|                                                                                                 |\n");
    printf("\t|                              --------------                                                     |\n");
    printf("\t|                             |              |                                                    |\n");
    printf("\t|                             |    1 У��     |                                                    |\n");
    printf("\t -------------------------------------------------------------------------------------------------\n");
    printf("\t                                                                                                    \n");
    printf("\n\t                                  ��������������˵�.                                               \n");
    getch();
}

void judge(int key)	//�жϾ������
{
    switch(key)
    {
        case  1  :printf("У�� ");return;
        case  2  :printf("������ ");return;
        case  3  :printf("���ٳ� ");return;
        case  4  :printf("�˽� ");return;
        case  5  :printf("����");return;
        case  6  :printf("�Ľ� ");return;
        case  7  :printf("���� ");return;
        case  8  :printf("ͼ��� ");return;
        case  9  :printf("�������� ");return;
        case  10  :printf("�ۺ�¥ ");return;
        case  11  :printf("�߽� ");return;
        case  12  :printf("���� ");return;
        case  13  :printf("һ�� ");return;
        case  14  :printf("ѧ������� ");return;
        case  15  :printf("���Ĺ㳡 ");return;
        case  16  :printf("ʮ���� ");return;
        case  17  :printf("ʮ�� ");return;
        case  18  :printf("���ٳ� ");return;
        case  19  :printf("ʮһ�� ");return;
        default  :printf("�Ž� ");return;
    }
}

void message( )         //�鿴ѧУ�и�������Ϣ
{
    //system("cls");
    int x;
    printf("������Ҫ��ѯ���������1 - 20 (0 ������):");
    while(scanf("%d",&x) == 1)
    {
        if(x == 0)break;
        switch(x)
        {
            case  1  :printf("%d",x); judge(x); printf("���޵ڶ���У��.\n");break;
            case  2  :printf("%d",x); judge(x); printf("���������ݣ����ھٰ�������ѧ����CUBA���ش�.\n");break;
            case  3  :printf("%d",x); judge(x); printf("�ں����򳡡����򳡡����򳡡����򳡵ȳ���.\n");break;
            case  4  :printf("%d",x); judge(x); printf("���г���ȹ�ͬѧ��ʵϰ��.\n");break;
            case  5  :printf("%d",x); judge(x); printf("�ų�¥����ѧԺ�������빤��ѧԺ���ڽ�ѧ¥\n");break;
            case  6  :printf("%d",x); judge(x); printf("�½���ѧ¥������ʵ���о�.\n");break;
            case  7  :printf("%d",x); judge(x); printf("����¥���Զ���ѧԺ��������ϢѧԺ����е����ѧԺ���ڽ�ѧ¥.\n");break;
            case  8  :printf("%d",x); judge(x); printf("��ͬѧ����ͼ����ϰ�ȳ���.\n");break;
            case  9  :printf("%d",x); judge(x); printf("����һ�󾰵㣬�����������㡱.\n");break;
            case  10  :printf("%d",x); judge(x); printf("УҽԺ�����������շ��ҵ����ڵ�.\n");break;
            case  11  :printf("%d",x); judge(x); printf("�Ų�¥�������ν���.\n");break;
            case  12  :printf("%d",x); judge(x); printf("����¥�������ѧԺ���ڽ�ѧ¥.\n");break;
            case  13  :printf("%d",x); judge(x); printf("����¥�������ѧԺ��ͨ�Ź���ѧԺ�����簲ȫѧԺ���ڽ�ѧ¥.\n");break;
            case  14  :printf("%d",x); judge(x); printf("ѧ������ģ�������ͬѧ��������.\n");break;
            case  15  :printf("%d",x); judge(x); printf("����'����㳡'��ÿ���峿�ɹ��커����ͬѧ�е���������.\n");break;
            case  16  :printf("%d",x); judge(x); printf("�����ν��ҡ�.\n");break;
            case  17  :printf("%d",x); judge(x); printf("׿ԽѧԺ��ѧԺ���ڽ�ѧ¥.\n");break;
            case  18  :printf("%d",x); judge(x); printf("������ͬѧҹ��.\n");break;
            case  19  :printf("%d",x); judge(x); printf("�����ν���.\n");break;
            case  20  :printf("%d",x); judge(x); printf("����ѧԺ�����ڽ�ѧ¥.\n");break;
            default :printf("������������������.\n");
        }
        printf("\n������Ҫ��ѯ���������1 - 20 (0 ������):");
    }
    printf("��������������˵�.\n");
    getch();
}

void Initiate( )        //��ʼ��D[]��P[]�����D[]�ľ���
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

void floyd( )								//���������㷨�����·
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


void path(int x,int y)							//�����㵽�յ��·��
{
    int all=0;
    int m,n;
    printf("���Path: ");
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
    printf("\t\t\t·���ܳ���%d m\n",all);
}



void search( )									//���в�����㵽�յ����
{
    //system("cls");
    int strat,end;
    printf("��ѡ�����ľ���(1-20): ");
    scanf("%d",&strat);
    printf("\n");
    printf("��ѡ���յ�ľ���(1-20): ");
    scanf("%d",&end);
    printf("\n");
    if(strat != end)
    {
        path(strat,end);
        printf("\n");
    }
    else
    {
        printf("������յ���ͬ.\n");
    }
    printf("�����������.\n");
    getch();
}

void door( )
{
    //system("cls");
    int i;
    printf("У�ſڵ�����������·��.\n\n");
    for(i = 2;i <= 20;i ++)
    {
        path(1,i);
        printf("\n");
    }
    printf("�����������.\n");
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
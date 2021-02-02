/*问题说明：
当有车来时，判断进入停车场或者便道
当停车场内某车离开时，后进入的车进入临时停车场让出道路，待该车辆行驶出真正停车场后再依次进入
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAXSIZE 100//假定停车场可停放100辆汽车
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;//返回一个状态

typedef struct Car {
	//定义车辆结构
	int Id;//车牌号
	int ArriveTime;
	int EnterTime = 0;//进入车库时间，初始值为0，未进入车库
	int LeaveTime = 0;//离去的时刻
	struct Car *next;//如果处于停车场内部，指针为空不使用；处于便道，使用指针
}Car, *QueuePtr;

typedef struct {
	//定义链队列结构
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

typedef struct {
	//定义顺序栈结构
	Car data[MAXSIZE];
	int top;
}SqStack;

LinkQueue Q;//定义一个链队列
QueuePtr p;
SqStack S1;//真正停车场
SqStack S2;//临时停车场
int weizhi;//确定离开车辆位置，等于1在停车场，等于0 在便道

Status InitQueue(LinkQueue &Q) {
	//初始化队列
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(Car));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status QueueLength(LinkQueue Q)
{
	QueuePtr p;//定义p指针，用于赋值
	int i = 0;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status InQueue(LinkQueue &Q,int id,int arrivetime) {
	//进队列
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(Car));
	p->Id = id;
	p->ArriveTime =arrivetime;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	printf("该车辆在便道上停车位置为%d号\n", QueueLength(Q));
	return OK;
}

Status OutQueue(LinkQueue &Q) {
	//出队列
	QueuePtr p;
	p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear = p) Q.rear = Q.front;
	return OK;
}
Status InitStack(SqStack &S) {
	//初始化栈
	S.top = -1;
	return OK;
}
Status InStack(SqStack &S1,int id,int arrivetime) {
	//进栈
	if (S1.top == MAXSIZE - 1) return FALSE;
	S1.top++;
	S1.data[S1.top].Id = id;
	S1.data[S1.top].EnterTime = arrivetime;
	printf("该车辆在停车场停车位置为%d号\n", S1.top + 1);
	return OK;
}

int FindLocation(SqStack &S1, LinkQueue Q,int id) {
	QueuePtr p;
	if(S1.data[S1.top].Id == id) {
	    weizhi=1;
	    return 1;
	}
	while (S1.data[S1.top].Id != id) {
		S1.top--;
		if (S1.data[S1.top].Id = id) {
			weizhi = 1;
			return 1;
		}
		if (S1.top == -1) break;//停车场没找到跳出循环
	}

	if(Q.front=Q.rear) {
	    printf("便道为空，该车辆不存在\n");
	    return 1;
	}
	else {
		p = Q.front->next;
		while (p->Id != id) {
			p = p->next;
			if (p == Q.rear) {
				printf("该车辆不存在\n");
				return 1;
			}
		}
	}
	

}
Status OutStack(SqStack &S1, SqStack &S2,int id,int leavetime) {
	//先真移到假停车场
	int resulttime;
	while(S1.data[S1.top].Id != id) {
		S2.top++;
		S2.data[S2.top] = S1.data[S1.top];
		S1.top--;
	}
	S1.data[S1.top].LeaveTime =leavetime;
	resulttime = (S1.data[S1.top].LeaveTime) - (S1.data[S1.top].EnterTime);
	printf("该汽车在停车场内停留时间: %d seconds\n", resulttime);
	printf("应缴纳费用：%d 元\n", resulttime*10);
	S1.top--;//逻辑删除
	//假移到真
	while(S2.top != -1) {
		S1.top++;
		S1.data[S1.top] = S2.data[S2.top];
		S2.top--;
	}
	//自动移入停车场
	if (S1.top < 99 && Q.front != Q.rear) {
		//flag = 0;
		OutQueue(Q);
		id = p->Id;
		InStack(S1,id,leavetime);
		//flag = 1;
	}
	return OK;
}

int main() {
	char order;
	char order1 = 'A';
    char order2 = 'O';
    char order3;
	int id;
	int time;
	int arrivetime;
	int leavetime;
	int flag=1;


	InitQueue(Q);
	InitStack(S1);
	InitStack(S2);
	order3='C';
	while(flag==1){
        printf("请输入将要执行的操作：\n");
        printf("命令格式为（A/O 汽车牌照 到达/离去的时刻)\n");
        scanf("%c%d%d",&order, &id, &time);
        //到达命令
        if (order==order1) {
            arrivetime = time;
            if (S1.top < 99) InStack(S1,id, arrivetime);
            else InQueue(Q,id, arrivetime);
        }
        if (order==order2) {
            leavetime = time;
            FindLocation(S1,Q,id);
            if (weizhi == 1) {
                OutStack(S1,S2,id,leavetime);
            }
            else {
                if (Q.front->next->Id == id)
                    OutQueue(Q);
                else printf("该车辆不是队列第一辆车，无法离开\n");
            }
        }
        printf("如果继续输入命令键入1,离开键入0\n");
        scanf("%d",&flag);


	}
		return OK;
	
}
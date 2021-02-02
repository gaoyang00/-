/*����˵����
���г���ʱ���жϽ���ͣ�������߱��
��ͣ������ĳ���뿪ʱ�������ĳ�������ʱͣ�����ó���·�����ó�����ʻ������ͣ�����������ν���
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAXSIZE 100//�ٶ�ͣ������ͣ��100������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;//����һ��״̬

typedef struct Car {
	//���峵���ṹ
	int Id;//���ƺ�
	int ArriveTime;
	int EnterTime = 0;//���복��ʱ�䣬��ʼֵΪ0��δ���복��
	int LeaveTime = 0;//��ȥ��ʱ��
	struct Car *next;//�������ͣ�����ڲ���ָ��Ϊ�ղ�ʹ�ã����ڱ����ʹ��ָ��
}Car, *QueuePtr;

typedef struct {
	//���������нṹ
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

typedef struct {
	//����˳��ջ�ṹ
	Car data[MAXSIZE];
	int top;
}SqStack;

LinkQueue Q;//����һ��������
QueuePtr p;
SqStack S1;//����ͣ����
SqStack S2;//��ʱͣ����
int weizhi;//ȷ���뿪����λ�ã�����1��ͣ����������0 �ڱ��

Status InitQueue(LinkQueue &Q) {
	//��ʼ������
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(Car));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status QueueLength(LinkQueue Q)
{
	QueuePtr p;//����pָ�룬���ڸ�ֵ
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
	//������
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(Car));
	p->Id = id;
	p->ArriveTime =arrivetime;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	printf("�ó����ڱ����ͣ��λ��Ϊ%d��\n", QueueLength(Q));
	return OK;
}

Status OutQueue(LinkQueue &Q) {
	//������
	QueuePtr p;
	p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear = p) Q.rear = Q.front;
	return OK;
}
Status InitStack(SqStack &S) {
	//��ʼ��ջ
	S.top = -1;
	return OK;
}
Status InStack(SqStack &S1,int id,int arrivetime) {
	//��ջ
	if (S1.top == MAXSIZE - 1) return FALSE;
	S1.top++;
	S1.data[S1.top].Id = id;
	S1.data[S1.top].EnterTime = arrivetime;
	printf("�ó�����ͣ����ͣ��λ��Ϊ%d��\n", S1.top + 1);
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
		if (S1.top == -1) break;//ͣ����û�ҵ�����ѭ��
	}

	if(Q.front=Q.rear) {
	    printf("���Ϊ�գ��ó���������\n");
	    return 1;
	}
	else {
		p = Q.front->next;
		while (p->Id != id) {
			p = p->next;
			if (p == Q.rear) {
				printf("�ó���������\n");
				return 1;
			}
		}
	}
	

}
Status OutStack(SqStack &S1, SqStack &S2,int id,int leavetime) {
	//�����Ƶ���ͣ����
	int resulttime;
	while(S1.data[S1.top].Id != id) {
		S2.top++;
		S2.data[S2.top] = S1.data[S1.top];
		S1.top--;
	}
	S1.data[S1.top].LeaveTime =leavetime;
	resulttime = (S1.data[S1.top].LeaveTime) - (S1.data[S1.top].EnterTime);
	printf("��������ͣ������ͣ��ʱ��: %d seconds\n", resulttime);
	printf("Ӧ���ɷ��ã�%d Ԫ\n", resulttime*10);
	S1.top--;//�߼�ɾ��
	//���Ƶ���
	while(S2.top != -1) {
		S1.top++;
		S1.data[S1.top] = S2.data[S2.top];
		S2.top--;
	}
	//�Զ�����ͣ����
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
        printf("�����뽫Ҫִ�еĲ�����\n");
        printf("�����ʽΪ��A/O �������� ����/��ȥ��ʱ��)\n");
        scanf("%c%d%d",&order, &id, &time);
        //��������
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
                else printf("�ó������Ƕ��е�һ�������޷��뿪\n");
            }
        }
        printf("������������������1,�뿪����0\n");
        scanf("%d",&flag);


	}
		return OK;
	
}
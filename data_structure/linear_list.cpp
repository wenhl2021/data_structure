#include<stdio.h>

#include <stdlib.h>

//����������ṹ

typedef struct Node {
    int data;
    struct Node* next;
}Node;

//���嵥����

typedef Node* LinkList;

//β�巨����������

void CreatList(LinkList* L, int n) {
    LinkList p, r;
    *L = (LinkList)malloc(sizeof(Node)); //ͷ���
    r = *L;                     //rָ������β���,��ʱr�ǵ�һ��Ҳ�����һ��
    printf("����������Ԫ��:\n");
    for (int i = 0; i < n; i++) {
        p = (Node*)malloc(sizeof(Node));          //Ϊ�½�������ڴ�
        scanf_s("%d", &p->data);
        r->next = p;
        r = p;
    }
    r->next = NULL;

}

//�������
void Printlist(LinkList L)
{
    LinkList p;
    p = L->next;  //pָ��L�ĵ�һ�����
    while (p) {
        printf("%d", p->data);
        p = p->next;
    }
}

//�͵�����
void Reverselist(LinkList* L) {
    Node* p, * q;
    if ((*L)->next && (*L)->next->next) {              //������ջ�����ֻ��һ����㣬����Ҫ��ת
        p = (*L)->next;           //�������Ϊ������һ����ͷ����һ������������ʣ�� �����ɵ�����
        q = p->next;
        p->next = NULL;
        while (q) {             //��ͷ�巨���ν��ڶ��������еĽ������һ������
            p = q;
            q = q->next;
            p->next = (*L)->next;
            (*L)->next = p;
        }
    }
}

const int max = 100;

class Seqlist  //����˳���Ĳ������
{
public:
    Seqlist();
    ~Seqlist();
    int find(Seqlist L, int x) {};
    void insert(Seqlist& L, int x);
    int length = -1;
    int data[];
};

int Seqlist::find(Seqlist L, int x)  //Ѱ��λ��
{
    int i;
    for (i = 0; i < L.length; ++i) {
        if (x < L.data[i]) {
            return i;
        }
    }
    return i;
}

void Seqlist::insert(Seqlist& L, int x)  //����λ�ã���������Ԫ�غ���һ����λ
{
    int p, i;
    p = find(L, x);
    for (i = L.length - 1; i >= p; --i)
        L.data[i + 1] = L.data[i];
    L.data[p] = x;
    L.length++;
}
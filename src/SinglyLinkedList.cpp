#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d){data=d;next=NULL;}
};

class NodeList
{
private:
    Node* node;
public:
    NodeList();
    ~NodeList();
    void clear();
    bool empty();
    int size();
    void print();
    int get(int pos);
    void insert(int pos, int d);
    int remove(int pos);
    void push_front(int d);
    void push_back(int d);
};

NodeList::NodeList():node(NULL)
{
}

NodeList::~NodeList()
{
    clear();
}

//清空链表 
void NodeList::clear()
{
    cout<<"清空链表"<<endl;
    if (node == NULL)
    {
        return ;
    }
    else
    {
        //这里要讲node链表赋NULL，所以要取指针 
        Node** p = &(node->next);
        while (*p != NULL)
        {
            Node* pNext = (*p)->next;
            delete *p;
            *p = NULL;
            *p = pNext;
        }
        delete node;
        node = NULL;
    }
}

//判断链表是否为空 
bool NodeList::empty()
{
    return node == NULL;
}

//返回链表长度 
int NodeList::size()
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int count = 1;
        Node* p = node;
        while(p->next != NULL)
        {
            ++count;
            p = p->next;
        }
        return count;
    }
}

//打印链表数据 
void NodeList::print()
{
    cout<<"输出链表：";
    if (node == NULL)
    {
        return ;
    }
    else
    {
        Node* p = node;
        while(p != NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }
    cout<<endl;
}

//获取链表位置为pos的数据 
int NodeList::get(int pos)
{
    cout<<"获取位置为"<<pos<<"的数据 ";
    if (pos < 1)
    {
        cout<<"pos值非法"<<endl;
        return 0;
    }
    if (node == NULL)
    {
        cout<<"链表为空"<<endl;
        return 0;
    }
    int index = 0;
    Node* p = node;
    while (p != NULL)
    {
        ++index;
        if (index == pos)
        {
            break;
        }
        else
        {
            p = p->next;
        }
    }
    if (index < pos)
    {
        cout<<"链表长度不足"<<pos<<endl;
        return 0;
    }
    cout<<"位置为"<<pos<<"的数据为："<<p->data<<endl;
    return p->data;    
}

//位置为pos的链表节点插入数据 
void NodeList::insert(int pos, int d)
{
    cout<<"位置为"<<pos<<"插入数据"<<d<<" ";
    if (pos < 1)
    {
        cout<<"pos值非法"<<endl;
        return ;
    }
    if (node == NULL)
    {
        cout<<"链表为空"<<endl;
        return ;
    }
    int ret = 0;
    if (pos == 1)
    {
        Node* pNode = new Node(d);
        pNode->next = node;
        node = pNode;
    }
    else
    {
        Node* previous = node;
        Node* current = node;
        int index = 0;
        while (current != NULL)
        {
            ++index;
            if (index == pos)
            {
                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (index < pos)
        {
            cout<<"链表长度不足"<<pos<<endl;
            return ;
        }
        else
        {
            Node* pNode = new Node(d);
            previous->next = pNode;
            pNode->next = current;
        }
    }
}

//移除位置为pos的链表节点
int NodeList::remove(int pos)
{
    cout<<"移除位置为"<<pos<<"的数据 ";
    if (pos < 1)
    {
        cout<<"pos值非法"<<endl;
        return 0;
    }
    if (node == NULL)
    {
        cout<<"链表为空"<<endl;
        return 0;
    }
    int ret = 0;
    if (pos == 1)
    {
        Node* pFirst = node;
        node = node->next;
        ret = pFirst->data;
        delete pFirst;
        pFirst = NULL;
    }
    else
    {
        Node* previous = node;
        Node* current = node;
        int index = 0;
        while (current != NULL)
        {
            ++index;
            if (index == pos)
            {
                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (index < pos)
        {
            cout<<"链表长度不足"<<pos<<endl;
            return 0;
        }
        else
        {
            previous->next = current->next;
            ret = current->data;
            delete current;
            current = NULL;
        }
    }
    return ret;
}

//链表头插入数据 
void NodeList::push_front(int d)
{
    Node* pNode = new Node(d);
    if (node == NULL)
    {
        node = pNode;
        return ;
    }
    else
    {
        pNode->next = node;
        node = pNode;
        cout<<"链表头插入"<<pNode->data<<endl;
        return ;
    }
}

//链表尾插入数据 
void NodeList::push_back(int d)
{
    Node* pNode = new Node(d);
    if (node == NULL)
    {
        node = pNode;
        return ;
    }
    else
    {
        Node* p = node;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = pNode;
        cout<<"链表尾插入"<<pNode->data<<endl;
        return ;
    }
}

int main()
{
    NodeList* pNodeList = new NodeList;
    bool empty = pNodeList->empty();
    int size = pNodeList->size();
    
    pNodeList->push_back(3);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->push_front(5);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->push_front(8);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->remove(2);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->insert(2, 7);
    pNodeList->print();
    pNodeList->get(2);
    
    pNodeList->clear();
    pNodeList->print();
    pNodeList->get(2);
    
    system("pause");
    return 0;
}

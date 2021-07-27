#include<bits/stdc++.h>
using namespace std;
#define N 5
class Queue{
    int arr[N];
    int front;
    int rear;
public:
    Queue()
    {
        front=rear=-1;
    }
    bool isFull();
    bool isEmpty();
    int peek();
    void enqueue(int);
    int dequeue();
    void display();
};

bool Queue::isFull()
{
    if((rear+1)%N==front)
    {
        cout << "Queue is FULL!!!\n";
        return true;
    }
    return false;
}

bool Queue::isEmpty()
{
    if(front==-1 && rear==-1)
    {
        cout << "Queue is Empty!!!\n";
        return true;
    } 
    return false;
}

int Queue::peek()
{
    if(isEmpty())
        return -1;
    return arr[front];
}

void Queue::enqueue(int x)
{
    if(isFull())
        return;
    if(front==-1 && rear==-1)
        front=rear=0;
    else
        rear=(rear+1)%N;
    arr[rear]=x;
}

int Queue::dequeue()
{
    if(isEmpty()) 
        return -1;
    int x=arr[front];
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%N;
    return x;
}


void Queue::display()
{
    int i=front-1;
    do{
        i=(i+1)%N;
        cout << arr[i] << " ";
    }while(i!=rear);
}

int main()
{
    Queue* obj=new Queue();
    cout << "Queue Implementation using Arrays--> \n";
    int n;
    while(cin >> n)
    {
        if(n==1)
        {
            int x;
            cout << "Enqueue-> ";
            cin >> x;
            obj->enqueue(x);
        }
        else if(n==2)
        {
            cout << "Dequeue--> " << obj->dequeue() << endl;
        }
        else if(n==3)
            cout << "Peek--> " << obj->peek() << endl;
        else if(n==4)
        {
            cout << "Display--> ";
            obj->display();
            cout << endl;
        }
        else
            cout << "Enter another Key-->\n";        
    }
    return 0;
}
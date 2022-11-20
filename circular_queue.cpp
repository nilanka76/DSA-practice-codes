#include<iostream>

using namespace std;
class Cqueue{
    int *arr;
    int rear, front, size ;
public:
    Cqueue(int n){
        front = rear = -1;
        size = n;
        arr = new int[n];
    }
    void enqueue(int val){
        if ((front == 0 && rear == size - 1) || (rear == (front - 1)%(size-1))){
            cout<<"Queue is full "<< endl;
            return;
        }
        else if (front == -1){
            front = rear = 0;
            arr[rear] = val;
        }
        else if (rear == size-1 && front !=0){
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }
    void dequeue(){
        if (front == -1){
            cout<<"empty"<<endl;
            return ;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1){
            front = 0;
        }
        else front ++;
    return;
    }
    void display(){
        if (front == -1){
            printf("\nQueue is Empty");
            return;
        }
        if (rear >= front){
            for(int i = front; i <= rear; i++){
                cout<<arr[i]<<endl;
            }
        }
        else{
            for (int i = front; i < size; i++)
                printf("%d ", arr[i]);
  
            for (int i = 0; i <= rear; i++)
                printf("%d ", arr[i]);
        }
    }
};

int main(){
    Cqueue q(5);
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);

    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(100);
    q.enqueue(10);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}

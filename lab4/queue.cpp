#include<iostream>
using namespace std;
#define MAX 5
template <class T>
class Queue {
private:
    T q[MAX];
    int f = -1, r = -1;
public:
    void enqueue(T item) {
        if (r == MAX - 1) {
            cout << "Queue overflow!" << endl;
            return;
        }
        if (f == -1 && r == -1) {
            f = 0;
            r = 0;
        } else {
            r += 1;
        }
        q[r] = item;
    }
    T dequeue() {
        if (f == -1 || f > r) {
            cout << "Queue is empty" << endl;
            return 0;
        } else {
            T item = q[f];
            f += 1;
            return item;
        }
    }
    void display(){
        for(int j =f;j<=r;j++)
        {
            cout<<q[j]<<"\t";
        }
    }
};
int main() {
    Queue<int> a;
    int choice;
    while(1){ 
    cout << "Press 1 to enqueue"<<endl<<"Press 2 to dequeue"<<endl<<"Press 3 to display:";
    cin >> choice;
    switch (choice) {
    case 1:
        int i;
        cout << "Enter number to enqueue: ";
        cin >> i;
        a.enqueue(i);
        break;

    case 2:
        cout << a.dequeue() << " removed." << endl;
        break;
    case 3:
        cout<<" Queue is: ";
        a.display();
        cout<<endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 0;
    }
    }
}

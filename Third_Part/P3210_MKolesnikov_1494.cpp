#include <iostream>

using namespace std;

class Stack{
public:
    int st_pointer;
    int* st_buffer;

    Stack(int size){
        this->st_buffer = new int [size];
        this->st_pointer = - 1;
    }

    void push(int element){
        st_buffer[++st_pointer] = element;
    }

    int pop(){
        if (st_pointer < 0)
            return -1;
        else
            return st_buffer[st_pointer--];
    }
};

int main() {
    int size;
    cin >> size;
    Stack stack (size);
    int start_point = 0;
    cin >> start_point;
    for (int k = 1; k < start_point; ++k) {
        stack.push(k);
    }
    for (int i = 1; i < size ; ++i) {
        int ball;
        cin >> ball;
        if (ball > start_point){
            for (int j = start_point + 1; j < ball; j++) {
                stack.push(j);
            }
            start_point = ball;
            continue;
        } else if (stack.pop() != ball){
            cout << ("Cheater") << endl;
            return 0;
        }
    }
    cout << "Not a proof" << endl;
    return 0;
}

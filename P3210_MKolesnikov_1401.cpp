#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


class Logic {
private:
    int k ;
    int** arr;
    int size;
    void logic(int row,int col,int x,int y,int size){
        if(size == 2){
            make_angle(row + x%2,col + y%2);
            return;
        }
        int size_block = size/2;
        if(x < size_block && y< size_block ){
            logic(row,col,x,y,size_block);
            logic(row+size_block,col,0,size_block-1,size_block);
            logic(row,col+size_block,size_block-1,0,size_block);
            logic(row+size_block,col+size_block,0,0,size_block);
            arr[row+size_block][col+size_block] =
                    arr[row+size_block-1][col+size_block] =
                            arr[row+size_block][col+size_block-1]=k++;
        } else if (x >= size_block && y < size_block){
            logic(row+size_block,col,x-size_block,y,size_block);
            logic(row,col,size_block-1,size_block-1,size_block);
            logic(row,col+size_block,size_block-1,0,size_block);
            logic(row + size_block,col+size_block,0,0,size_block);
            arr[row+size_block-1][col+size_block-1] =
                    arr[row+size_block-1][col+size_block]=
                            arr[row+size_block][col+size_block] = k++;
        } else if (x < size_block && y >= size_block){
            logic(row,col+size_block,x,y-size_block,size_block);
            logic(row,col,size_block-1,size_block-1,size_block);
            logic(row+size_block,col,0,size_block-1,size_block);
            logic(row+size_block,col+size_block,0,0,size_block);
            arr[row+size_block-1][col+size_block-1] =
                    arr[row+size_block][col+size_block-1]=
                            arr[row+size_block][col+size_block] = k++;
        } else{
            logic(row+size_block,col+size_block,x-size_block,y-size_block,size_block);
            logic(row,col,size_block-1,size_block-1,size_block);
            logic(row+size_block,col,0,size_block-1,size_block);
            logic(row,col+size_block,size_block-1,0,size_block);
            arr[row+size_block][col+size_block-1] =
                    arr[row + size_block-1][col+size_block-1]=
                            arr[row+size_block-1][col+size_block] = k++;
        }
    }
    void make_angle(int x,int y){
        int miss_x = x%2;
        int miss_y = y%2;
        if(miss_x == 0 && miss_y == 0){
            arr[x+1][y] = arr [x+1][y+1] = arr[x][y+1] = k++;
        } else if (miss_x == 0 && miss_y == 1){
            arr[x+1][y] = arr[x][y-1] = arr[x+1][y-1] = k++;
        } else if (miss_x == 1 && miss_y == 0){
            arr[x][y+1] = arr[x-1][y] = arr[x-1][y+1] = k++;
        } else{
            arr[x][y-1] = arr[x-1][y-1] = arr[x-1][y] = k++;
        }
    }
public:
    Logic(int** arr,int size){
        this->arr = arr;
        this->size = size;
        k = 1;
    }
    void start(int x, int y){
        logic(0,0,x-1,y-1,size);
    }
    void print(){
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n , x,y;
    cin >> n >> x >> y;
    int pow= 1 << n;
    int ** arr = new int*[pow];
    for(int i = 0 ; i < pow;i++){
        arr[i] = new int [pow];
        for(int j = 0 ; j < pow;j++){
            arr[i][j] = 0;
        }
    }
    Logic logic(arr,pow);
    logic.start(x,y);
    logic.print();
}

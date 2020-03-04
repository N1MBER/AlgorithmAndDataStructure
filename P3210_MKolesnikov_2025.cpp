#include <iostream>

using namespace std;

int main() {
    int test;//Количество тестов
    cin >> test;//Воод кол-ва
    for (int i = 0; i < test; ++i)	{
        int n,  k;
        cin >> n >> k;
        int peopleInCommand = n / k;	//Гарантированное количество человек в одной команде
        int peopleWithoutCommand = n % k;	// Не поделившиеся
        int peopleInFullCommand = peopleInCommand + 1; //Максимальное кол-во человек в команде
        int result = (peopleInCommand*(n - peopleInCommand)*(k - peopleWithoutCommand)  + peopleInFullCommand*(n- peopleInFullCommand)*(peopleWithoutCommand) )/2;//расчет
        cout << result << endl;
    }

    return 0;
}

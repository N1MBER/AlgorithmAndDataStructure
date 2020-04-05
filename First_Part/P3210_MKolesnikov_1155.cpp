#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void delete_section(int* const a, int* const b, string msg) {
    cout << msg << endl;
    (*a)--; (*b)--;
}

int main() {
    int A, B, C, D, E, F, G, H;
    cin >> A >> B >> C >> D >> E >> F >> G >> H;
    if ((E + D + B + G) != (A + C + F + H)) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        while (E + D + B + G > 0) {
            if (E > 0) {
                if (F > 0) {
                    delete_section(&E, &F, "EF-");
                }
                else if (A > 0) {
                    delete_section(&E, &A, "EA-");
                }
                else if (H > 0)  {
                    delete_section(&E, &H, "EH-");
                }
                else if (C > 0) {
                    E--;
                    C--;
                    cout << "FB+" << endl << "EF-" << endl << "CB-" << endl;
                }
            }
            if (D > 0) {
                if (A > 0){
                    delete_section(&D, &A, "DA-");
                }
                else if (C > 0) {
                    delete_section(&D, &C, "DC-");
                }
                else if (H > 0) {
                    delete_section(&D, &H, "DH-");
                }
                else if (F > 0) {
                    D--;
                    F--;
                    cout << "EA+" << endl << "FE-" << endl << "DA-" << endl;
                }
            }
            if (B > 0) {
                if (A > 0){
                    delete_section(&B, &A, "BA-");
                }
                else if (C > 0) {
                    delete_section(&B, &C, "BC-");
                }
                else if (F > 0) {
                    delete_section(&B, &F, "BF-");
                }
                else if (H > 0) {
                    B--;
                    H--;
                    cout << "EA+" << endl << "BA-" << endl << "EH-" << endl;
                }
            }
            if (G > 0) {
                if (H > 0) {
                    delete_section(&G, &H, "GH-");
                }
                else if (C > 0){
                    delete_section(&G, &C, "GC-");
                }
                else if (F > 0) {
                    delete_section(&G, &F, "GF-");
                }
                else if (A > 0) {
                    G--;
                    A--;
                    cout << "FB+" << endl << "GF-" << endl << "AB-" << endl;
                }
            }
        }
    }
    return 0;
}

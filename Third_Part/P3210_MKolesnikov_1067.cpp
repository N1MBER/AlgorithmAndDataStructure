#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

struct Catalog {
    map<string, Catalog*> directories;
};

void print_result(Catalog* pCatalog, const string& tabs);

Catalog roots[10000];

int root = 1;
int n;

Catalog* get_new_Catalog(Catalog* parent, const string& child_name);

int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string path;
        string directory;
        cin >> path;
        stringstream stringstreamer(path);
        Catalog* element = &roots[0];
        
        while (getline(stringstreamer, directory, '\\')) {
            element = get_new_Catalog(element, directory);
        }
    }

    print_result(&roots[0], "");
}

void print_result(Catalog* pCatalog, const string& tabs = ""){
    for (const auto& root_Catalog : pCatalog->directories){
        cout << tabs << root_Catalog.first << endl;
        print_result(root_Catalog.second, tabs + " ");
    }
}

Catalog* get_new_Catalog(Catalog* parent, const string& child_name){
    auto& d = parent->directories[child_name];
    if (!d) {
        d = &roots[root++];
        return d;
    } else
        return d;
}
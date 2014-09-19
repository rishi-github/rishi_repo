#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    unordered_map <string, int> m;
    m["foo"] = 42;
    m["foo"]=43;
    cout << m["foo"] << endl;
}

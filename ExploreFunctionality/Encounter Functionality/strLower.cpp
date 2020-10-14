

#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
string strLower(string n);
string strLower(string n) {
for (size_t i=0;i<n.size();i++){
    n[i] = tolower(n[i]);
    }
    return n;
}

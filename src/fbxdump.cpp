#include <stdint.h>
#include <iostream>
#include <string>
#include <chrono>

#include "fbxdocument.h"
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using namespace fbx;

bool findNode(const std::string name, FBXNode where) {
    if(where.getName() == name) {
        where.printAll();
        return true;
    }
    for(FBXNode n : where.getChildren()) {
        if(findNode(name, n)) {
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    try {
        fbx::FBXDocument doc;
        std::string jsonPath = doc.readFBXwriteJsonFiltered("fbx/SM_Kronshtadtskij_Bulvar_Ground.fbx");
        std::cout << "json path = " << jsonPath << std::endl;

    } catch(string s) {
        cerr << "ERROR: " << s << endl;
        return 2;
    }

    return 0;
}

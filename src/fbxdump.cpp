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
    // auto start = std::chrono::high_resolution_clock::now();

    // if(argc < 2) {
    //     cerr << "Specify file which you want to dump" << endl;
    //     return 1;
    // }

    try {
        fbx::FBXDocument doc;
        // doc.read(argv[1]);
        // doc.read("fbx/SM_VolokolamskoeShosse_106_Ground.fbx");
        // doc.read("fbx/test_object_boxes_01.fbx");
        // doc.read("fbx/test_object_boxes_02.fbx");

        // doc.read("fbx/SM_Lyublinskaya_ZU_111_3.fbx");
        doc.read("fbx/SM_Kronshtadtskij_Bulvar_Ground.fbx");
        // doc.read("fbx/SM_Kronshtadtskij_Bulvar_Ground_replaced.fbx");
        // doc.read("fbx/SM_Kronshtadtskij_Bulvar_Ground_bin_test.fbx");
        // doc.read("fbx/SM_Stavropolskaya_Vld_4_K_2_001.fbx");
        // doc.read("fbx/SM_Stavropolskaya_Vld_4_K_2_Ground.fbx");
        if(argc > 2) {
            for(auto n : doc.nodes) {
                if(findNode(argv[2], n)) break;
            }
        } else {
            // doc.printAllNodes();
            doc.printSomeNodes();
        }

    } catch(string s) {
        cerr << "ERROR: " << s << endl;
        return 2;
    }

    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cout << "Время выполнения: " << elapsed.count() << " секунд" << std::endl;

    return 0;
}

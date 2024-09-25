#ifndef FBXDOCUMENT_H
#define FBXDOCUMENT_H

#include "fbxnode.h"

namespace fbx {

class FBXDocument
{
public:
    FBXDocument();

    /* @brief
    Facade method: read FBX file, write Json filtered and return path to Json
    */
    std::string readFBXwriteJsonFiltered(const std::string fbxPath);

    void read(std::ifstream &input);
    void read(std::string fname);
    void write(std::string fname);
    void write(std::ofstream &output);

    void createBasicStructure();

    std::uint32_t getVersion();
    const std::vector<FBXNode> &getNodes() const;

    /* @brief
    Prints full fbx file.
    */
    void printAllNodes();

    /* @brief
    Prints fbx file with filters.
    */
    void printSomeNodes();
    
    /* @brief
    Writes fbx file with filters to json file.
    */
    void writeSomeNodesJson(const std::string pathToJson);

private:
    std::string trimPathFbxToJson(const std::string &pathToFbx);

    std::vector<FBXNode> nodes;
    std::uint32_t version;
};

} // namespace fbx

#endif // FBXDOCUMENT_H

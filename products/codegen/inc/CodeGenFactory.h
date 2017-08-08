/*
    CodeGenFactory.h
*/

#pragma once
#include <vector>
#include <string>

namespace cbtek {
namespace products {
namespace codegen {


class CodeGenFactory
{

public:
    /**
     * @brief create
     * @param generator
     * @param type
     * @param outputPath
     */
    static void create(const std::string &name,
                       const std::string& generator,
                       const std::string& type,
                       const std::string& outputPath);

private:
    /**
     * @brief createCode
     * @param type
     * @param outputPath
     */
    static void createCode(const std::string &name,
                           const std::string& type,
                           const std::string& outputPath,
                           bool seperateIncSrc = true);

    /**
     * @brief createProject
     * @param type
     * @param outputPath
     */
    static void createProject(const std::string &name,
                              const std::string& type,
                              const std::string& outputPath);
};

}}} //namespace

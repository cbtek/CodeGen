/*
    CodeGenUtils.h
    

*/
#pragma once
#include <vector>
#include <string>

namespace cbtek {
namespace products {
namespace codegen {


class CodeGenUtils
{
public:
    static void generateLibraries(const std::vector<std::string>& dependLibs,
                                  const std::vector<std::string>& linkLibs,
                                  std::ostream& out);

    static void generateDirectories(const std::string& projectName,
                                    const std::string& path, const std::vector<std::string> &dirs);
private:
    //! Private constructor for CodeGenUtils
    CodeGenUtils();

    //! Private copy constructor for CodeGenUtils
    CodeGenUtils(const CodeGenUtils &);

    //! Private destructor for CodeGenUtils
    ~CodeGenUtils();
};
}}}//end namespace

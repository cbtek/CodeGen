/*
    CodeGenUtils.h   
*/
#pragma once
#include <vector>
#include <string>

#include "CodeTemplate.hpp"
#include "ProjectTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {

class CodeGenUtils
{
public:

    /**
     * @brief printSupportedProjectTemplates
     * @param out
     */
    static void printSupportedProjectTemplates(std::ostream& out);

    /**
     * @brief printSupportedCodeTemplates
     * @param out
     */
    static void printSupportedCodeTemplates(std::ostream& out);

    /**
     * @brief getCodeTemplateTypeFromStr
     * @param codeTemplateStr
     * @return
     */
    static CodeTemplateType getCodeTemplateTypeFromStr(const std::string& codeTemplateStr);

    /**
     * @brief getStringFromCodeTemplate
     * @param codeTemplateType
     * @return
     */
    static std::string getStringFromCodeTemplate(CodeTemplateType codeTemplateType);

    /**
     * @brief getProjectTemplateTypeFromStr
     * @param projectTemplateStr
     * @return
     */
    static ProjectTemplateType getProjectTemplateTypeFromStr(const std::string& projectTemplateStr);

    /**
     * @brief getStringFromProjectTemplate
     * @param projectTemplatetype
     * @return
     */
    static std::string getStringFromProjectTemplate(ProjectTemplateType projectTemplatetype);

    /**
     * @brief generateLibraries
     * @param dependLibs
     * @param linkLibs
     * @param out
     */
    static void generateLibraries(const std::vector<std::string>& dependLibs,
                                  const std::vector<std::string>& linkLibs,
                                  std::ostream& out);

    /**
     * @brief generateDirectories
     * @param projectName
     * @param path
     * @param dirs
     */
    static void generateDirectories(const std::string& projectName,
                                    const std::string& path, const std::vector<std::string> &dirs);

    /**
     * @brief getDoxygenClassHeader
     * @param className
     * @param headerOnly
     * @return
     */
    static std::string getDoxygenClassHeader(const std::string& className, bool headerOnly=false);

    /**
     * @brief generateDoxygenMethodHeader
     * @param functionName
     * @param returnType
     * @param params
     */
    static void generateDoxygenMethodHeader(const std::string& functionName,
                                            const std::string& returnType,
                                            const std::vector<std::string>& params);

    /**
     * @brief generateNamespaceOpenCode
     * @param out
     * @param namespaceList
     */
    static void generateNamespaceOpen(std::ostream& out,
                                      const std::vector<std::string>& namespaceList);

    /**
     * @brief generateNamespaceCloseCode
     * @param out
     * @param namespaceList
     */
    static void generateNamespaceClose(std::ostream& out,
                                       const std::vector<std::string>& namespaceList);

    /**
     * @brief generateNamespaceResolutionCode
     * @param out
     * @param namespacelist
     */
    static void generateNamespaceResolutionCode(std::ostream& out,
                                                const std::vector<std::string>& namespacelist);

    /**
     * @brief generateClassIncludeMethods
     * @param out
     * @param methodReturnTypes
     * @param methodNames
     * @param methodParams
     */
    static void generateClassDefinitionMethods(std::ostream& out,
                                               const std::vector<std::string>& methodReturnTypes,
                                               const std::vector<std::string>& methodNames,
                                               const std::vector<std::vector<std::string> >& methodParams);

    /**
     * @brief generateClassImplementationMethods
     * @param out
     * @param methodReturnTypes
     * @param methodNames
     * @param methodParams
     */
    static void generateClassImplementationMethods(std::ostream& out,
                                                   const std::vector<std::string>& methodReturnTypes,
                                                   const std::vector<std::string>& methodNames,
                                                   const std::vector<std::vector<std::string> >& methodParams);
private:
    //! Private constructor for CodeGenUtils
    CodeGenUtils();

    //! Private copy constructor for CodeGenUtils
    CodeGenUtils(const CodeGenUtils &);

    //! Private destructor for CodeGenUtils
    ~CodeGenUtils();
};
}}}//end namespace

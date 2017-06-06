/*
    CodeTemplate.hpp
    

*/
#pragma once

#include <string>
#include <vector>

namespace cbtek {
namespace products {
namespace codegen {

enum class CodeTemplateType
{
    //C++ class types
    BasicClass,
    VirtualClass,
    SingletonClass,
    StaticClass,
    TemplateClass,
    EnumClass,

    //Custom CBTek class types
    CBGameClass,
    RStatsModuleUIClass,
    CodeTemplateClass,
    ProjectTemplateClass,

    //Qt Related class types
    QMainWindowClass,
    QDialogClass,
    QWidgetClass,

    //Entry-Points (mains)
    MainEntryPoint,
    QtMainEntryPoint,
    CBGameEntryPoint,
};

class CodeTemplate 
{
public:

    /**
     * @brief createCode
     * @param name
     * @param rootFolderIncPath
     * @param rootFolderSrcPath
     */
    virtual void createCode(const std::string& name,
                            const std::string& rootFolderIncPath,
                            const std::string& rootFolderSrcPath) = 0;


    /**
     * @brief getType
     * @return
     */
    virtual CodeTemplateType getType() const = 0;

    /**	
    * @brief Virtual descructor for CodeTemplate
    *
	*/	
    virtual ~CodeTemplate(){}
};
}}}//end namespace

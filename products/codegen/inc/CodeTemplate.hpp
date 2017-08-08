/*
    CodeTemplate.hpp
    

*/
#pragma once

#include <string>
#include <vector>
#include <memory>

#include "utility/inc/Exception.hpp"

namespace cbtek {
namespace products {
namespace codegen {

enum class CodeTemplateType
{
    //C++ class types
    BasicClass = 0,
    VirtualClass,
    SingletonClass,
    StaticClass,
    TemplateClass,
    EnumClass,

    //Custom CBTek class types
    CBGameClass,
    RStatsModuleUIClass,        
    CodeGenCodeTemplateClass,
    CodeGenProjectTemplateClass,

    //Qt Related class types
    QMainWindowClass,
    QDialogClass,
    QWidgetClass,

    //Entry-Points (mains)
    MainEntryPoint,
    QtMainEntryPoint,
    CBGameEntryPoint,
    Invalid
};


class CodeTemplate 
{
public:

    /**
     * @brief createCode Calls the derived class method for generating source
     * code in the rootFolderIncPath and rootFolderSrcPath.
     * @param name The name of the class to generate
     * @param rootFolderIncPath The output location of the .h/.hpp file
     * @param rootFolderSrcPath The output location of the .cpp/.cxx/.c file
     */
    virtual void createCode(const std::string& name,
                            const std::string& rootFolderIncPath,
                            const std::string& rootFolderSrcPath) = 0;

    /**
     * @brief getType Returns the type associated with the derived class
     * @return
     */
    virtual CodeTemplateType getType() const = 0;

    /**	
    * @brief Virtual descructor for CodeTemplate
    *
	*/	
    virtual ~CodeTemplate(){}
};

typedef std::shared_ptr<CodeTemplate> CodeTemplatePtr;

}}}//end namespace

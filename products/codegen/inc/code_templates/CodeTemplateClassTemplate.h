/*
    CodeTemplateClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class CodeTemplateClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief CodeTemplateClassTemplate
    *
	*/
	CodeTemplateClassTemplate();
    
    /**
     * @brief createCode
     * @param name
     * @param rootFolderIncPath
     * @param rootFolderSrcPath
     */
    virtual void createCode(const std::string& name,
                            const std::string& rootFolderIncPath,
                            const std::string& rootFolderSrcPath);


    /**
     * @brief getType
     * @return
     */
    virtual CodeTemplateType getType() const;

    /**
	 * @brief CodeTemplateClassTemplate (Descructor)
     *
	 */
	~CodeTemplateClassTemplate();	

private:
    
};
}}}}//end namespace


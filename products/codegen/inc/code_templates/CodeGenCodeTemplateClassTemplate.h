/*
    CodeGenCodeTemplateClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class CodeGenCodeTemplateClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief CodeGenCodeTemplateClassTemplate
    *
	*/
	CodeGenCodeTemplateClassTemplate();
    
    /**
     * @see CodeTemplate::createCode
     */
    virtual void createCode(const std::string& name,
                            const std::string& rootFolderIncPath,
                            const std::string& rootFolderSrcPath);

    /**
     * @see CodeTemplate::getType
     */
    virtual CodeTemplateType getType() const;

    /**
	 * @brief CodeGenCodeTemplateClassTemplate (Descructor)
     *
	 */
	~CodeGenCodeTemplateClassTemplate();	

private:
    
};
}}}}//end namespace


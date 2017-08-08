/*
    CodeGenProjectTemplateClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class CodeGenProjectTemplateClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief CodeGenProjectTemplateClassTemplate
    *
	*/
	CodeGenProjectTemplateClassTemplate();
    
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

	/*
	 * @brief CodeGenProjectTemplateClassTemplate (Descructor)
     *
	 */
	~CodeGenProjectTemplateClassTemplate();	

private:
    
};
}}}}//end namespace


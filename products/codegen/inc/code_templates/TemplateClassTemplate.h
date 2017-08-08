/*
    TemplateClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class TemplateClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief TemplateClassTemplate
    *
	*/
	TemplateClassTemplate();
    
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
	 * @brief TemplateClassTemplate (Descructor)
     *
	 */
	~TemplateClassTemplate();	

private:
    
};
}}}}//end namespace


/*
    EnumClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class EnumClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief EnumClassTemplate
    *
	*/
	EnumClassTemplate();
    
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
	 * @brief EnumClassTemplate (Descructor)
     *
	 */
	~EnumClassTemplate();	

private:
    
};
}}}}//end namespace


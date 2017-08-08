/*
    VirtualClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class VirtualClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief VirtualClassTemplate
    *
	*/
	VirtualClassTemplate();
    
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
	 * @brief VirtualClassTemplate (Descructor)
     *
	 */
	~VirtualClassTemplate();	

private:
    
};
}}}}//end namespace


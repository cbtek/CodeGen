/*
    CBGameClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class CBGameClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief CBGameClassTemplate
    *
	*/
	CBGameClassTemplate();
    
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
     *
	 * @brief CBGameClassTemplate (Descructor)
     *
	 */
	~CBGameClassTemplate();	

private:
    
};
}}}}//end namespace


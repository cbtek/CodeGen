/*
    CBGameEntryPointTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class CBGameEntryPointTemplate :public CodeTemplate
{
public:
   /*
    * @brief CBGameEntryPointTemplate
    *
	*/
	CBGameEntryPointTemplate();
    
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
	 * @brief CBGameEntryPointTemplate (Descructor)
     *
	 */
	~CBGameEntryPointTemplate();	

private:
    
};
}}}}//end namespace


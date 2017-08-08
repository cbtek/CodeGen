/*
    StaticClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class StaticClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief StaticClassTemplate
    *
	*/
	StaticClassTemplate();
    
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
	 * @brief StaticClassTemplate (Descructor)
     *
	 */
	~StaticClassTemplate();	

private:
    
};
}}}}//end namespace


/*
    SingletonClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class SingletonClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief SingletonClassTemplate
    *
	*/
	SingletonClassTemplate();
    
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
	 * @brief SingletonClassTemplate (Descructor)
     *
	 */
	~SingletonClassTemplate();	

private:
    
};
}}}}//end namespace


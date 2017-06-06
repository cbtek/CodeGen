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
	 * @brief EnumClassTemplate (Descructor)
     *
	 */
	~EnumClassTemplate();	

private:
    
};
}}}}//end namespace


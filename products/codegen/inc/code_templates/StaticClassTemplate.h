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

	/*
	 * @brief StaticClassTemplate (Descructor)
     *
	 */
	~StaticClassTemplate();	

private:
    
};
}}}}//end namespace

/*
    MainEntryPointTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class MainEntryPointTemplate :public CodeTemplate
{
public:
   /*
    * @brief MainEntryPointTemplate
    *
	*/
	MainEntryPointTemplate();
    
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
	 * @brief MainEntryPointTemplate (Descructor)
     *
	 */
	~MainEntryPointTemplate();	

private:
    
};
}}}}//end namespace


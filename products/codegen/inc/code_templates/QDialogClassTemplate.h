/*
    QDialogClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class QDialogClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief QDialogClassTemplate
    *
	*/
	QDialogClassTemplate();
    
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
	 * @brief QDialogClassTemplate (Descructor)
     *
	 */
	~QDialogClassTemplate();	

private:
    
};
}}}}//end namespace


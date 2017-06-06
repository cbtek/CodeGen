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
	 * @brief QDialogClassTemplate (Descructor)
     *
	 */
	~QDialogClassTemplate();	

private:
    
};
}}}}//end namespace


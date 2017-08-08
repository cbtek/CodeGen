/*
    QMainWindowClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class QMainWindowClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief QMainWindowClassTemplate
    *
	*/
	QMainWindowClassTemplate();
    
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
	 * @brief QMainWindowClassTemplate (Descructor)
     *
	 */
	~QMainWindowClassTemplate();	

private:
    
};
}}}}//end namespace


/*
    QWidgetClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class QWidgetClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief QWidgetClassTemplate
    *
	*/
	QWidgetClassTemplate();
    
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
	 * @brief QWidgetClassTemplate (Descructor)
     *
	 */
	~QWidgetClassTemplate();	

private:
    
};
}}}}//end namespace


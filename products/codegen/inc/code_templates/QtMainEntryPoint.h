/*
    QtMainEntryPoint.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class QtMainEntryPoint :public CodeTemplate
{
public:
   /*
    * @brief QtMainEntryPoint
    *
	*/
	QtMainEntryPoint();
    
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
	 * @brief QtMainEntryPoint (Descructor)
     *
	 */
	~QtMainEntryPoint();	

private:
    
};
}}}}//end namespace


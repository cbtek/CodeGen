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
	 * @brief QtMainEntryPoint (Descructor)
     *
	 */
	~QtMainEntryPoint();	

private:
    
};
}}}}//end namespace


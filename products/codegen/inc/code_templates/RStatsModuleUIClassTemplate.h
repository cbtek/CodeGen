/*
    RStatsModuleUIClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

class RStatsModuleUIClassTemplate :public CodeTemplate
{
public:
   /*
    * @brief RStatsModuleUIClassTemplate
    *
	*/
	RStatsModuleUIClassTemplate();
    
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
	 * @brief RStatsModuleUIClassTemplate (Descructor)
     *
	 */
	~RStatsModuleUIClassTemplate();	

private:
    
};
}}}}//end namespace


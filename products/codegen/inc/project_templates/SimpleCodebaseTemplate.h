/*
    SimpleCodebaseTemplate.h
    

*/
#pragma once
#include "ProjectTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace project_templates {

class SimpleCodebaseTemplate :public ProjectTemplate
{
public:
   /**
    * @brief SimpleCodebaseTemplate
    *
	*/
	SimpleCodebaseTemplate();
    
    /**
     * @brief getType
     * @return
     */
    virtual ProjectTemplateType getType() const;

    /**
     * @brief createProject
     * @param projectName
     * @param rootFolderPath
     * @param dependLibs
     * @param linkLibs
     */
    virtual void createProject(const std::string& projectName,
                               const std::string& rootFolderPath,
                               const std::vector<std::string>& dependLibs,
                               const std::vector<std::string>& linkLibs);

    /**
	 * @brief SimpleCodebaseTemplate (Descructor)
     *
	 */
	~SimpleCodebaseTemplate();	

private:
    
};
}}}}//end namespace


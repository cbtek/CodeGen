/*
    CommandlineApplicationTemplate.h
    

*/
#pragma once
#include "codegen/inc/ProjectTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace project_templates {

class CommandlineApplicationTemplate :public ProjectTemplate
{
public:
   /**
    * @brief CommandlineApplicationTemplate
    *
	*/
	CommandlineApplicationTemplate();
    


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
	 * @brief CommandlineApplicationTemplate (Descructor)
     *
	 */
	~CommandlineApplicationTemplate();	

private:
    
};
}}}}//end namespace


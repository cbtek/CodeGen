/*
    QtWidgetApplicationTemplate.h
    

*/
#pragma once
#include "codegen/inc/ProjectTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace project_templates {

class QtWidgetApplicationTemplate :public ProjectTemplate
{
public:

    /**
    * @brief QtWidgetApplicationTemplate
    *
	*/
	QtWidgetApplicationTemplate();
    


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
	 * @brief QtWidgetApplicationTemplate (Descructor)
     *
	 */
	~QtWidgetApplicationTemplate();	

private:
    
};
}}}}//end namespace


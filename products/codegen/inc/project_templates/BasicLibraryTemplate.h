/*
    BasicLibraryTemplate.h
    

*/
#pragma once
#include "codegen/inc/ProjectTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace project_templates {

class BasicLibraryTemplate :public ProjectTemplate
{
public:
   /**
    * @brief BasicLibraryTemplate
    *
	*/
	BasicLibraryTemplate();
    
    
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
	 * @brief BasicLibraryTemplate (Descructor)
     *
	 */
	~BasicLibraryTemplate();	

private:
    
};
}}}}//end namespace


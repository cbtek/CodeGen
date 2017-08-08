/*
    ProjectTemplate.hpp
    

*/
#pragma once

#include "utility/inc/Exception.hpp"
#include "utility/inc/StringUtils.hpp"

#include <string>
#include <vector>

namespace cbtek {
namespace products {
namespace codegen {

enum class ProjectTemplateType
{
    SimpleCodebase = 0,
    CommandlineApplication,
    BasicLibrary,    
    QtWidgetApplication,    
    QtLibrary,
    GLFWApplication,
    SDLApplication,
    SFMLApplication,
    AllegroApplication,
    CEGUIApplication,
    wxWidgetsApplication,
    FOXToolkitApplication,
    FLTKApplication,
    NanaApplication,
#ifdef __WIN32
    UWPApplication,
    Win32Application,
#elif __gnu_linux__
    X11Application,
    WaylandApplication,
#endif
    Invalid
};


class ProjectTemplate 
{
public:

    /**
     * @brief getType
     * @return
     */
    virtual ProjectTemplateType getType() const = 0;

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
                               const std::vector<std::string>& linkLibs) = 0;

    /**	
    * @brief Virtual descructor for ProjectTemplate
    *
	*/	
    virtual ~ProjectTemplate(){}
};
}}}//end namespace

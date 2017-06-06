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
    SimpleCodebase,
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

/**
 * @brief printSupportedTemplates Show list of supported templates
 * @param out The stream to print to
 */
static inline void printSupportedTemplates(std::ostream& out)
{
    out << "Supported Template Types:\n{\n";
    out << "\t-t \"SimpleCodebase\"" << std::endl;
    out << "\t-t \"CommandlineApplication\"" << std::endl; //Commandline";
    out << "\t-t \"BasicLibrary\"" << std::endl; //BasicLibrary";
    out << "\t-t \"QtLibrary\"" << std::endl; //QtCoreLibrary";
    out << "\t-t \"QtWidgetApplication\"" << std::endl; //QtWidgetApplication";
//    out << "\t-t \"QtCoreApplication\"" << std::endl; //QtCoreApplication";
//    out << "\t-t \"GLFWOpenGLApplication\"" << std::endl; //GLFWApplication";
//    out << "\t-t \"SDLApplication\"" << std::endl; //SDLApplication";
//    out << "\t-t \"SFMLApplication\"" << std::endl; //SFMLApplication";
//    out << "\t-t \"AllegroApplication\"" << std::endl; //AllegroApplication";
//    out << "\t-t \"CEGUIApplication\"" << std::endl; //CEGUIApplication";
//    out << "\t-t \"wxWidgetsApplication\"" << std::endl; //wxWidgetsApplication";
//    out << "\t-t \"FOXToolkitApplication\"" << std::endl; //FOXToolkitApplication";
//    out << "\t-t \"FLTKApplication\"" << std::endl; //FLTKApplication";
//    out << "\t-t \"NanaApplication\"" << std::endl; //NanaApplication";
//    #ifdef __WIN32
//    out << "\t-t \"UWPApplication\"" << std::endl; //UWPApplication";
//    out << "\t-t \"Win32Application\"" << std::endl; //Win32Application";
//    #elif __gnu_linux__
//    out << "\t-t \"X11Application\"" << std::endl; //X11Application";
//    out << "\t-t \"WaylandApplication\"" << std::endl; //WaylandApplication";
//    #endif
    out << "}\n";
}

inline ProjectTemplateType getProjectTemplateType(const std::string& typeStr)
{
    if (cbtek::common::utility::StringUtils::equals(typeStr,"CommandlineApplication")) return ProjectTemplateType::CommandlineApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"SimpleCodebase")) return ProjectTemplateType::SimpleCodebase;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"BasicLibrary")) return ProjectTemplateType::BasicLibrary;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"QtLibrary")) return ProjectTemplateType::QtLibrary;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"QtWidgetApplication")) return ProjectTemplateType::QtWidgetApplication;    
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"GLFWApplication")) return ProjectTemplateType::GLFWApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"SDLApplication")) return ProjectTemplateType::SDLApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"SFMLApplication")) return ProjectTemplateType::SFMLApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"AllegroApplication")) return ProjectTemplateType::AllegroApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"CEGUIApplication")) return ProjectTemplateType::CEGUIApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"wxWidgetsApplication")) return ProjectTemplateType::wxWidgetsApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"FOXToolkitApplication")) return ProjectTemplateType::FOXToolkitApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"FLTKApplication")) return ProjectTemplateType::FLTKApplication;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"NanaApplication")) return ProjectTemplateType::NanaApplication;
    #ifdef __WIN32
    if (cbtek::common::utility::StringUtils::equals(typeStr,"UWPApplication")) return ProjectTemplateType::UWPApplication;
    if (cbtek::common::utility::StringUtils::equals(typeStr,"Win32Application")) return ProjectTemplateType::Win32Application;
    #elif __gnu_linux__
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"X11Application")) return ProjectTemplateType::X11Application;
    else if (cbtek::common::utility::StringUtils::equals(typeStr,"WaylandApplication")) return ProjectTemplateType::WaylandApplication;
    #endif
    return ProjectTemplateType::Invalid;
}

inline std::string getProjectTemplateTypeString(ProjectTemplateType type)
{
    switch(type)
    {
        case ProjectTemplateType::CommandlineApplication: return "Commandline";
        case ProjectTemplateType::BasicLibrary: return "BasicLibrary";
        case ProjectTemplateType::SimpleCodebase: return "SimpleCodebase";
        case ProjectTemplateType::QtLibrary: return "QtLibrary";
        case ProjectTemplateType::QtWidgetApplication: return "QtWidgetApplication";    
        case ProjectTemplateType::GLFWApplication: return "GLFWApplication";
        case ProjectTemplateType::SDLApplication: return "SDLApplication";
        case ProjectTemplateType::SFMLApplication: return "SFMLApplication";
        case ProjectTemplateType::AllegroApplication: return "AllegroApplication";
        case ProjectTemplateType::CEGUIApplication: return "CEGUIApplication";
        case ProjectTemplateType::wxWidgetsApplication: return "wxWidgetsApplication";
        case ProjectTemplateType::FOXToolkitApplication: return "FOXToolkitApplication";
        case ProjectTemplateType::FLTKApplication: return "FLTKApplication";
        case ProjectTemplateType::NanaApplication: return "NanaApplication";
        #ifdef __WIN32
        case ProjectTemplateType::UWPApplication: return "UWPApplication";
        case ProjectTemplateType::Win32Application: return "Win32Application";
        #elif __gnu_linux__
        case ProjectTemplateType::X11Application: return "X11Application";
        case ProjectTemplateType::WaylandApplication: return "WaylandApplication";
        #endif
    default: THROW_GENERIC_EXCEPTION("Undefined project template defined!")
    };
}

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

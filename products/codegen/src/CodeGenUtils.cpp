/*
    CodeGenUtils.cpp
    

*/
//----------------------------------------
//CodeGenUtils.cpp generated by cbtek on 06-04-2017 at 09:31:55 PM
//----------------------------------------

#include "CodeGenUtils.h"

#include "utility/inc/DateTimeUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/StringUtils.hpp"
#include "utility/inc/SystemUtils.hpp"

using namespace cbtek::common::utility;

namespace cbtek {
namespace products {
namespace codegen {

void CodeGenUtils::printSupportedProjectTemplates(std::ostream &out)
{
    out << "Supported Project Templates:" << std::endl;
    for (long type = static_cast <long>(ProjectTemplateType::SimpleCodebase);
         type < static_cast<long>(ProjectTemplateType::Invalid);
         ++type)
    {
        out << "    " << getStringFromProjectTemplate(static_cast<ProjectTemplateType>(type)) << std::endl;
    }
}

void CodeGenUtils::printSupportedCodeTemplates(std::ostream &out)
{
    out << "Supported Code Templates:" << std::endl;
    for (long type = static_cast <long>(CodeTemplateType::BasicClass);
         type < static_cast<long>(CodeTemplateType::Invalid);
         ++type)
    {
        out << "    " << getStringFromCodeTemplate(static_cast<CodeTemplateType>(type)) << std::endl;
    }
}

CodeTemplateType CodeGenUtils::getCodeTemplateTypeFromStr(const std::string &codeTemplateStr)
{
    std::string type = StringUtils::toUpperTrimmed(codeTemplateStr);

    if (type == "BASICCLASS" || type == "BASIC")
    {
       return CodeTemplateType::BasicClass;
    }
    else if (type == "VIRTUALCLASS" || type == "VIRTUAL")
    {
       return CodeTemplateType::VirtualClass;
    }
    else if (type == "SINGLETONCLASS" || type == "VIRTUAL")
    {
       return CodeTemplateType::SingletonClass;
    }
    else if (type == "TEMPLATECLASS" || type == "TEMPLATE")
    {
       return CodeTemplateType::TemplateClass;
    }
    else if (type == "ENUMCLASS" || type == "ENUM")
    {
       return CodeTemplateType::EnumClass;
    }
    else if (type == "STATICCLASS" || type == "STATIC")
    {
       return CodeTemplateType::StaticClass;
    }
    else if (type == "MAINENTRYPOINT" || type == "MAIN")
    {
       return CodeTemplateType::MainEntryPoint;
    }
    else if (type == "QWIDGETCLASS" || type == "QWIDGET")
    {
       return CodeTemplateType::QWidgetClass;
    }
    else if (type == "QMAINWINDOWCLASS" || type == "QMAINWINDOW")
    {
       return CodeTemplateType::QMainWindowClass;
    }
    else if (type == "QDIALOGCLASS" || type == "QDIALOG")
    {
       return CodeTemplateType::QDialogClass;
    }
    else if (type == "QTMAINENTRYPOINT" || type == "QTMAIN")
    {
       return CodeTemplateType::QtMainEntryPoint;
    }
    else if (type == "CODEGENPROJECTTEMPLATECLASS" || type == "CGPROJECT")
    {
       return CodeTemplateType::CodeGenProjectTemplateClass;
    }
    else if (type == "CODEGENCodeGenCodeTemplateClass" || type == "CGCODE")
    {
       return CodeTemplateType::CodeGenCodeTemplateClass;
    }
    else if (type == "CBTEKGAMEENTRYPOINT" || type == "CBMAIN")
    {
       return CodeTemplateType::CBGameEntryPoint;
    }
    else if (type == "CBGAMECLASS" || type == "CBGAME")
    {
        return CodeTemplateType::CBGameClass;
    }
    else if (type == "RSTATSUIMODULECLASS" || type == "RSTATS")
    {
        return CodeTemplateType::RStatsModuleUIClass;
    }
    else return CodeTemplateType::Invalid;
}

std::string CodeGenUtils::getStringFromCodeTemplate(CodeTemplateType codeTemplateType)
{
    switch (codeTemplateType)
    {
        case CodeTemplateType::BasicClass:return "Basic";
        case CodeTemplateType::SingletonClass:return "Singleton";
        case CodeTemplateType::TemplateClass:return "Template";
        case CodeTemplateType::StaticClass:return "Static";
        case CodeTemplateType::VirtualClass:return "Virtual";
        case CodeTemplateType::EnumClass: return "Enum";
        case CodeTemplateType::MainEntryPoint:return "Main";
        case CodeTemplateType::CBGameClass:return "CBGame";
        case CodeTemplateType::CBGameEntryPoint:return "CBMain";
        case CodeTemplateType::QDialogClass:return "QDialog";
        case CodeTemplateType::QMainWindowClass:return "QMainWindow";
        case CodeTemplateType::QWidgetClass:return "QWidget";
        case CodeTemplateType::QtMainEntryPoint:return "QtMain";
        case CodeTemplateType::CodeGenCodeTemplateClass:return "CGCode";
        case CodeTemplateType::CodeGenProjectTemplateClass:return "CGProject";
        case CodeTemplateType::RStatsModuleUIClass:return "RStats";
        default: THROW_GENERIC_EXCEPTION("Undefined code template defined!")
    }
}

ProjectTemplateType CodeGenUtils::getProjectTemplateTypeFromStr(const std::string &projectTemplateStr)
{
    if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"CommandlineApplication")) return ProjectTemplateType::CommandlineApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"SimpleCodebase")) return ProjectTemplateType::SimpleCodebase;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"BasicLibrary")) return ProjectTemplateType::BasicLibrary;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"QtLibrary")) return ProjectTemplateType::QtLibrary;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"QtWidgetApplication")) return ProjectTemplateType::QtWidgetApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"GLFWApplication")) return ProjectTemplateType::GLFWApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"SDLApplication")) return ProjectTemplateType::SDLApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"SFMLApplication")) return ProjectTemplateType::SFMLApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"AllegroApplication")) return ProjectTemplateType::AllegroApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"CEGUIApplication")) return ProjectTemplateType::CEGUIApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"wxWidgetsApplication")) return ProjectTemplateType::wxWidgetsApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"FOXToolkitApplication")) return ProjectTemplateType::FOXToolkitApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"FLTKApplication")) return ProjectTemplateType::FLTKApplication;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"NanaApplication")) return ProjectTemplateType::NanaApplication;
    #ifdef __WIN32
    if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"UWPApplication")) return ProjectTemplateType::UWPApplication;
    if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"Win32Application")) return ProjectTemplateType::Win32Application;
    #elif __gnu_linux__
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"X11Application")) return ProjectTemplateType::X11Application;
    else if (cbtek::common::utility::StringUtils::equals(projectTemplateStr,"WaylandApplication")) return ProjectTemplateType::WaylandApplication;
    #endif
    return ProjectTemplateType::Invalid;
}

std::string CodeGenUtils::getStringFromProjectTemplate(ProjectTemplateType projectTemplatetype)
{
    switch(projectTemplatetype)
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

void CodeGenUtils::generateLibraries(const std::vector<std::string> &dependLibs, const std::vector<std::string> &linkLibs, std::ostream &out)
{

    if (!dependLibs.empty())
    {
        std::string libs = StringUtils::vectorToString(dependLibs," ");
        out << "#==============================================================================" << std::endl;
        out << "# Add dependencies" << std::endl;
        out << "#==============================================================================" << std::endl;
        out << "add_dependencies (${CURR_TARGET} "+libs+")" << std::endl << std::endl;

    }

    if (!linkLibs.empty())
    {
        std::string libs = StringUtils::vectorToString(linkLibs," ");
        out << "#==============================================================================" << std::endl;
        out << "# Add libs to link with" << std::endl;
        out << "#==============================================================================" << std::endl;
        out << "target_link_libraries (${CURR_TARGET} "+libs+")" << std::endl;
    }
}

void CodeGenUtils::generateDirectories(const std::string &projectName, const std::string &path, const std::vector<std::string>& dirs)
{
    //Create directory structure for projects
    for(const auto& dir : dirs)
    {
        std::string dirToCreate = FileUtils::buildFilePath(path,projectName+"/"+dir);
        FileUtils::createDirectory(dirToCreate);
    }
}


std::string CodeGenUtils::getDoxygenClassHeader(const std::string &className, bool headerOnly)
{
    std::ostringstream out;
    out << "/**" << std::endl;
    out << "*" << std::endl;
    out << "* @file " + className + (headerOnly ? ".hpp" : ".h")  << std::endl;
    out << "* @author "<<  SystemUtils::getUserName() << std::endl;
    out << "* @date "<< DateTimeUtils::getDisplayTimeStamp() << std::endl;
    out << "*" << std::endl;
    out << "*/" << std::endl << std::endl;
    return out.str();
}

void CodeGenUtils::generateDoxygenMethodHeader(const std::string &functionName,
                                               const std::string &returnType,
                                               const std::vector<std::string> &params)
{

}

void CodeGenUtils::generateNamespaceOpen(std::ostream &out,
                                         const std::vector<std::string> &namespaceList)
{

}

void CodeGenUtils::generateNamespaceClose(std::ostream &out,
                                          const std::vector<std::string> &namespaceList)
{

}

void CodeGenUtils::generateNamespaceResolutionCode(std::ostream &out,
                                                   const std::vector<std::string> &namespacelist)
{

}

void CodeGenUtils::generateClassDefinitionMethods(std::ostream &out, const std::vector<std::string> &methodReturnTypes,
                                                  const std::vector<std::string> &methodNames,
                                                  const std::vector<std::string> &methodParams)
{

}

void CodeGenUtils::generateClassImplementationMethods(std::ostream &out,
                                                      const std::vector<std::string> &methodReturnTypes,
                                                      const std::vector<std::string> &methodNames,
                                                      const std::vector<std::string> &methodParams)
{

}

}}}//end namespace



/*
    QtWidgetApplicationTemplate.cpp
    

*/
//----------------------------------------
//QtWidgetApplicationTemplate.cpp generated by cbtek on 06-04-2017 at 07:45:08 PM
//----------------------------------------
#include "QtWidgetApplicationTemplate.h"

#include "utility/inc/StringUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/DateTimeUtils.hpp"
#include "utility/inc/STLUtils.hpp"
#include "utility/inc/XMLUtils.h"

#include "CodeGenUtils.h"

using namespace cbtek::common::utility;
using namespace cbtek::products::codegen;

namespace cbtek {
namespace products {
namespace codegen {
namespace project_templates {


QtWidgetApplicationTemplate::QtWidgetApplicationTemplate()
{

}

ProjectTemplateType QtWidgetApplicationTemplate::getType() const
{
    return ProjectTemplateType::QtWidgetApplication;
}

void QtWidgetApplicationTemplate::createProject(const std::string &projectName,
                                                const std::string &rootFolderPath,
                                                const std::vector<std::string> &dependLibs,
                                                const std::vector<std::string> &linkLibs)
{
    std::string name = FileUtils::getSanitizedPathName(projectName);
    std::vector<std::string> dirs;
    dirs.push_back("inc");
    dirs.push_back("src");
    dirs.push_back("docs");
    dirs.push_back("resx");
    dirs.push_back("tests");
    CodeGenUtils::generateDirectories(name,rootFolderPath,dirs);

    std::ostringstream cmakeOut, mainOut;
    cmakeOut << "#==============================================================================" << std::endl;
    cmakeOut << "# CMakeLists Qt widget application setup for " <<name<<"." << std::endl;
    cmakeOut << "# Created by " << SystemUtils::getUserName() << " on " << DateTimeUtils::getDisplayTimeStamp() << std::endl;
    cmakeOut << "#==============================================================================" << std::endl;
    cmakeOut << "set(CMAKE_INCLUDE_CURRENT_DIR ON)" << std::endl;
    cmakeOut << "set(CURR_TARGET " << name << ")" << std::endl;
    cmakeOut << "set(CURR_TARGET_SOURCES \"${CURR_TARGET}_SOURCES\")" << std::endl;
    cmakeOut << "set(CURR_TARGET_FORMS \"${CURR_TARGET}_FORMS\")" << std::endl;
    cmakeOut << "set(CURR_TARGET_HEADERS \"${CURR_TARGET}_HEADERS\")" << std::endl;
    cmakeOut << "set(CURR_TARGET_HEADERS_NO_MOC \"${CURR_TARGET}_HEADERS_NO_MOC\")" << std::endl;
    cmakeOut << "set(CURR_TARGET_RESOURCES \"${CURR_TARGET}_RESOURCES\")" << std::endl;
    cmakeOut << std::endl;
    cmakeOut << "include(${CMAKE_MODULE_PATH}/flags.cmake)" << std::endl;
    cmakeOut << std::endl;
    cmakeOut << "include_directories(inc)" << std::endl;
    cmakeOut << std::endl;
    cmakeOut << "if (${ENABLE_"+StringUtils::toUpper(name)+"_UNIT_TESTS})" << std::endl;
    cmakeOut << "    add_subdirectory(tests)" << std::endl;
    cmakeOut << "endif()" << std::endl;
    cmakeOut << std::endl;
    cmakeOut << "#==============================================================================" << std::endl;
    cmakeOut << "# Set Qt specific options and find widgets package" << std::endl;
    cmakeOut << "#==============================================================================" << std::endl;
    cmakeOut << "set(CMAKE_AUTOMOC ON)" << std::endl;
    cmakeOut << "set(CMAKE_AUTORCC ON)" << std::endl;
    cmakeOut << "set(CMAKE_AUTOUIC ON)" << std::endl;
    cmakeOut << "set(CMAKE_INCLUDE_CURRENT_DIR ON)" << std::endl;
    cmakeOut << "find_package(Qt5Widgets REQUIRED)" << std::endl;
    cmakeOut << std::endl;
    cmakeOut << "#==============================================================================" << std::endl;
    cmakeOut << "# Include Source Files" << std::endl;
    cmakeOut << "#==============================================================================" << std::endl;
    cmakeOut << "file(GLOB CURR_TARGET_SOURCES \"src/*.cpp\")" << std::endl;
    cmakeOut << "file(GLOB CURR_TARGET_HEADERS \"inc/*.h*\")" << std::endl;
    cmakeOut << "file(GLOB CURR_TARGET_FORMS \"src/*.ui\")" << std::endl;
    cmakeOut << "file(GLOB CURR_TARGET_RESOURCES \"resx/*.qrc\")" << std::endl;
    cmakeOut << std::endl;
    cmakeOut << "#==============================================================================" << std::endl;
    cmakeOut << "# Add executable" << std::endl;
    cmakeOut << "#==============================================================================" << std::endl;
    cmakeOut << "add_executable(${CURR_TARGET}" << std::endl;
    cmakeOut << "               ${PLATFORM}" << std::endl;
    cmakeOut << "               ${CURR_TARGET_SOURCES}" << std::endl;
    cmakeOut << "               ${CURR_TARGET_HEADERS}" << std::endl;
    cmakeOut << "               ${CURR_TARGET_FORMS}" << std::endl;
    cmakeOut << "               ${CURR_TARGET_RESOURCES})" << std::endl;
    cmakeOut << "qt5_use_modules(${CURR_TARGET} Widgets)" << std::endl;
    std::vector<std::string> customLinkLibs = linkLibs;
    customLinkLibs.push_back("Qt5::Widgets");
    CodeGenUtils::generateLibraries(dependLibs,customLinkLibs,cmakeOut);

    //Save CMakeLists.txt file
    std::string cmakeListsPath = FileUtils::buildFilePath(rootFolderPath,name+"/CMakeLists.txt");
    FileUtils::writeFileContents(cmakeListsPath,cmakeOut.str());

    //Save main.cpp file
    std::string srcPath = FileUtils::buildFilePath(rootFolderPath,name+"/src/main.cpp");
    mainOut << "/**" << std::endl;
    mainOut << "* @file   main.cpp" << std::endl;
    mainOut << "* @Author "<< SystemUtils::getUserName() << std::endl;
    mainOut << "* @date   " + DateTimeUtils::getDisplayTimeStamp() << std::endl;
    mainOut << "* @brief  This is the main entry point for " << name << std::endl;
    mainOut << "*/" << std::endl << std::endl;
    mainOut << "#include <QApplication>" << std::endl;
    mainOut << "int main(int argc, char ** argv)" << std::endl;
    mainOut << "{" << std::endl;
    mainOut << "    QApplication a(argc,argv);" << std::endl;
    mainOut << "    return a.exec();" << std::endl;
    mainOut << "}" << std::endl;
    FileUtils::writeFileContents(srcPath,mainOut.str());

    //Save resources.qrc file
    std::string resxPath = FileUtils::buildFilePath(rootFolderPath,name+"/resx/resources.qrc");
    std::ostringstream resxOut;
    XMLStreamWriter resxXML(resxOut);
    resxXML.writeStartDocument();
    resxXML.writeStartElementNoAttributes("RCC");
    resxXML.writeStartElement("qresource");
    resxXML.writeLastAttribute("prefix","/");
    resxXML.writeEndElement("qresource");
    resxXML.writeEndElement("RCC");
    FileUtils::writeFileContents(resxPath,resxOut.str());
}

QtWidgetApplicationTemplate::~QtWidgetApplicationTemplate()
{

}

}}}}//end namespace




#include "CodeGenFactory.h"
#include "CodeGenUtils.h"
#include "CodeTemplate.hpp"

//Standard / Basic C++ Class Code Templates
#include "code_templates/BasicClassTemplate.h"
#include "code_templates/EnumClassTemplate.h"
#include "code_templates/MainEntryPointTemplate.h"
#include "code_templates/SingletonClassTemplate.h"
#include "code_templates/StaticClassTemplate.h"
#include "code_templates/TemplateClassTemplate.h"
#include "code_templates/VirtualClassTemplate.h"

//Qt Class Code Templates
#include "code_templates/QDialogClassTemplate.h"
#include "code_templates/QMainWindowClassTemplate.h"
#include "code_templates/QtMainEntryPoint.h"
#include "code_templates/QWidgetClassTemplate.h"

//CBTek 2D Game Engine Code Templates
#include "code_templates/CBGameClassTemplate.h"
#include "code_templates/CBGameEntryPointTemplate.h"

//CodeGen Code Templates
#include "code_templates/CodeGenCodeTemplateClassTemplate.h"
#include "code_templates/CodeGenProjectTemplateClassTemplate.h"

//RStats Code Templates
#include "code_templates/RStatsModuleUIClassTemplate.h"

//Utility Classes
#include "utility/inc/StringUtils.hpp"
#include "utility/inc/FileUtils.hpp"

using namespace cbtek::common::utility;
using namespace cbtek::products::codegen::code_templates;

namespace cbtek {
namespace products {
namespace codegen {

void CodeGenFactory::create(const std::string &name,
                            const std::string &generator,
                            const std::string &type,
                            const std::string &outputPath)
{
    std::string generatorStr = StringUtils::toUpperTrimmed(generator);
    std::string typeStr = StringUtils::toUpperTrimmed(type);
    std::string nameStr = StringUtils::replace(name," ","_");

    if (generatorStr == "CODE" || generatorStr == "C")
    {
        createCode(nameStr,typeStr,outputPath);
    }

    else if (generatorStr == "PROJECT" || generatorStr == "P")
    {
        createProject(nameStr,typeStr,outputPath);
    }
    else
    {
        THROW_GENERIC_EXCEPTION("Invalid Generator Type(" + generatorStr + ") Detected!");
    }
}

void CodeGenFactory::createCode(const std::string &name,
                                const std::string &type,
                                const std::string &outputPath,
                                bool seperateIncSrc)
{
    CodeTemplatePtr codeTemplate;
    switch(CodeGenUtils::getCodeTemplateTypeFromStr(type))
    {
        case CodeTemplateType::BasicClass : codeTemplate = std::make_shared<BasicClassTemplate>(); break;
        case CodeTemplateType::SingletonClass : codeTemplate = std::make_shared<SingletonClassTemplate>(); break;
        case CodeTemplateType::VirtualClass : codeTemplate = std::make_shared<VirtualClassTemplate>(); break;
        case CodeTemplateType::StaticClass : codeTemplate = std::make_shared<StaticClassTemplate>(); break;
        case CodeTemplateType::TemplateClass : codeTemplate = std::make_shared<TemplateClassTemplate>(); break;
        case CodeTemplateType::EnumClass : codeTemplate = std::make_shared<EnumClassTemplate>(); break;
        case CodeTemplateType::CBGameClass : codeTemplate = std::make_shared<CBGameClassTemplate>(); break;
        case CodeTemplateType::CBGameEntryPoint : codeTemplate = std::make_shared<CBGameEntryPointTemplate>(); break;
        case CodeTemplateType::RStatsModuleUIClass : codeTemplate = std::make_shared<RStatsModuleUIClassTemplate>(); break;
        case CodeTemplateType::QDialogClass : codeTemplate = std::make_shared<QDialogClassTemplate>(); break;
        case CodeTemplateType::QMainWindowClass : codeTemplate = std::make_shared<QMainWindowClassTemplate>(); break;
        case CodeTemplateType::QWidgetClass : codeTemplate = std::make_shared<QWidgetClassTemplate>(); break;
        case CodeTemplateType::QtMainEntryPoint : codeTemplate = std::make_shared<QtMainEntryPoint>(); break;
        case CodeTemplateType::CodeGenProjectTemplateClass : codeTemplate = std::make_shared<CodeGenProjectTemplateClassTemplate>(); break;
        case CodeTemplateType::CodeGenCodeTemplateClass : codeTemplate = std::make_shared<CodeGenCodeTemplateClassTemplate>(); break;
        default:
        {
            THROW_GENERIC_EXCEPTION("ERROR: invalid code template("+type+") detected during creation!");
        }
    }

    std::string srcPath = outputPath;
    std::string incPath = outputPath;
    if (seperateIncSrc)
    {
        srcPath = FileUtils::buildFilePath(srcPath,"src");
        incPath = FileUtils::buildFilePath(incPath,"inc");
        FileUtils::createDirectory(srcPath);
        FileUtils::createDirectory(incPath);
    }
    codeTemplate->createCode(name,incPath,srcPath);
}

void CodeGenFactory::createProject(const std::string &name,
                                   const std::string &type,
                                   const std::string &outputPath)
{

}



}}} //namespace

#include "utility/inc/StringUtils.hpp"

#include "CodeGenUtils.h"
#include "CodeGenFactory.h"

using namespace cbtek::common::utility;
using namespace cbtek::products::codegen;

void showHelp()
{
    std::ostringstream out;
    out << "---------------------" << std::endl;
    out << "CodeGen Help" << std::endl;
    out << "---------------------" << std::endl;
    out << " -n or --name             : Name for generated item (no spaces / required)" << std::endl;
    out << " -g or --generator        : Generator Type(defaults to Code) " << std::endl;
    out << " -t or --type             : Output Type " << std::endl;
    out << " -o or --output           : Output Folder (defaults to current directory)" << std::endl;
    out << "-pt or --project-templates: List of available project templates" << std::endl;
    out << "-ct or --code-templates   : List of available code templates" << std::endl;
    out << std::endl;
    out << "---------------------" << std::endl;
    out << "Generator Types" << std::endl;
    out << "---------------------" << std::endl;
    out << "1) Code" << std::endl;
    out << "2) Project" << std::endl;
    out << "---------------------" << std::endl;
    out << "Examples" << std::endl;
    out << "---------------------" << std::endl;
    out << "1) codegen -g \"code\" -n \"MyClass\" -t \"Basic\""  << std::endl;
    out << "2) codegen -g \"project\" -n \"MyCodebase\" -t \"SimpleCodebase\""  << std::endl;
    std::cerr << out.str() << std::endl;
}


int main(int argc, char **argv)
{

    bool showPT = StringUtils::commandLineArgExists(argc,argv,"--project-templates") ||
                  StringUtils::commandLineArgExists(argc,argv,"-pt");

    bool showCT = StringUtils::commandLineArgExists(argc,argv,"-ct") ||
                  StringUtils::commandLineArgExists(argc,argv,"--code-templates");

    if (showPT)
    {
        CodeGenUtils::printSupportedProjectTemplates(std::cerr);
    }

    if (showCT)
    {
        CodeGenUtils::printSupportedCodeTemplates(std::cerr);
    }

    if (showPT || showCT)
    {
        return 0;
    }

    std::string name = StringUtils::getCommandLineArg(argc,argv,"-n","--name");
    std::string generator =  StringUtils::getCommandLineArg(argc,argv,"-g","--generator");
    std::string output = StringUtils::getCommandLineArg(argc,argv,"-o","--output");
    std::string type = StringUtils::getCommandLineArg(argc,argv,"-t","--type");

    if (name.empty())
    {
        showHelp();
        THROW_GENERIC_EXCEPTION("ERROR: No name specified!")
    }

    if (generator.empty())
    {
        generator = "code";
    }

    if (type.empty())
    {
        showHelp();
        THROW_GENERIC_EXCEPTION("ERROR: No type specified!")
    }

    CodeGenFactory::create(name,generator,type,output);
    return 0;
}

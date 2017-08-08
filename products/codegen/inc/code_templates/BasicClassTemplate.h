/*
    BasicClassTemplate.h
    

*/
#pragma once
#include "CodeTemplate.hpp"

namespace cbtek {
namespace products {
namespace codegen {
namespace code_templates {

/**
 * @brief Template for generating a basic C++ class
 */
class BasicClassTemplate :public CodeTemplate
{
public:

   /**
    * @brief BasicClassTemplate
    *
	*/
	BasicClassTemplate();
    
    /**
     * @see CodeTemplate::createCode
     */
    virtual void createCode(const std::string& name,
                            const std::string& rootFolderIncPath,
                            const std::string& rootFolderSrcPath);

    /**
     * @see CodeTemplate::getType
     */
    virtual CodeTemplateType getType() const;
    
    /**
	 * @brief BasicClassTemplate (Descructor)
     *
	 */
	~BasicClassTemplate();	

private:
    std::vector<std::string> m_namespaceList;
    std::vector<std::string> m_localIncludeList;
    std::vector<std::string> m_libraryIncludeList;
    std::vector<std::string> m_methodNameList;
    std::vector<std::string> m_methodReturnTypeList;
    std::vector<std::string> m_methodParamsList;

};
}}}}//end namespace


#ifndef RULE_H
#define RULE_H

#include "CategorizationFileInfo.h"

///////////////////////////////////////////////////////////////////////
WX_DEFINE_ARRAY(CategorizationFileInfo*, ArrayCategorizationFileInfo);
///////////////////////////////////////////////////////////////////////

class Rule
{
public:
    Rule();
    virtual ~Rule();

    virtual void Execute( CategorizationFileInfo* pFileInfo ) = 0;
    virtual void GetDispStr(wxString& strDisp ) = 0;

    virtual wxString GetRuleType() = 0;
    virtual wxString GetCondition() = 0;
    virtual void SetCondition(wxString strCondition) = 0;
    void SetDestPath(wxString strDestPath)
    {
        m_strBaseDestPath = strDestPath;
    }
    ///////////////////////////////////////////////////////////////

    unsigned long m_nNo;	///< Rule No.
    bool m_bSelected;	///< Seleted flag
    wxString m_strBaseDestPath;		///< Base dest path

protected:
private:
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class BasicRule : public Rule
{
public:
    BasicRule() {};
    virtual ~BasicRule() {};

    virtual void Execute( CategorizationFileInfo* pFileInfo );
    virtual void GetDispStr(wxString& strDisp );

    virtual wxString GetRuleType()
    {
        return ms_strType;
    }

    virtual wxString GetCondition()
    {
        return _T("-");
    }


    virtual void SetCondition(wxString strCondition) {}


    ///////////////////////////////////////////////////////////////////

    static wxString ms_strType;

protected:
private:
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class NameIncludeRule : public Rule
{
public:
    NameIncludeRule() {};
    virtual ~NameIncludeRule() {};

    ///////////////////////////////////////////////////////////////////

    wxString m_strInclude;

    static wxString ms_strType;

    ///////////////////////////////////////////////////////////////////

    virtual void Execute( CategorizationFileInfo* pFileInfo );
    virtual void GetDispStr(wxString& strDisp );
    virtual wxString GetRuleType()
    {
        return ms_strType;
    }
    virtual wxString GetCondition()
    {
        return m_strInclude;
    }

    virtual void SetCondition(wxString strCondition)
    {
        m_strInclude = strCondition;
    }

protected:
private:

};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class ExtNameRule : public Rule
{
public:
    ExtNameRule();
    virtual ~ExtNameRule();

    ///////////////////////////////////////////////////////////////////

    wxArrayString m_arrStrExtName;

    static wxString ms_strType;

    ///////////////////////////////////////////////////////////////////

    virtual void Execute( CategorizationFileInfo* pFileInfo );
    virtual void GetDispStr(wxString& strDisp );
    virtual wxString GetRuleType()
    {
        return ms_strType;
    }
    virtual wxString GetCondition();
    virtual void SetCondition(wxString strCondition);

protected:
private:

};

#endif // RULE_H
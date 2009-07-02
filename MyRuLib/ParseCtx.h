#ifndef __PARSECTX_H__
#define __PARSECTX_H__

#include <wx/wx.h>

#define XML_STATIC
#include <expat.h>

class ParsingContext
{
public:
	ParsingContext();
	virtual ~ParsingContext();
	wxString Path(size_t count = 0);
	void AppendTag(wxString &tag);
	void RemoveTag(wxString &tag);
	size_t Level() {return m_tags.Count();};
	XML_Parser & GetParser() {return m_parser;};
	void Stop();
public:
    static wxString CharToString(const char *s, size_t len = wxString::npos);
    static wxString CharToLower(const char *s, size_t len = wxString::npos);
    static bool IsWhiteOnly(const wxChar *buf);
public:
    wxMBConv *conv;
    wxString encoding;
    wxString version;
private:
	wxArrayString m_tags;
	XML_Parser m_parser;
};

#endif // __PARSECTX_H__
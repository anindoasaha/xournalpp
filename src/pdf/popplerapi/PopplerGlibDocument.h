/*
 * Xournal++
 *
 * Poppler GLib Implementation
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "pdf/base/XojPdfDocumentInterface.h"

#include <boost/filesystem/path.hpp>
using boost::filesystem::path;

#include <poppler.h>

class PopplerGlibDocument : public XojPdfDocumentInterface
{
public:
	PopplerGlibDocument();
	PopplerGlibDocument(const PopplerGlibDocument& doc);
	virtual ~PopplerGlibDocument();

public:
	virtual void assign(XojPdfDocumentInterface* doc);
	virtual bool equals(XojPdfDocumentInterface* doc);

public:
	virtual bool save(path filename, GError** error);
	virtual bool load(path filename, string password, GError** error);
	virtual bool isLoaded();

	virtual XojPdfPage* getPage(size_t page);
	virtual size_t getPageCount();
	virtual XojPdfBookmarkIterator* getContentsIter();

private:
	XOJ_TYPE_ATTRIB;

	PopplerDocument* document;
};
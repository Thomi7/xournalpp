/*
 * Xournal++
 *
 * Part of the customizable toolbars
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <string>
#include <vector>

#include "AbstractToolItem.h"
#include "XournalType.h"

class GladeGui;
class SpinPageAdapter;

class ToolPageSpinner: public AbstractToolItem {
public:
    ToolPageSpinner(GladeGui* gui, ActionHandler* handler, string id, ActionType type);
    virtual ~ToolPageSpinner();

public:
    SpinPageAdapter* getPageSpinner();
    void setPageInfo(size_t pagecount, size_t pdfpage);
    virtual string getToolDisplayName();
    GtkToolItem* createItem(bool horizontal);
    GtkToolItem* createTmpItem(bool horizontal);

protected:
    virtual GtkToolItem* newItem();
    virtual GtkWidget* getNewToolIcon();

private:
    void updateLabels();

private:
    GladeGui* gui = nullptr;

    SpinPageAdapter* pageSpinner = nullptr;
    GtkOrientation orientation = GTK_ORIENTATION_HORIZONTAL;

    GtkWidget* box = nullptr;
    GtkWidget* lbPageNo = nullptr;
    GtkWidget* lbVerticalPdfPage = nullptr;
    size_t pagecount, pdfpage;
};

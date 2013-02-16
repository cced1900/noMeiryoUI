#pragma once

#include <vector>
#include <windows.h>
#include "Resource.h"
#include "basedialog.h"
#include "TwrCombobox.h"
#include "TwrCheckbox.h"

struct FontInfo {
	LOGFONT logFont;
	std::vector<int> charsetList;
};

class FontSel :
	public BaseDialog
{
private:
	TwrCombobox *m_fontNameList;
	TwrCombobox *m_fontSizeList;
	TwrCombobox *m_ChersetList;
	TwrCombobox *m_styleList;
	TwrCheckbox *m_underline;
	TwrCheckbox *m_strike;

	LOGFONT selectedFont;

	void setCharset(void);
	void setStyle(void);
	INT_PTR onOK(void);

protected:
	INT_PTR OnInitDialog();
	INT_PTR OnCommand(WPARAM wParam);

public:
	FontSel(HWND parent, int resource);
	virtual ~FontSel(void);

	LOGFONT getSelectedFont() {
		return selectedFont;
	}
	void setNoMeiryoUI();

};

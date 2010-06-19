/*
 * This file is part of WMail.
 * Copyright (C) 2010-2011  Kevin Vicrey <kevin.vicrey@nexu.org>
 * Copyright (C) 2010-2011  Cyril Collen <cyril.collen@nexu.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <vector>
#include <Wt/WContainerWidget>
#include <Wt/WText>
#include <Wt/WAnchor>
#include <Wt/WBorderLayout>

#include "CApplication.h"
#include "CMenu.h"
#include "CMainpage.h"

using namespace nsWMail;
using namespace Wt;

CApplication::CApplication(const WEnvironment& env)
  : WApplication(env)
{
    //b->clicked().connect(this, &WMailApplication::greet);
    
    // Main layouts
    _mainContainer = new WContainerWidget();
    _mainLayout    = new WBorderLayout();

    _menu = new CMenu();
    CMainpage * mainpage = new CMainpage();

    _mainLayout->addWidget(_menu   , WBorderLayout::West);
    _mainLayout->addWidget(mainpage, WBorderLayout::Center);
    
    // use layout but do not justify vertically
    _mainContainer->setLayout(_mainLayout, AlignTop | AlignJustify);

    root()->addWidget(_mainContainer);
}

CApplication::~CApplication() { }

void CApplication::showPage(WContainerWidget& widgetCont)
{
	_mainLayout->addWidget(&widgetCont, WBorderLayout::Center);
}

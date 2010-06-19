#include "wmailapplication.h"
#include "mainpage.h"

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
WMailApplication::WMailApplication(const WEnvironment& env)
  : WApplication(env)
{
    _mainContainer = new WContainerWidget();
    _mainLayout = new WBorderLayout();

    MainPage * mainpage = new MainPage();
    _mainLayout->addWidget(new WText("West-side is best"), WBorderLayout::West);
    _mainLayout->addWidget(new WText("East-side is best"), WBorderLayout::East);
    _mainLayout->addWidget(mainpage, WBorderLayout::Center);
    //layout->addWidget(contents, Center);
   
    // use layout but do not justify vertically
    _mainContainer->setLayout(_mainLayout, AlignTop | AlignJustify);
    //b->clicked().connect(this, &WMailApplication::greet);
    //
    root()->addWidget(_mainContainer);
}

void WMailApplication::showPage(WContainerWidget& widgetCont)
{
	_mainLayout->addWidget(&widgetCont, WBorderLayout::Center);
}

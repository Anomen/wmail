#include "wmailapplication.h"

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
WMailApplication::WMailApplication(const WEnvironment& env)
  : WApplication(env)
{
    WContainerWidget *w = new WContainerWidget();
    WBorderLayout *layout = new WBorderLayout();
    WTreeView *treeEmail = new WTreeView();
    WStringListModel *emailModel = new WStringListModel();
    emailModel->addString("Status");
    emailModel->addString("Description");
    emailModel->addString("Date");
    emailModel->addString("Date");

    
  //  for(int i = 0; i < 10; i++) {
  //      emailModel->insertRows(i, i 
  //  }
    treeEmail->setModel(emailModel);

    layout->addWidget(new WText("West-side is best"), WBorderLayout::West);
    layout->addWidget(new WText("East-side is best"), WBorderLayout::East);
    layout->addWidget(treeEmail, WBorderLayout::Center);
    //layout->addWidget(contents, Center);
   
    // use layout but do not justify vertically
    w->setLayout(layout, AlignTop | AlignJustify);
    //b->clicked().connect(this, &WMailApplication::greet);
    //
    root()->addWidget(w);
}

void WMailApplication::greet()
{
  /*
   * Update the text, using text input into the nameEdit_ field.
   */
  greeting_->setText("Hello there, " + nameEdit_->text());

}

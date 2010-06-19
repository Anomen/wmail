/*
 * Copyright (C) 2008 Emweb bvba, Heverlee, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include <vector>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WString>
#include <Wt/WSuggestionPopup>
#include <Wt/WFileUpload>
#include <Wt/WBorderLayout>
#include <Wt/WContainerWidget>
#include <Wt/WStringListModel>
#include <Wt/WTreeView>

using namespace Wt;
using namespace std;

/*
 * A simple hello world application class which demonstrates how to react
 * to events, read input, and give feed-back.
 */
class WMailApplication : public WApplication
{
public:
  WMailApplication(const WEnvironment& env);

private:
  WLineEdit *nameEdit_;
  WText *greeting_;

  void greet();
};

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

WApplication *createApplication(const WEnvironment& env)
{
  /*
   * You could read information from the environment to decide whether
   * the user has permission to start a new application
   */
  return new WMailApplication(env);
}

int main(int argc, char **argv)
{
  /*
   * Your main method may set up some shared resources, but should then
   * start the server application (FastCGI or httpd) that starts listening
   * for requests, and handles all of the application life cycles.
   *
   * The last argument to WRun specifies the function that will instantiate
   * new application objects. That function is executed when a new user surfs
   * to the Wt application, and after the library has negotiated browser
   * support. The function should return a newly instantiated application
   * object.
   */
  return WRun(argc, argv, &createApplication);
}



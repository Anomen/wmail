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

using namespace Wt;
using namespace std;

/*
 * A simple hello world application class which demonstrates how to react
 * to events, read input, and give feed-back.
 */
class HelloApplication : public WApplication
{
public:
  HelloApplication(const WEnvironment& env);

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
HelloApplication::HelloApplication(const WEnvironment& env)
  : WApplication(env)
{
  setTitle("Hello world");                               // application title

  root()->addWidget(new WText("Your name, please ? "));  // show some text
  nameEdit_ = new WLineEdit(root());                     // allow text input
  nameEdit_->setFocus();                                 // give focus

  WPushButton *b = new WPushButton("Greet me.", root()); // create a button
  b->setMargin(5, Left);                                 // add 5 pixels margin

  root()->addWidget(new WBreak());                       // insert a line break

  greeting_ = new WText(root());                         // empty text

 // options for email address suggestions
 Wt::WSuggestionPopup::Options contactOptions
 = { "<b>",         // highlightBeginTag
     "</b>",        // highlightEndTag
     ',',           // listSeparator      (for multiple addresses)
     " \\n",        // whitespace
     "-., \"@\\n;", // wordSeparators     (within an address)
     ", "           // appendReplacedText (prepare next email address)
    };

 Wt::WSuggestionPopup *popup
   = new Wt::WSuggestionPopup(Wt::WSuggestionPopup::generateMatcherJS(contactOptions),
                              Wt::WSuggestionPopup::generateReplacerJS(contactOptions),
                              root());
 popup->forEdit(nameEdit_);

 // load popup data
vector<WString> contacts;
contacts.push_back ("aa Tipoun");
contacts.push_back ("aa Anomen");


 for (unsigned i = 0; i < contacts.size(); ++i)
   popup->addSuggestion(contacts[i], contacts[i]);

 // set style
 popup->setStyleClass("suggest");

 Wt::WFileUpload *upload = new Wt::WFileUpload(root());
 upload->setFileTextSize(40);

 // Provide a button
 Wt::WPushButton *uploadButton = new Wt::WPushButton("Send", root());

 // Upload when the button is clicked.
 uploadButton->clicked().connect(SLOT(upload, Wt::WFileUpload::upload));
 uploadButton->clicked().connect(SLOT(uploadButton, Wt::WPushButton::disable));

 // Upload automatically when the user entered a file.
 upload->changed().connect(SLOT(upload, WFileUpload::upload));
 upload->changed().connect(SLOT(uploadButton, Wt::WPushButton::disable));



  /*
   * Connect signals with slots
   *
   * - simple Wt-way
   */
  b->clicked().connect(this, &HelloApplication::greet);

  /*
   * - using an arbitrary function object (binding values with boost::bind())
   */
  nameEdit_->enterPressed().connect
    (boost::bind(&HelloApplication::greet, this));
}

void HelloApplication::greet()
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
  return new HelloApplication(env);
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



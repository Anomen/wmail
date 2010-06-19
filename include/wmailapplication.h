#ifndef __wmailapplication_h
#define __wmailapplication_c

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

#endif

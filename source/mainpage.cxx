#include <Wt/WStringListModel>
#include <Wt/WTreeView>
#include "mainpage.h"

MainPage::MainPage() 
{
    WTreeView *treeEmail = new WTreeView();
    WStringListModel *emailModel = new WStringListModel();
    emailModel->addString("Status");
    emailModel->addString("Description");
    emailModel->addString("Date");
    emailModel->addString("Date");

    
    treeEmail->setModel(emailModel);

	this->addWidget(treeEmail);

}

#include <Wt/WStringListModel>
#include <Wt/WTreeView>
#include "mainpage.h"

#include <vector>
#include <string>
#include <iostream>

#include <vmime/vmime.hpp>
#include <vmime/platforms/posix/posixHandler.hpp>

using namespace std;

vector<string> subjects()
{
	// VMime initialization
	vmime::platform::setHandler<vmime::platforms::posix::posixHandler>();

    // Connect to the IMAP store
    vmime::ref <vmime::net::session> sess = vmime::create <vmime::net::session>();

    vmime::utility::url storeURL("imap://wmail:pouet@nexu.org");

    vmime::ref <vmime::net::store> store = sess->getStore(storeURL);
    store->connect();

    // Open the INBOX
    vmime::utility::path  p ("Potes");
    vmime::ref <vmime::net::folder> folder = store->getFolder(p);
    folder->open(vmime::net::folder::MODE_READ_WRITE);

    vmime::utility::outputStreamAdapter out(std::cout);

    // Get the first message in the INBOX
    vector<vmime::ref<vmime::net::message> > messages = folder->getMessages();
    folder->fetchMessages(messages, vmime::net::folder::FETCH_FULL_HEADER);

    vector<string> ret;
    for (vector<vmime::ref<vmime::net::message> >::iterator i = messages.begin();
            i != messages.end(); ++i)
        ret.push_back((*i)->getHeader()->Subject()->getValue()->generate());

    return ret;
}

MainPage::MainPage() 
{
    WTreeView *treeEmail = new WTreeView();
    WStringListModel *emailModel = new WStringListModel();

    vector<string> listSubject = subjects();
    for(vector<string>::iterator i = listSubject.begin();
            i != listSubject.end(); ++i)
        emailModel->addString(*(i));

    treeEmail->setModel(emailModel);

	this->addWidget(treeEmail);

}

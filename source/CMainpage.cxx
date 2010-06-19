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
#include <string>
#include <iostream>

#include <vmime/vmime.hpp>
#include <vmime/platforms/posix/posixHandler.hpp>

#include <Wt/WStringListModel>
#include <Wt/WTreeView>

#include "CMainpage.h"

using namespace std;
using namespace nsWMail;
using namespace Wt;

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

CMainpage::CMainpage() 
    : WContainerWidget()
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

CMainpage::~CMainpage() { }

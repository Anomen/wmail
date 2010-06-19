#include <iostream>
#include <vector>

#include <vmime/vmime.hpp>
#include <vmime/platforms/posix/posixHandler.hpp>

using namespace std;

int main (void)
{
	// VMime initialization
	vmime::platform::setHandler<vmime::platforms::posix::posixHandler>();

    // Connect to the IMAP store
    vmime::ref <vmime::net::session> sess = vmime::create <vmime::net::session>();

    vmime::utility::url storeURL("imap://wmail:pouet@nexu.org");

    vmime::ref <vmime::net::store> store = sess->getStore(storeURL);
    store->connect();

    // Open the INBOX
    vmime::ref <vmime::net::folder> folder = store->getDefaultFolder();
    folder->open(vmime::net::folder::MODE_READ_WRITE);

    vmime::utility::outputStreamAdapter out(std::cout);

    // Get the first message in the INBOX
    vector<vmime::ref<vmime::net::message> > messages = folder->getMessages();
    folder->fetchMessages(messages, vmime::net::folder::FETCH_FULL_HEADER);

    for (vector<vmime::ref<vmime::net::message> >::iterator i = messages.begin();
            i != messages.end(); ++i)
        cout << (*i)->getHeader()->Subject()->getValue()->generate() << endl;

    return 0;
}

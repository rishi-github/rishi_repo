


#include<string>
#include<iostream>
#include<unistd.h>
using namespace std;
void print_info()
{
cout<<endl<<"ruid is:"<<getuid()<<"  euid is:"<<geteuid();

}

int main(int argc , char** argv) {
// we don’t have to save this; getuid() will return
//it for us.
// but it’s nice to have in a variable that we can
//use similar
// to savedUid
const uid_t realUid = getuid();
const uid_t savedUid = geteuid();
print_info();

/*
NOTE: if the effective uid is root, this call to
setuid() here will change the effective uid for
the rest of the program. This is why one must
use setreuid() if you want a setuid root
program to flip back and forth between root and
the real UID.
*/

const uid_t tmp=200;
const uid_t root=0;
seteuid(root);
print_info();
setuid(tmp);
print_info();


cout<<"*****************";
seteuid(realUid);
print_info();

//reset to original state using
//setreuid(" << realUid
//<< " , " << savedUid << ")]” << std::endl;
setreuid(realUid , savedUid);
print_info();

//std::cout << “[call to seteuid(" << realUid << ")]”
//<< std::endl;
seteuid(realUid);
print_info();

//std::cout << “[reset to original state using
//setreuid(" << realUid
//<< " , " << savedUid << ")]” << std::endl;
setreuid(realUid , savedUid);
print_info();

//std::cout << “[swapping real/effective uid's using
//setreuid()]” << std::endl;
setreuid(savedUid , realUid);
print_info();

//std::cout << “[reset to original state using
//setreuid(" << realUid
//<< " , " << savedUid << ")]” << std::endl;
setreuid(realUid , savedUid);
print_info();

//std::cout << “[changing all id's using setresuid("
//<< realUid << " , "
//<< realUid << " , " << realUid << ")]” <<
//std::endl;
setresuid(realUid , realUid , realUid);
print_info();

//std::cout << “[reset to original state using
//setreuid(" << realUid
//<< " , " << savedUid << ")]” << std::endl;
//std::cout << ‘\n’ << “(this will fail: we just
//overwrote the” << ‘\n’
//<< ” saved set-user ID with setresuid())” <<
//std::endl;
setreuid(realUid , savedUid);
print_info();

return(0);
}

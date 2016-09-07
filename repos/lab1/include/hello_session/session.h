#ifndef _INCLUDE__HELLO_SESSION__HELLO_SESSION_H_
#define _INCLUDE__HELLO_SESSION__HELLO_SESSION_H_

#include <base/rpc.h>
#include <session/session.h>

namespace Hello {struct Session;}

struct Hello::Session : Genode::Session
{
    static const char *server_name() {return "hello";}

    virtual void say_hello() = 0;
    virtual int add(int a, int b) = 0;

    GENODE_RPC(Rpc_say_hello, void, say_hello);
    GENODE_RPC(Rpc_add, int , add ,int ,int);
    GENODE_RPC_INTERFACE(Rpc_say_hello, Rpc_add);
};

#endif

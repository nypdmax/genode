#include <hello_session/session.h>
#include <base/log.h>
#include <base/rpc_client.h>

namespace Hello { struct Session_client; }

struct Hello::Session_client : Genode::Rpc_client<Session>
{
  Session_client(Genode::Capability<Session> cap)
    : Genode::Rpc_client<Session>(cap) { }

  void say_hello()
  {
    Genode::log("issue rpc from say_hello");
    call<Rpc_say_hello>();
    Genode::log("returned from 'say_hello' RPC call");
  }

  int add(int a, int b)
  {
    return call<Rpc_add>(a, b);
  }
};

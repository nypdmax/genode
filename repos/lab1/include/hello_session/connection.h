#include <session/client.h>
#include <base/connection.h>

namespace Hello { struct Connection; }

struct Hello::Connection : Genode::Connection<Session>, Session_client
{
    Connection(Genode::Env &env)
        : Genode::Connection<Hello::Session>(env, session(env.parent(), "ram_quota=4K")), Session_client(cap())
    {}
};

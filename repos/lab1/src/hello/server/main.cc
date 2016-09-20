#include <base/log.h>
#include <base/component.h>
#include <hello_session/hello_session.h>
#include <base/rpc_server.h>
#include <root/component.h>

namespace Hello {
    struct Session_component;
    class Root_component;
    struct Main;
}

struct Hello::Session_component : Genode::Rpc_object<Session>
{
    void say_hello()
    {
        Genode::log("Hello I am server.");
    }

    int add(int a, int b)
    {
        return (a + b);
    }
};

class Hello::Root_component : public Genode::Root_component<Session_component>
{
protected:

    Session_component *_create_session(const char *args)
        {
            Genode::log("creating hello session");
            return new (md_alloc()) Session_component();
        }

public:

    Root_component(Genode::Entrypoint &ep, Genode::Allocator &alloc):
        Genode::Root_component<Session_component>(ep, alloc)
    {
        Genode::log("creating root component.");
    }
};

struct Hello::Main
{
    Genode::Env &env;

    Genode::Sliced_heap sliced_heap { env.ram(), env.rm()};

    Hello::Root_component root { env.ep(), sliced_heap };

    Main(Genode::Env &env) : env(env)
    {
        env.parent().announce(env.ep().manage(root));
    }
};

Genode::size_t Component::stack_size() { return (64 * 1024);}

void Component::construct(Genode::Env &env)
{
    static Hello::Main main(env);
}

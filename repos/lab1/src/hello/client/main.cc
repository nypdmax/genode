#include <base/component.h>
#include <base/log.h>
#include <hello_session/connection.h>

Genode::size_t Component::stack_size() { return 64*1024; }

void Component::construct(Genode::Env &env)
{
    Hello::Connection hello(env);

    hello.say_hello();

    int const sum = hello.add(2, 5);
    Genode::log("2 + 5 = ", sum);

    Genode::log("hello tutorial completed");
}

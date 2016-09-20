//#ifndef _INCLUDE__HELLO_SESSION_H__CLIENT_H_
//#define _INCLUDE__HELLO_SESSION_H__CLIENT_H_

#include <base/component.h>
#include <base/log.h>
#include <hello_session/connection.h>

Genode::size_t Component::stack_size() { return 64*1024; }

void Component::construct(Genode::Env &env)
{
    Hello::Connection hello(env);

    Genode::log("hello servie connected");
    hello.say_hello();

    int const sum = hello.add(2, 5);
    Genode::log("2 + 5 = ", sum);

    Genode::log("hello tutorial completed");
}

//#endif

#include <base/component.h>
#include <base/log.h>

enum {
    DEFAULT_STACK_SIZE = 64 * 1024
};

Genode::size_t Component::stack_size() { return DEFAULT_STACK_SIZE; }

void Component::construct(Genode::Env &)
{
    Genode::log("Hello world");
    //Genode::printf("Hello world");
}

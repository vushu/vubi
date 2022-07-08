#include <iostream>
#include <vubi/application.h>
#define NDEBUG
int main() { 
    vubi::Application application;
    application.enable_log_messages();
    application.run();
}
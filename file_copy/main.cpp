//
//  main.cpp
//  file_copy
//
//  Created by 어진석 on 2021/12/19.
//

#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

extern char **environ;

class App
{
public:
    App& start();
    App& handleArguments(int argc, const char ** argv);
    App& printEnvironmentVariables();
};

App& App::start()
{
    std::cout << "starting the application" << std::endl;
    return *this;
}

App& App::handleArguments(int argc, const char **argv)
{
    if(argc != 2 || strcmp(argv[1], "--help") != 0) {
        std::cout << "--help is not found" << std::endl;
    }
    
    int len = argc;
    std::cout << len << std::endl;
    for(int i = 0; i < len; i++) {
        std::cout << "argv" << i << ":";
        std::cout << argv[i] << std::endl;
    }
    
    return *this;
}

App& App::printEnvironmentVariables()
{
    // read environment variables
    for (unsigned i = 0; environ[i]; i++)
        std::cout << environ[i] << std::endl;
    
    return *this;
}

int main(int argc, const char * argv[]) {
        
    App app;
    
    app
        .start()
        .handleArguments(argc, argv)
        .printEnvironmentVariables();
        
    return 0;
}

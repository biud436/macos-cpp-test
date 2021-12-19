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
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

class App
{
public:
    App& start();
    App& handleArguments(int argc, const char ** argv);
    App& printEnvironmentVariables();
    App& makeTempFile();
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
    for(int i = 0; i < len; i++)
    {
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

App& App::makeTempFile()
{
    int fd;
    char temp[] = "/tmp/temp_test_XXXXXX";
    fd = mkstemp(temp);
    
    if( fd == -1)
    {
        std::cout << "error mkstemp" << std::endl;
        return *this;
    }
    
    std::cout << "filename : " << temp << std::endl;
    
    unlink(temp);
    
    if(close(fd) == -1)
    {
        std::cout << "close() error" << std::endl;
    }
            
    return *this;
}

int main(int argc, const char * argv[]) {
        
    App app;
    
    app
        .start()
        .handleArguments(argc, argv)
        .printEnvironmentVariables()
        .makeTempFile();

    return 0;
}

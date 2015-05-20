#include <iostream>
using namespace std;

#include "logger.h"

int main(int argc, char* argv[])
{
    cout << "This is log4cpp example" << endl;

    LogHelper logger;
    logger.Init("logger.log", "Testor", true);

    logger.Error("I am real error!");
    logger.Warn("Tell me,who is the coder?");
    logger.Info("Tell me,who is the coder?");
    logger.Debug("Tell me,where can i to go?");

    return 0;
}

// Copyright 2023 Tarasova Anastasiya

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

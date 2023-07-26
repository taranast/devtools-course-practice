// Copyright 2023 Yashina Anastasia

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/vector_3d_app.h"

int main(int argc, const char** argv) {
    vector3dApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

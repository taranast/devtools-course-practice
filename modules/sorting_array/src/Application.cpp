// Copyright 2023 Tarasova Anastasiya
#include <string>
#include <sstream>
#include <cstring>
#include "include/Application.h"
#include "include/sorting_array.h"

size_t parseUInt(const char* arg) {
    int value = 0;
    std::stringstream s(arg);
    s >> value;
    if (s.fail() || value < 0) {
        throw std::invalid_argument("Expected unsigned integer value.");
    }

    return static_cast<size_t>(value);
}

char parseSort(const char* arg) {
    char op;
    if (strcmp(arg, "1") == 0) {
        op = '1';
    } else if (strcmp(arg, "2") == 0) {
        op = '2';
    } else {
        throw std::string("Wrong sort format!");
    }
    return op;
}

double parseDouble(const char* arg) {
    double value = 0;
    std::stringstream s(arg);
    s >> value;
    if (s.fail()) {
        throw std::invalid_argument("Expected double value.");
    }

    return value;
}

void Application::help(const char* appname) {
    std::string sb;
    sb
        .append("This program is designed to sorting array ")
        .append("Please provide arguments in the following format:\n\n")
        .append("  $ ")
        .append(appname)
        .append(" <count> <sort> <array> \n\n")
        .append("Where <count> is an unsigned integer size of array\n")
        .append("<sort> is char sort type\n")
        .append("<array> is an double array\n");

    message = std::move(sb);
}

bool Application::validateArguments(int argc, const char** argv) {
    std::string helper_str =
        std::string(" Type `$ ").append(argv[0])
        .append("` to see help message");

    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 3) {
        message =
            std::string("ERROR: Input parameters amount mismatch.");

        return false;
    }

    size_t count;
    try {
        count = parseUInt(argv[1]);
    }
    catch (const std::invalid_argument& e) {
        message =
            std::string("Wrong count format!")
            .append(e.what());
        return false;
    }
    int sort;
    try {
        sort = parseUInt(argv[2]);
    }
    catch (const std::invalid_argument& e) {
        message =
            std::string("Wrong sort format!")
            .append(e.what());
        return false;
    }
    if (argc == 3) {
        message =
            std::string("Array is empty!");
        return false;
    }

    if (sort < 1 || sort > 2) {
        message =
            std::string("Wrong sort value!");
        return false;
    }

    if (static_cast<size_t>(argc) < (3 + count)) {
        message =
            std::string("ERROR: Adjacency matrix "
                "is not completely filled");
        return false;
    }

    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    if (!validateArguments(argc, argv)) {
        return message;
    }

    size_t count;
    int sort;
    std::vector<std::vector<double>> mat;

    try {
        count = parseUInt(argv[1]);
    }
    catch (const std::invalid_argument& e) {
        message =
            std::string("Wrong count format!")
            .append(e.what());
        return message;
    }
    try {
        sort = parseUInt(argv[2]);
    }
    catch (const std::invalid_argument& e) {
        message =
            std::string("Wrong sort format!")
            .append(e.what());
        return message;
    }
    double* array = new double[count];
    for (size_t i = 0; i < count; i++)
        try {
        array[i] = parseDouble(argv[3 + i]);
    }
    catch (const std::invalid_argument& e) {
        message =
            std::string("ERROR: Cant parse matrix at index ")
            .append("[")
            .append(std::to_string(i))
            .append("]. ")
            .append(e.what());
        return message;
    }
    std::ostringstream stream;
    switch (sort) {
    case 1:
        SortInsert(array, count);
        stream << "Sorted array: ";
        for (size_t i = 0; i < count; i++)
            stream << array[i] << " ";
        break;
    case 2:
        SortQuick(array, 0, count);
        stream << "Sorted array: ";
        for (size_t i = 0; i < count; i++)
            stream << array[i] << " ";
        break;
    }
    message = stream.str();
    return message;
}

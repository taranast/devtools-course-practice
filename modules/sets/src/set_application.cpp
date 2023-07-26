// Copyright 2023 Mironov Nikita

#include "include/set_application.h"

void set_application::help() {
    message += "This application is needed to work with the Set class.\n\n";
    message += "To get started, write one of the commands below: \n";
    message += "s - to separate operations \n";
    message += "get - to get elements of set \n";
    message += "insert - to inset element or elements separated by space \n";
    message += "erase - to erase element \n";
    message += "exist - to check if the element exists \n";
    message += R"(/ - to separate  two sets in following commands 
     /like & 1 2 3 / 2 3 5 / \n)";
    message += "& - to intersect two sets /like & 1 2 3 / 2 3 5 / \n";
    message += "| - to union two sets /like | 1 2 3 / 2 3 5 / \n";
    message += "- - to difference two sets /like - 1 2 3 / 2 3 5 / \n";
}

bool set_application::is_number(const std::string& string) {
    std::string::const_iterator iterator = string.begin();
    while (iterator != string.end() && std::isdigit(*iterator))
        ++iterator;
    return !string.empty() && iterator == string.end();
}

std::string set_application::operator()(int argc, const char** argv) {
    if (argc == 1) {
        help();
    }

    for (int arg_num = 1; arg_num < argc; ++arg_num) {
        std::string arg(argv[arg_num]);
        if (arg == "s") {
            continue;
        }
        if (arg == "get") {
            std::vector<int> elems = set.getElems();
            for (unsigned int i = 0; i < elems.size(); i++) {
                message += " " + std::to_string(elems[i]);
            }
            if (set.getElems().empty()) {
                message += "Notification: set is empty.\n";
            }
            continue;
        }
        if (arg == "insert") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for insert!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "s") {
                message += "Error: need arguments for insert!";
                break;
            } else if (!is_number(std::string(argv[arg_num + 1]))) {
                message += "Error: can't insert non digit!";
                break;
            }
            int insert_arg_num = arg_num + 1;
            std::string insert_arg(argv[insert_arg_num]);
            set.insert(stoi(insert_arg));
            while (true) {
                insert_arg_num += 1;
                if (insert_arg_num < argc) {
                    insert_arg = argv[insert_arg_num];
                    if (insert_arg == "s") {
                        break;
                    }
                    if (is_number(insert_arg)) {
                        set.insert(stoi(insert_arg));
                    } else {
                        message = "Error: can't insert non digit!";
                        break;
                    }
                } else {
                    break;
                }
            }
            arg_num += (insert_arg_num - arg_num) - 1;
            continue;
        }
        if (arg == "erase") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for erase!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "s") {
                message += "Error: need arguments for erase!";
                break;
            } else if (!is_number(std::string(argv[arg_num + 1]))) {
                message += "Error: can't erase non digit!";
                break;
            } else if (!set.isExit(stoi(std::string(argv[arg_num + 1])))) {
                message += "Notification: element doesn't exist.\n";
                arg_num += 1;
                continue;
            } else {
                set.erase(stoi(std::string(argv[arg_num + 1])));
                arg_num += 1;
                continue;
            }
        }
        if (arg == "exist") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for check!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "s") {
                message += "Error: need arguments for check!";
                break;
            } else if (!is_number(std::string(argv[arg_num + 1]))) {
                message += "Error: can't check non digit!";
                break;
            } else if (!set.isExit(stoi(std::string(argv[arg_num + 1])))) {
                message += "Notification: element doesn't exist.\n";
                arg_num += 1;
                continue;
            } else {
                message += "Notification: element exists.\n";
                arg_num += 1;
                continue;
            }
        }
        if (arg == "&") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for intersect!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "s") {
                message += "Error: need arguments for intersect!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "/") {
                message += "Error: need arguments for intersect!";
                break;
            }
            Set first_set;
            Set second_set;
            bool first_set_filling = true;
            bool non_digit_flag = false;
            int inter_iterator = arg_num + 1;
            std::string inter_arg(argv[inter_iterator]);
            first_set.insert(stoi(inter_arg));
            while (true) {
                inter_iterator += 1;
                if (inter_iterator < argc) {
                    inter_arg = argv[inter_iterator];
                    if (inter_arg == "s") {
                        break;
                    }
                    if (inter_arg == "/") {
                        first_set_filling = false;
                        continue;
                    }
                    if (is_number(inter_arg)) {
                        if (first_set_filling) {
                            first_set.insert(stoi(inter_arg));
                        } else {
                            second_set.insert(stoi(inter_arg));
                        }
                    } else {
                        message = "Error: can't intersect non digit!";
                        non_digit_flag = true;
                        break;
                    }
                } else {
                    break;
                }
            }
            if (non_digit_flag) {
                break;
            }
            Set result;
            if (!first_set.getElems().empty() &&
             !second_set.getElems().empty()) {
                result = first_set & second_set;
            } else {
                message += "Error: sets can't be empty!";
                break;
            }
            std::vector<int> res = result.getElems();
            for (size_t i = 0; i < res.size(); i++) {
             message += " " + std::to_string(res[i]);
            }
            message += '\n';
            continue;
        }
        if (arg == "|") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for union!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "s") {
                message += "Error: need arguments for union!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "/") {
                message += "Error: need arguments for union!";
                break;
            }
            Set first_set;
            Set second_set;
            bool first_set_filling = true;
            bool non_digit_flag = false;
            int inter_iterator = arg_num + 1;
            std::string inter_arg(argv[inter_iterator]);
            first_set.insert(stoi(inter_arg));
            while (true) {
                inter_iterator += 1;
                if (inter_iterator < argc) {
                    inter_arg = argv[inter_iterator];
                    if (inter_arg == "s") {
                        break;
                    }
                    if (inter_arg == "/") {
                        first_set_filling = false;
                        continue;
                    }
                    if (is_number(inter_arg)) {
                        if (first_set_filling) {
                            first_set.insert(stoi(inter_arg));
                        } else {
                            second_set.insert(stoi(inter_arg));
                        }
                    } else {
                        message = "Error: can't union non digit!";
                        non_digit_flag = true;
                        break;
                    }
                } else {
                    break;
                }
            }
            if (non_digit_flag) {
                break;
            }
            Set result;
            if (!first_set.getElems().empty() &&
             !second_set.getElems().empty()) {
                result = first_set | second_set;
            } else {
                message += "Error: sets can't be empty!";
                break;
            }
            std::vector<int> res = result.getElems();
            for (size_t i = 0; i < res.size(); i++) {
             message += " " + std::to_string(res[i]);
            }
            message += '\n';
            continue;
        }
        if (arg == "-") {
            if (arg_num + 1 == argc) {
                message += "Error: need arguments for difference!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "s") {
                message += "Error: need arguments for difference!";
                break;
            } else if (std::string(argv[arg_num + 1]) == "/") {
                message += "Error: need arguments for difference!";
                break;
            }
            Set first_set;
            Set second_set;
            bool first_set_filling = true;
            bool non_digit_flag = false;
            int inter_iterator = arg_num + 1;
            std::string inter_arg(argv[inter_iterator]);
            first_set.insert(stoi(inter_arg));
            while (true) {
                inter_iterator += 1;
                if (inter_iterator < argc) {
                    inter_arg = argv[inter_iterator];
                    if (inter_arg == "s") {
                        break;
                    }
                    if (inter_arg == "/") {
                        first_set_filling = false;
                        continue;
                    }
                    if (is_number(inter_arg)) {
                        if (first_set_filling) {
                            first_set.insert(stoi(inter_arg));
                        } else {
                            second_set.insert(stoi(inter_arg));
                        }
                    } else {
                        message = "Error: can't difference non digit!";
                        non_digit_flag = true;
                        break;
                    }
                } else {
                    break;
                }
            }
            if (non_digit_flag) {
                break;
            }
            Set result;
            if (!first_set.getElems().empty() &&
             !second_set.getElems().empty()) {
                result = first_set - second_set;
            } else {
                message += "Error: sets can't be empty!";
                break;
            }
            std::vector<int> res = result.getElems();
            for (size_t i = 0; i < res.size(); i++) {
             message += " " + std::to_string(res[i]);
            }
            message += '\n';
            continue;
        }
    }
    message += '\n';
    return message;
}

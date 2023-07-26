// Copyright 2023 Prokofev Denis

#include "include/lex.h"

Lex::Lex() {}
Lex::Lex(std::string _s, Type _t, int _val) {
    s = _s;
    t = _t;
    val = _val;
    if (_t == operation && _val != -1) throw "Error";
    if (_t == vall && _val == -1) throw "Error";
}

Type Lex::getType() { return t; }
int Lex::getVal() { return vall; }
std::string Lex::getS() { return s; }

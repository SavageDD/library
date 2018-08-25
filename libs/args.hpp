#pragma once
#include <string>
#include <vector>
typedef unsigned long ptr_t;

enum types : unsigned char {
	tp_int,
	tp_float,
	tp_bool,
	tp_string,
	tp_obj,
};

class Argument
{
	int i_t = 0;
	float f_t = 0;
	bool b_t = 0;
	std::string c_t;
	ptr_t* obj_t = nullptr;
	unsigned char type;

public:
	Argument(bool val) { type = types::tp_bool; b_t = val; }
	Argument(int val) {	type = types::tp_int; i_t = val; }
	Argument(float val) { type = types::tp_float; f_t = val; }
	Argument(std::string val) { type = types::tp_string; c_t = val; }
	Argument(char* val) { type = types::tp_string; c_t = val; }
	Argument(ptr_t* val) { type = types::tp_obj; obj_t = val; }

	std::string Str() { return (type == tp_string) ? c_t : ""; }
	auto Int() { return (type == tp_int) ? i_t : 0; }
	auto Float() { return (type == tp_float) ? f_t : 0.0f; }
	auto Bool() { return (type == tp_bool) ? b_t : false; }
	ptr_t* Obj() { return (type == tp_obj) ? obj_t : nullptr; }
	
	types GetType() { return (types)type; }
	bool IsType(types t) { return type == t; }
};

class Arguments
{
	std::vector<Argument> args;
	Argument nullarg = Argument(0);
	
public:
	Arguments() { }
	auto begin() const { return args.begin(); }
	auto end() const { return args.end(); }
	size_t size() { return args.size(); }
	void clear() { args.clear(); }
	void push(Argument arg) { args.push_back(arg); }
	Argument& operator[](size_t id) { if (id >= args.size()) { return nullarg; } return args[id]; }
};
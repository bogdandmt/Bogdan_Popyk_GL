/**
 * @file	func.h
 * @brief	Prototypes of functions for 6th task
 */

#include<string>
#include<stdio.h>
#include<iostream>

using namespace std;

const char BRACKETS[] = "()[]{}";

/**
 * @brief	The function remove all characters which are not one of BRACKETS
 * @param	[in, out] str Input string
 * @return	void
 */
void Preproc(string &str);

/**
 * @brief	The function checks correctness of brackets
 * @param	[in] str Input string
 * @param	[in] l Left boundary
 * @param	[in] r Right boundary
 * @return	bool Are all brackets in input string in the correct format
 */
bool Check(const string &str, int l, int r);
/*
 * simpleOutPipe.cpp - an application that opens a fifo pipe and writes contents to the pipe.
 * Copyright (C) 2015  Salim Haniff <blog@salimhaniff.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should review the GNU General Public License to accept the agreements to
 * use this program. Available at http://www.gnu.org/licenses/gpl-3.0.html .
 */

#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <random>
#include "helper.h"
using namespace std;

int main(){
	ofstream pipe0; 
	string fifoData;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,15);
	uniform_int_distribution<int> analog_sample(1,1024); 
	char buffer[64];
	int result;

	result = checkFifoPipe();
	if (result == -1){
		/* create pipe */
		cout << "Creating pipe" << endl;
		result = createFifoPipe();
		if (result == -1){
			cout << "Failed to create pipe" << endl;
			exit(-1);
		}
	}

	while(1){
		this_thread::sleep_for(chrono::milliseconds(distribution(generator)*1000));
		pipe0.open(FIFO_PIPE,ofstream::out);
		int rand_num = analog_sample(generator);
		pipe0 << to_string(rand_num);
		pipe0.flush(); 
		pipe0.close();
	}
 return 0;
}


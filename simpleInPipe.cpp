/*
 * simpleInPipe.cpp - an application that opens a fifo pipe and reads the contents
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

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include "helper.h"

using namespace std;

int main(){
	ifstream pipe0; 
	string fifoData;
	int tries = 3;


	while(tries > -1){
		int result;
		result = checkFifoPipe();
		if (result == 0){
			break;
		} else {
			if (tries == 0){
				cout << "Failed to connect to pipe" << endl;
				exit(-1);
			} else {
				tries--;
				cout << "Waiting for pipe to open. Tries left: " << tries << endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
			}
		}
	}	

	while(1){
		pipe0.open(FIFO_PIPE,ios::in);
		getline(pipe0, fifoData);
		cout << fifoData << endl;
		pipe0.close();
	}
	return 0;
}


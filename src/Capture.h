/*
	Copyright (C) 2006 Andrew Gaydenko <a@gaydenko.com>

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/


#ifndef CAPTURE_H
#define CAPTURE_H

#include <QtCore>
#include "WavInfo.h"
#include "JackWrap.h"
#include "QLE.h"

class Capture {
public:
	Capture(QString aDirPath);
	~Capture();
	static QString responseFileName() {
		return QString("response.wav");
	}
	void openJack();
	int getJackRate();
	void closeJack();
	bool jackIsConnected();
	void initBuffers();
	void doJob(int playDbLevel);
	float getMaxResponse();
	QString getWorkDir() {
		return this->dirPath;
	}

private:
	QString dirPath;

	float* playBuf;
	float* capBuf;

	WavInfo* wavInfo;
	JackWrap* jack;
	float maxResponse;

	void freeBuffers();
};

#endif

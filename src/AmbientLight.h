#pragma once

#include <QCoreApplication>
#include <QAmbientLightSensor>

class AmbientLight:public QCoreApplication {
	Q_OBJECT
public:
	AmbientLight(int &argc, char **&argv);
public Q_SLOTS:
	void readingChanged();
protected:
	QAmbientLightSensor _sensor;
};

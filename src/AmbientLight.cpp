#include "AmbientLight.h"
#include <QAmbientLightReading>
#include <QDBusInterface>
#include <QDBusReply>
#include <iostream>

AmbientLight::AmbientLight(int &argc, char **&argv):QCoreApplication(argc, argv),_sensor(this) {
	connect(&_sensor, &QSensor::readingChanged, this, &AmbientLight::readingChanged);
	_sensor.start();
}

void AmbientLight::readingChanged() {
	QDBusInterface intf(QStringLiteral("local.org_kde_powerdevil"),	QStringLiteral("/org/kde/Solid/PowerManagement/Actions/BrightnessControl"), "", QDBusConnection::sessionBus());
	//QDBusReply<int> brightness = intf.call("brightness"); <--- in case we want to adjust relative to current
	QDBusReply<int> maxBrightness = intf.call("brightnessMax");
	int b = maxBrightness;

	switch(_sensor.reading()->lightLevel()) {
	case QAmbientLightReading::Dark:
		b *= 0.2;
		break;
	case QAmbientLightReading::Twilight:
		b *= 0.6;
		break;
	case QAmbientLightReading::Light:
		b *= 0.8;
		break;
	case QAmbientLightReading::Bright:
		b *= 0.9;
		break;
	case QAmbientLightReading::Sunny:
		break;
	case QAmbientLightReading::Undefined:
	default:
		break;
	};
	intf.call("setBrightness", b);
}

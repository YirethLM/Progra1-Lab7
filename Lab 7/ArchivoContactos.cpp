#include "ArchivoContactos.h"
#include <QFile>
#include <QDir>
#include <QByteArray>
#include <QStringList>

QString ArchivoContactos::ruta() const

{
	
	return QDir::homePath() + "/Lab7Datos/contactos.txt";

}

QStringList ArchivoContactos::leer() const
{
	QStringList contactos;
	QFile archivo(ruta());

	if (!archivo.open(QIODevice::ReadOnly))
		return contactos;

	QByteArray datos = archivo.readAll();
	archivo.close();

	QString contenido = QString::fromUtf8(datos);
	QStringList lineas = contenido.split('\n');

	for (const QString& linea : lineas) {
		if (!linea.trimmed().isEmpty())
			contactos.append(linea.trimmed());
	}

	return contactos;
}

	bool ArchivoContactos::guardar(const QString& nombre, const QString& telefono, const QString& correo) const

	{ 

		QString carpeta = QDir::homePath() + "/Lab7Datos";
		if (!QDir().mkpath(carpeta)) 
			return false;

		QFile archivo(ruta());
		if (!archivo.open(QIODevice::WriteOnly | QIODevice::Append))
			return false;

		QString linea = nombre + ";" + telefono + ";" + correo + "\n";
		QByteArray datos = linea.toUtf8();
		bool completo = archivo.write(datos) == datos.size();
		bool vaciado = archivo.flush();
		archivo.close();
		return completo && vaciado;

}
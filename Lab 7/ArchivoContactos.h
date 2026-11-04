#pragma once
#include <QString>
#include <QStringList>

class ArchivoContactos
{
public:
	QString ruta() const;
	bool guardar(const QString& nombre, const QString& telefono, const QString& correo) const;
	QStringList leer() const;
}; 
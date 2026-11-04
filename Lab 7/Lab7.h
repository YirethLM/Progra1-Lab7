#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab7.h"
#include "ArchivoContactos.h"

class Lab7 : public QMainWindow
{
    Q_OBJECT

public:
    Lab7(QWidget *parent = nullptr);
    ~Lab7();

private:
    Ui::Lab7Class ui;
    ArchivoContactos archivoContactos;
    bool editando = false;
    int filaEditar = -1;
    QString contactoEditar;
	void guardarContacto();
    void mostrarRegistrar();
    void mostrarHistorial();
    void configurarTabla();
    void editarContacto();
    void eliminarContacto();
};


#include "Lab7.h"
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QStringList>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QList>
#include <QStringList>
#include <QHeaderView>

Lab7::Lab7(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    configurarTabla();
    connect(ui.btnGuardar, &QPushButton::clicked, this, &Lab7::guardarContacto);
    connect(ui.actionRegistrar, &QAction::triggered, this, &Lab7::mostrarRegistrar);
    connect(ui.actionHistorial, &QAction::triggered, this, &Lab7::mostrarHistorial);
}

Lab7::~Lab7()
{
}

void Lab7::guardarContacto()
{
    QString nombre = ui.txtNombre->text().trimmed();
    QString telefono = ui.txtTelefono->text().trimmed();
    QString correo = ui.txtCorreo->text().trimmed();

    if (nombre.isEmpty() || telefono.isEmpty() || correo.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor, complete todos los campos, son tres por si acaso.");
        return;
    }

    for (const QString& dato : QStringList{ nombre, telefono, correo }) {
        if (dato.contains(';') || dato.contains('\n') || dato.contains('\r')) {
            QMessageBox::warning(this, "Esta mal", "Los datos no pueden tener ';' ni saltos de línea.");
            return;
        }
    }

    if (!archivoContactos.guardar(nombre, telefono, correo)) {
        QMessageBox::critical(this, "No se pudo guardar", "Revisa permisos y espacios disponibles.\nArchivo: " + archivoContactos.ruta());
        return;
    }

    ui.txtNombre->clear();
    ui.txtTelefono->clear();
    ui.txtCorreo->clear();
    QMessageBox::information(this, "Guardado completo", "El contacto se guardó correctamente.\nArchivo: " + archivoContactos.ruta());
    ui.txtNombre->setFocus();
}

void Lab7::mostrarRegistrar()
{
    ui.stackedWidget->setCurrentWidget(ui.pageRegistrar);
}

void Lab7::configurarTabla()
{
    ui.tablaContactos->setColumnCount(3);
    ui.tablaContactos->setHorizontalHeaderLabels(QStringList() << "Nombre" << "Teléfono" << "Correo");
    ui.tablaContactos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui.tablaContactos->setSelectionMode(QAbstractItemView::SingleSelection);
    ui.tablaContactos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tablaContactos->setSortingEnabled(false);
    ui.tablaContactos->horizontalHeader()->setStretchLastSection(true);
}

void Lab7::mostrarHistorial()
{
    ui.tablaContactos->setRowCount(0);

    QStringList lineas = archivoContactos.leer();

    for (const QString& linea : lineas)
    {
        QString limpia = linea.trimmed();
        if (limpia.isEmpty())
        {
            continue;
        }

        QStringList partes = limpia.split(';');
        if (partes.size() != 3)
        {
            continue;
        }

        int fila = ui.tablaContactos->rowCount();
        ui.tablaContactos->insertRow(fila);

        ui.tablaContactos->setItem(fila, 0, new QTableWidgetItem(partes.at(0)));
        ui.tablaContactos->setItem(fila, 1, new QTableWidgetItem(partes.at(1)));
        ui.tablaContactos->setItem(fila, 2, new QTableWidgetItem(partes.at(2)));
    }

    ui.stackedWidget->setCurrentWidget(ui.pageHistorial);
}
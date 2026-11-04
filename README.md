# Laboratorio 7 – Agenda de contactos (Qt Widgets, C++)

Agenda de contactos hecha con Qt Widgets en Visual Studio. Permite registrar, ver, editar y eliminar contactos.

## Dónde se guardan los datos

Los contactos se guardan en:

`C:/Users/YirethLM/Lab7Datos/contactos.txt`

Cada contacto es una línea con este formato: `nombre;telefono;correo`

En este repositorio hay un `contactos.txt` de ejemplo con datos de prueba (no son datos reales).

## Cómo usar el programa

- **Navegación > Registrar:** formulario para guardar un contacto nuevo. Valida que los tres campos no estén vacíos y que no tengan `;` ni saltos de línea. Muestra un mensaje de confirmación.
- **Navegación > Historial:** tabla con todos los contactos. Si el archivo no existe o está vacío, la tabla se muestra vacía.
- **Navegación > Editar:** modifica el contacto seleccionado en la tabla.
- **Navegación > Eliminar:** borra el contacto seleccionado, con confirmación.

Si no hay una fila seleccionada, Editar y Eliminar avisan con un mensaje y no cambian nada.

## Cómo comprobé Editar y Eliminar

1. Creé 3 contactos de prueba y los vi en el Historial.
2. Edité el teléfono del 2.º contacto. Cambió solo ese registro, en la tabla y en el archivo.
3. Eliminé el 3.º contacto y confirmé la eliminación.
4. Cerré la aplicación y la volví a abrir. Quedaron 2 contactos y el 2.º tenía el teléfono nuevo.
5. Probé cancelar una eliminación: no cambió nada.
6. Probé Editar y Eliminar sin seleccionar fila: salió el aviso y no se modificó ningún contacto.
7. Probé el Historial con el archivo ausente: la tabla se mostró vacía y el programa no se cerró.

Los registros se identifican por su posición (fila) y no por el nombre, porque los nombres se pueden repetir. Para editar y eliminar, el archivo se reescribe completo con `QSaveFile`.

## Capturas

Las capturas (guardado con confirmación e historial final) están en el archivo `Evidencia Imágenes.docx`.

# StoreClothing
Repositorio de Sistema de Gestión de una tienda de ropa correspondiente al segundo Parcial de Laboratorio 2 UTN - FRGP 

Descripción:
El sistema de gestión de tienda de ropa “CLOTHING STORE”, cuenta con 6 archivos (proveedores.dat, productos.dat, vendedores.dat, clientes.dat, ventas.dat, detalleventa.dat), los mismos que según haga falta podrán ser modificados(cargar uno nuevo, eliminar registro), y 7 clases (class venta, class fecha, class producto, class proveedor, class vendedor, class cliente, class detalleventa) que contarán con sus respectivos métodos: setters, getters, cargar(), mostrar() ,grabarEnDisco() y leerDeDisco(), para así dotar de funcionalidad al sistema.

Este sistema consideró las siguientes características de una tienda de ropas: 
El vendedor: debe contar con un código de acceso para evitar manipulación indebida de la información, el mismo que deberá ingresar cada vez que quiera hacer una venta.
Ropa: Cada prenda disponible en la tienda cuenta con un etiquetado que muestra tanto el código de proveedor, como el código de ropa. Información que al realizar una venta deberá ser ingresada correctamente, pues de lo contrario el sistema no reconocerá la existencia del producto, haciendo imposible la realización de la misma.

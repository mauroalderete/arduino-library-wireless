# Wireless

Simple implementacion y utilidades para las librerias estandar de WiFi arduino y esp

## Instalación

Utilizando la consola de tu preferencia, dirigete a la ruta de las librerias de arduino de tu instalacion. Por ejemplo:

``` bash
cd P:\Arduino\libraries
```

Una vez dentro del directorio solo basta con clonar el proyecto de la libreria en la versión que gustes.

``` bash
git clone git@gitlab.com:arduinolibraries/Wireless.git .
```

Esto creara el directorio Wireless de la libreria junto con los archivos de documentación y los ejemplos.

## Seleccion de versión

Por defecto, luego de instalar desde el repositorio, la versión seleccionada es la última vigente en master. Si quiere puede seleccionar otra version en cualquier momento utilizando los comandos git checkout y haciendo referencia a la versión que desee.

``` bash
git checkout tag/<versión>
```

Puede ver un listado de las versiones disponibles por medio del siguiente comando

``` bash
git fetch --tags
```

## Actualización

Para actualizar a la última versión solo es necesario ejecutar un simple pull

``` bash
git pull
```

Luego podra seleccionar la última versión siguiendo los pasos de Selección de versión

## Uso

La libreria incluye una instancia de Wireless ya declarada. No es necesario realizar ninguna instancia nueva. Pero puede ser util aprovechar los constructores para configurar rapidamente el comportamiento de Wireless.

``` c++
Wireless = WirelessClass( <router>, <password>, <hostname>, <timeout> );
```

De otra forma se pueden utilizar los metodos setters correspondientes para cargar los valores.

Al mismo tiempo WirelessClass ofrece una serie de callbacks que se van ejecutando dependiendo del estados de la conección. Lo que permite ejecutar codigo diferente entre cada cambio de estado.

Por ejemplo es posible emitir un mensaje de conexión perdida una unica vez realizando una subcripción al metodo ``` OnLostConnection() ```

``` c++
Wireless.OnLostConnection([](){
    Serial.println("Connection Lost!")
});
```

Para iniciar el ciclo de ejecucion de WirelessClass se debe realizar una llamada al metodo Begin()

``` c++
Wireless.Begin();
```

Es obligatorio que se realice una llamada al metodo **Loop()** dentro del bucle infinito del procesador para que Wireless sea capaz de verificar y ejecutar los callbacks correspondientes.

``` c++
void loop(){
    Wireless.Loop();
}
```

## Links

- [Cambios de version](CHANGELOG.md)
- [Repositorio](https://gitlab.com/arduinolibraries/Wireless/-/tree/master)
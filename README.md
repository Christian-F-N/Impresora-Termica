# Proyecto de Impresora Térmica Personalizada con Arduino

Este proyecto consiste en el diseño y construcción de una solución de impresión de etiquetas y tickets utilizando Arduino y una impresora térmica TTL RS232 CSN-A2, junto con un teclado y dos pulsadores.

## Requisitos de Hardware

- Arduino Uno o compatible.
- Impresora térmica TTL RS232 CSN-A2.
- Teclado matricial.
- Dos pulsadores.
- Fuente de alimentación adecuada para la impresora y el Arduino.
- Cables de conexión.

## Requisitos de Software

- Arduino IDE.
- Librerías específicas para la impresora térmica, como Adafruit Thermal Printer Library o similar.

## Diagrama de Conexiones

A continuación se muestra el diagrama de conexiones entre el Arduino, la impresora térmica, el teclado y los pulsadores:

                   +-----------------+
                   | Impresora Térmica|
                   |   TTL RS232     |
                   |    CSN-A2       |
                   +-----------------+
                            |
                            |
        +-----------------------------------+
        |              Arduino              |
        +-----------------------------------+
        |                                   |
        |    +-------------------------+    |
        |    |       Teclado           |    |
        |    +-------------------------+    |
        |    |   +-----+  +-----+      |    |
        |    |   |Btn1 |  |Btn2 |      |    |
        |    |   +-----+  +-----+      |    |
        |    +-------------------------+    |
        |                                   |
        +-----------------------------------+

## Pasos de Implementación

1. **Configuración del hardware**: Conecta la impresora térmica, el teclado y los pulsadores a las salidas correspondientes en el Arduino según el diagrama de conexiones. Asegúrate de utilizar los niveles de voltaje adecuados y las resistencias de pull-up o pull-down necesarias.

2. **Instalación de las librerías**: Abre el Arduino IDE y asegúrate de tener instaladas las librerías específicas para la impresora térmica que estás utilizando, como la Adafruit Thermal Printer Library. Si es necesario, sigue las instrucciones de instalación proporcionadas por el fabricante de la impresora térmica.

3. **Desarrollo del código**: Escribe el código en el Arduino IDE para controlar la impresora térmica, leer las entradas del teclado y los pulsadores, y enviar los comandos de impresión correspondientes. Puedes utilizar las librerías mencionadas anteriormente para facilitar la comunicación con la impresora.

4. **Pruebas y ajustes**: Realiza pruebas exhaustivas del sistema de impresión de etiquetas y tickets. Verifica que los comandos de impresión sean enviados correctamente y que los datos se impriman de acuerdo a tus requisitos. Realiza ajustes en el código y la configuración si es necesario.

5. **Construcción del sistema**: Diseña y construye una carcasa o estructura para alojar el Arduino, la impresora térmica, el teclado y los pulsadores de acuerdo a tus necesidades. Asegúrate de proporcionar un acceso adecuado para la carga de papel y el mantenimiento de la impresora.

## Contribuciones

Si deseas contribuir a este proyecto, siéntete libre de hacer fork del repositorio y enviar pull requests con tus mejoras.

## Licencia

Este proyecto se distribuye bajo la Licencia MIT. Consulta el archivo [LICENSE](./LICENSE) para obtener más detalles.

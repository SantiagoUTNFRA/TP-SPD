# TP-SPD

# Integrantes
* Santiago Felipe Cantos
* Fiorella Marina Aguayo

# Primera Parte
![Primera parte](https://github.com/SantiagoUTNFRA/TP-SPD/blob/main/images/circuito%20parte%201.png)
# Descripción
Este proyecto de Arduino se centra en la creación de un contador digital que utiliza un display de 7 segmentos para mostrar números de 0 a 99. El contador se puede controlar mediante tres botones: "RESET", "AUMENTA" y "DISMINUYE". A continuación el funcionamiento:

- Componentes: 
    * Dos displays de 7 segmentos.
    * Tres pulsadores: RESET, AUMENTA y DISMINUYE.
    * Arduino.
    * Cables y resistencias.

- Botones de Control: 
    * RESET: Si se presiona el botón "RESET," el contador se restablece a 0.
    * AUMENTA: Al presionar el botón "AUMENTA," el contador aumenta en 1.
    * DISMINUYE: Al presionar el botón "DISMINUYE," el contador disminuye en 1.

- Rango del Contador: El contador se asegura de permanecer en el rango de 0 a 99. Cuando se alcanza pasa el valor máximo (99) el contador vuelve a 0. Por el contrario, si el contador sobrepasa el mínimo valor (0) se establece en 99.

- Visualización: El número actual en el contador se muestra en el display. El dígito de las decenas se muestra primero y, después de un breve retraso, se muestra el dígito de las unidades, cumpliendose así la multiplexación. 

Link al proyecto: https://www.tinkercad.com/things/hvoB1uoDoom

# Segunda Parte
![Segunda parte](https://github.com/SantiagoUTNFRA/TP-SPD/blob/main/images/circuito%20parte%202.png)
# Descripción
En esta segunda parte se ha agregado una funcionalidad que permite dos modos de eventos mediante un interruptor. Los dos botones: "AUMENTA" y "DISMINUYE", se utilizan para controlar el contador en ambos modos.

- Componentes: 
    * Dos displays de 7 segmentos.
    * Dos pulsadores: AUMENTA y DISMINUYE.
    * Arduino.
    * Cables y resistencias.
        - Nuevo:
            * Un interruptor deslizante.
            * Un sensor de temperatura.

- Incorporación de interruptor deslizante:
Permite dos modos de funcionamiento. Cuando el interruptor está en la posición "0", el contador operará de forma común (1 en 1), y cuando está en la posición "1", el contador operará de forma distinta (números primos).

- Incorporación de Sensor de temperatura:
Lectura de Temperatura: El sensor de temperatura se utiliza para medir la temperatura ambiente. Se mostrará en el monitor serial.

Link al proyecto: https://www.tinkercad.com/things/dey6lBWNwzw


# Integración de Motor de CC
![Motor CC](https://github.com/SantiagoUTNFRA/TP-SPD/blob/main/images/circuito%20con%20motor%20cc.png)
# Descripción
El motor de CC se integra en el proyecto para indicar visualmente si se está en el modo de números o en el modo de números primos, dependiendo de la posición del interruptor. Cuando el interruptor se encuentra en el lado de números, el motor se detiene, y cuando está en el lado de números primos, el motor gira.
# Pruebas con Allegro en C 🎮

Este repositorio contiene una serie de ejercicios y pruebas realizadas con la biblioteca [Allegro](https://liballeg.org/) en el lenguaje de programación **C**. La intención principal es explorar los componentes fundamentales de Allegro, como la creación de ventanas, entrada por teclado, gráficos, animaciones, sonido y más.

## 📁 Estructura del repositorio

```bash
.
├── 01_ventana_basica/
├── 02_entrada_teclado/
├── 03_dibujar_formas/
├── 04_manejo_eventos/
├── 05_animacion_sprites/
├── 06_audio/
├── 07_proyecto_completo/
├── README.md
Descripción de carpetas
01_ventana_basica/
Crea una ventana básica con Allegro, útil como punto de partida para cualquier aplicación.

02_entrada_teclado/
Captura y procesa la entrada del usuario mediante teclado.

03_dibujar_formas/
Dibuja formas geométricas simples en pantalla: rectángulos, círculos, líneas, etc.

04_manejo_eventos/
Muestra cómo funciona el sistema de eventos en Allegro, incluyendo cierres y pulsaciones de teclas.

05_animacion_sprites/
Carga y anima sprites usando temporizadores de Allegro.

06_audio/
Reproduce archivos de sonido, tanto música de fondo como efectos.

07_proyecto_completo/
Combina los elementos anteriores en una pequeña demo interactiva o juego básico.

🛠️ Requisitos
Para compilar y ejecutar los ejemplos necesitas:

Un compilador de C (como GCC).

La biblioteca Allegro 5 instalada.

En sistemas basados en Debian (como Ubuntu) puedes instalar Allegro con:

bash
Copiar
Editar
sudo apt-get install liballegro5-dev
▶️ Compilación y ejecución
Cada carpeta contiene un archivo main.c (o similar) que puedes compilar así:

bash
Copiar
Editar
gcc main.c -o programa -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_audio -lallegro_acodec -lallegro_primitives
./programa
Nota: Asegúrate de estar en la carpeta correspondiente antes de compilar.

📚 Referencias
Documentación oficial de Allegro

Allegro Wiki (archivada)

Tutoriales en GitHub y YouTube

✍️ Autor
Este repositorio fue creado como una práctica personal por Alejandro para fortalecer sus habilidades con C y desarrollo de videojuegos.
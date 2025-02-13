# 🖼️ SVIM - Sistema de Visualización de Imágenes Médicas  

SVIM es un software desarrollado en **C++ con Qt y OpenGL** para la **carga, visualización y procesamiento de imágenes médicas** en formato **MIF (Medical Image Format)**.  

## 🚀 Características principales  
✅ **Carga y guardado** de imágenes en formato `.mif`.  
✅ **Visualización gráfica** utilizando OpenGL.  
✅ **Procesamiento de imágenes**, como filtros de color y detección de estructuras.  
✅ **Gestión de metadatos** asociados a las imágenes.  
✅ **Interfaz de usuario combinada**: consola y ventana gráfica.  


## 📌 Conceptos aplicados  
Durante el desarrollo de este proyecto, se pusieron en práctica diversos conceptos clave de programación y desarrollo de software, entre ellos:  

### 🔹 Diseño y programación orientada a objetos  
- Aplicación de principios de **OOP** para estructurar el sistema.  

### 🔹 Herramientas de programación  
- **Sobrecarga de operadores** para manipulación de datos.  
- **Herencia y polimorfismo** para una arquitectura modular.  
- **Recursividad** en el procesamiento de imágenes.  

### 🔹 Uso de la biblioteca de templates STL  
- **Clases contenedoras** para organizar datos.  
- **Iteradores y algoritmos** para manipulación eficiente de estructuras.  

### 🔹 Desarrollo de software gráfico  
- **Uso de APIs para graficación** con OpenGL y Qt.  
- **Manejo de coordenadas homogéneas** para transformaciones de imagen.  

### 🔹 Interfaces gráficas con Qt  
- **Creación de formularios** y componentes gráficos.  
- **Manejo de eventos** para interacción con el usuario.  
- **Gestión de propiedades y distribución de controles**.  

### 🔹 Trabajo en equipo en un proyecto de tamaño medio  
- Organización modular del código para facilitar la colaboración.  


## 📑 Formato de archivo `.mif`  
Los archivos `.mif` contienen:  
1️⃣ **Cabecera** con dimensiones de la imagen y metadatos (ej. nombre del paciente, fecha, tipo de estudio).  
2️⃣ **Datos binarios** con los píxeles en formato RGB de 16 bits.  

📌 **Ejemplo de cabecera `.mif`**


        210;300;42.2;60.3;mm
        fecha:2015/07/04;nombre:Bruce Willis;equipo:T1000;tipo:XRay

🔹 La imagen tiene **210x300 píxeles** y mide **42.2x60.3 mm**.  
🔹 El paciente es **Bruce Willis**, el estudio es de **Rayos-X** y el equipo utilizado es **T1000**.
## 📥 Ubicación de las imágenes  
Para que el software pueda encontrar correctamente las imágenes **`.mif`**, debes colocarlas en la carpeta **`build/Desktop_Qt_*-Debug`**, que debe estar en la misma ubicación que el ejecutable.  


## 🏗 Cómo Compilar y Ejecutar  
### 🔹 Opción 1: Usando Qt Creator  
1. Abre **Qt Creator**.  
2. Carga el archivo `SVIM.pro`.  
3. Selecciona el kit de compilación adecuado (**MinGW o MSVC**).  
4. Compila y ejecuta el proyecto.  

### 🔹 Opción 2: Usando CMake y la Terminal  
Si usas **CMake**, ejecuta en la terminal:


    mkdir build
    cd build
    cmake ..
    make
    ./SVIM`

## 🚀 Próximas Actualizaciones  
Este proyecto continuará evolucionando con nuevas versiones donde iré implementando los distintos **desafíos propuestos por la cátedra**. Algunas de las mejoras y funcionalidades que planeo agregar incluyen:  

✅ Mejoras en la visualización con OpenGL.  
✅ Implementación de nuevos algoritmos de procesamiento de imágenes.  
✅ Soporte para otros formatos además de `.mif`.  
✅ Optimización del rendimiento y corrección de errores.  

¡Si tienes sugerencias o ideas, estaré encantado de escucharlas! 🎯  
##📜 Licencia
Este proyecto se distribuye bajo la Licencia MIT.

##👨‍💻 Autor
Cortez Matias – Estudiante de UADER

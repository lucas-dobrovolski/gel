
# Guía de funcionamiento general y cosas por hacer

---

2 partes separadas: **Engine** y **Sandbox**

### Engine:
**Application.h** declara la clase Application y la función "*CreateApplication()*",  que devuelve un "*Aplicattion\** ". (Se define en cliente, osea SandboxApp.cpp).
**Application.cpp** define "*run()*", tiene el while principal.
**EntryPoint.h** define el main, en donde se crea "*app = GEL::CreateApplication()*"
**Utils.h** define utilidades generales: LOG.

**gel.h** es el archivo que importa a todos los demás.

### Sandbox:
**SandboxApp.cpp** define la clase Sandbox, que hereda Application, así define "*CreateApplication()*" para que devuelva "*new Sandbox()* "

---

### Flow del programa: 
**1. Entrypoint.h ➡ main() ➡ auto app = GEL::CreateApplication()**
**2.** app es un Sandbox**
**3. app->run()**, definida en Application.cpp **➡ while(True)**

---
#### extras
<span style="color:red">texto rojo</span>

<span style="color:blue">texto blue</span>

<span style="color:green">texto green</span>

<span style="color:pink">texto pink</span>

<span style="color:purple">texto purple</span>

<span style="color:yellow">texto yellow</span>


==Texto resaltado==

```python
def saludo():
    print("Hola mundo")
```


> Esto es una nota informativa.

[Wikipedia](https://es.wikipedia.org)

<details>
<summary>Ver cómo compilar</summary>
```bash
mkdir build
cd build
cmake ..
make
</details> 


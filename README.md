R4adit-Meteo - Software para radiodifusión.
=============================================

![Meteo-1](https://raw.githubusercontent.com/jfperini/meteo/master/screenshots/meteo-header.jpg "Meteo-1")

#### Meteo es un proyecto de software libre para radiodifusión.

    Meteo es una utilidad que recopila datos meteorológicos.

## Instalar

    En ArchLinux:

    [user@archlinux:~] yaourt -S meteo
    
Se necesitan algunos permisos. Ejecutar el [script](https://github.com/jfperini/radit/blob/master/radit.sh):

    [user@archlinux:~] sh ~/Descargas/radit.sh
    
    [user@archlinux:~] meteo

## Compilar

    cd src

    qmake-qt4 meteo.pro

    make

El binario generado se encuntra en la carpeta LinuxDesktop.

![Meteo-2](https://raw.githubusercontent.com/jfperini/meteo/master/screenshots/meteo-footer.jpg "Meteo-2")

Página oficial: http://www.radit.org/net



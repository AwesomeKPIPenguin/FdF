
# FdF

Available only for **MacOSX**

The goal of the FdF is to draw a wireframe of a 3D landscape.

## Instalation and Usage

Run make

```
make
```

Executable named **fdf** will appear. It takes a map file as a parametr.

Map is represented as a rectangle block of numbers:

```
cat 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Each number corresponds to a point in space:

* The horizontal position corresponds to its **axis**.
* The vertical position corresponds to its **ordinate**.
* The value corresponds to its **altitude**.

Also, a **colour** can be specified as a parametr, so one point in the map would have next format:

**altitude_number,colour_in_hex** (the '0x' prefix is supported and case does not matter)

Example:

```
1,0xff 15,ffc 6,0xFF
```

Colour is represented by an **int** value by the next rule:

**0x00RRGGBB**

Next manipulations of the created map are available:

* Moving
* Rotating
* Scaling

To see manipulation settings run 

```
./fdf info
```

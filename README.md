# nu2debug
A mod to enable debug menus in nu2 (TT's engine) games. Currently only works for LEGO® Star Wars: The Complete Saga. This mod is meant to be used an example of how to make a mod for nu2 games using [mod_loader](https://github.com/lcdr/mod_loader).

# Features
Currently, nu2debug is able to toggle on an fps counter, a position display and a level loading display.

# Installation
To install the mod, you will need [mod_loader](https://github.com/lcdr/mod_loader). Go to the releases page and download the latest `dinput8.dll`. Once you've downloaded it, put it in the same folder as your nu2 game executable (Example: `LEGOStarWarsSaga.exe`). After this, create a `mods` folder in the same folder you put `dinput.dll` into, and download the latest `mod.dll` from the nu2debug releases page. Once you've done this, place the `mod.dll` into a folder named `nu2debug` within your `mods` folder. Then, just run your game.

# Usage
To keep this mod as simple and to the point as possible, the keys for the different debug options are hardcoded, feel free to fork this and make a version with a config. The keys are `F3` to toggle the FPS counter, `F4` to toggle the position display and `F5` to toggle the level loading display.
